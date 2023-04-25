// Shoot Them Up. Project from Udemy course

#include "Components/STUWeaponComponent.h"
#include "Animation/STUEquipAnimNotify.h"
#include "Animation/STUReloadFinishAnimNotify.h"
#include "GameFramework/Character.h"
#include "Player/STUBaseCharacter.h"
#include "STUBaseWeaponActor.h"

DEFINE_LOG_CATEGORY_STATIC(WeaponComponentLog, All, All)

// Sets default values for this component's properties
USTUWeaponComponent::USTUWeaponComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these
    // features off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void USTUWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    SpawnWeapons();

    CurrentWeaponIndex = 0;
    EquipWeapon(CurrentWeaponIndex);
    InitAnimation();
}

void USTUWeaponComponent::SpawnWeapons()
{
    ACharacter *OwnerCharacter = Cast<ACharacter>(GetOwner());

    for (auto OneWeapon : WeaponComponent)
    {
        CurrentWeapon = GetWorld()->SpawnActor<ASTUBaseWeaponActor>(OneWeapon.WeaponClass);
        CurrentWeapon->SetOwner(OwnerCharacter);
        Weapons.Add(CurrentWeapon);
        CurrentWeapon->OnClipEmpty.AddUObject(this, &USTUWeaponComponent::OnEmptyClip);
        AttachWeaponToSoket(CurrentWeapon, OwnerCharacter->GetMesh(), WeaponArmorySoket);
    }
}
void USTUWeaponComponent::AttachWeaponToSoket(ASTUBaseWeaponActor *Weapon, USceneComponent *SceneComponent,
                                              FName SoketName)
{
    FAttachmentTransformRules AttachmentRules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
    Weapon->AttachToComponent(SceneComponent, AttachmentRules, SoketName);
}

void USTUWeaponComponent::EquipWeapon(int32 WeaponIndex)
{
    if (WeaponIndex < 0 && WeaponIndex > WeaponComponent.Num())
    {
        UE_LOG(WeaponComponentLog, Warning, TEXT("Invalid Weapon Index"));
        return;
    }
    WeaponChangeInProgress = true;
    ACharacter *OwnerCharacter = Cast<ACharacter>(GetOwner());
    if (CurrentWeapon)
    {
        CurrentWeapon->EndFire();
        AttachWeaponToSoket(CurrentWeapon, OwnerCharacter->GetMesh(), WeaponArmorySoket);
    }

    CurrentWeapon = Weapons[WeaponIndex];
    CurrentReloadAnimMontage = WeaponComponent[WeaponIndex].ReloadMontage;
    AttachWeaponToSoket(CurrentWeapon, OwnerCharacter->GetMesh(), WeaponEquipSoket);
    LaunchAnimMontage(EquipAnimMontage);
}

void USTUWeaponComponent::LaunchAnimMontage(UAnimMontage *AnimMontage)
{
    ACharacter *OwnerCharacter = Cast<ACharacter>(GetOwner());
    OwnerCharacter->PlayAnimMontage(AnimMontage);
}

void USTUWeaponComponent::InitAnimation()
{

    USTUEquipAnimNotify *EquipNotifyFinish = FindNotifyByClass<USTUEquipAnimNotify>(EquipAnimMontage);
    if (EquipNotifyFinish)
    {
        EquipNotifyFinish->OnNotified.AddUObject(this, &USTUWeaponComponent::OnEquipFinished);
    }

    for (FWeaponData OneWeaponComponent : WeaponComponent)
    {
        USTUReloadFinishAnimNotify *ReloadNotifyFinish =
            FindNotifyByClass<USTUReloadFinishAnimNotify>(OneWeaponComponent.ReloadMontage);
        if (!ReloadNotifyFinish)
            continue;
        ReloadNotifyFinish->OnNotified.AddUObject(this, &USTUWeaponComponent::OnReloadFinished);
    }
}

void USTUWeaponComponent::OnEquipFinished(USkeletalMeshComponent *MeshComponent)
{
    auto Character = Cast<ASTUBaseCharacter>(GetOwner());
    if (Character && Character->GetMesh() == MeshComponent)
        WeaponChangeInProgress = false;
}

void USTUWeaponComponent::OnReloadFinished(USkeletalMeshComponent *MeshComponent)
{
    auto Character = Cast<ASTUBaseCharacter>(GetOwner());
    if (Character && Character->GetMesh() == MeshComponent)
        WeaponReloadInProgress = false;
}

bool USTUWeaponComponent::CanFire() const
{
    return (CurrentWeapon && !WeaponChangeInProgress && !WeaponReloadInProgress);
}

bool USTUWeaponComponent::CanEquip() const
{
    return !WeaponChangeInProgress && !WeaponReloadInProgress;
}

bool USTUWeaponComponent::CanReload() const
{
    return (CurrentWeapon              //
            && !WeaponChangeInProgress //
            && !WeaponReloadInProgress //
            && CurrentWeapon->CanReload());
}

void USTUWeaponComponent::OnEmptyClip()
{
    ChangeClip();
}

void USTUWeaponComponent::ChangeClip()
{
    if (!CanReload())
        return;
    CurrentWeapon->EndFire();
    CurrentWeapon->ChangeClip();
    WeaponReloadInProgress = true;
    LaunchAnimMontage(CurrentReloadAnimMontage);
}

void USTUWeaponComponent::Reload()
{
    ChangeClip();
}

void USTUWeaponComponent::NextWeapon()
{
    if (CanEquip())
    {
        CurrentWeaponIndex = (CurrentWeaponIndex + 1) % Weapons.Num();
        EquipWeapon(CurrentWeaponIndex);
    }
}

void USTUWeaponComponent::StartFire()
{
    if (CanFire())
        CurrentWeapon->StartFire();
}

void USTUWeaponComponent::EndFire()
{
    CurrentWeapon->EndFire();
}

void USTUWeaponComponent::DestuctWeapon()
{
    CurrentWeapon->EndFire();
    CurrentWeapon = nullptr;
    for (auto Weapon : Weapons)
    {
        Weapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
        Weapon->Destroy();
    }
    Weapons.Empty();
}
