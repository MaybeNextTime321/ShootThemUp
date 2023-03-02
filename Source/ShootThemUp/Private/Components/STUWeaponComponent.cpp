// Shoot Them Up. Project from Udemy course

#include "Components/STUWeaponComponent.h"
#include "GameFramework/Character.h"
#include "Player/STUBaseCharacter.h"
#include "STUBaseWeaponActor.h"

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
}

void USTUWeaponComponent::SpawnWeapons()
{
    ACharacter *OwnerCharacter = Cast<ACharacter>(GetOwner());

    for (auto Weapon : WeaponClass)
    {
        CurrentWeapon = GetWorld()->SpawnActor<ASTUBaseWeaponActor>(Weapon);
        CurrentWeapon->SetOwner(OwnerCharacter);
        Weapons.Add(CurrentWeapon);

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
    ACharacter *OwnerCharacter = Cast<ACharacter>(GetOwner());
    if (CurrentWeapon)
    {
        CurrentWeapon->EndFire();
        AttachWeaponToSoket(CurrentWeapon, OwnerCharacter->GetMesh(), WeaponArmorySoket);
    }

    CurrentWeapon = Weapons[WeaponIndex];
    AttachWeaponToSoket(CurrentWeapon, OwnerCharacter->GetMesh(), WeaponEquipSoket);
}

void USTUWeaponComponent::NextWeapon()
{
    CurrentWeaponIndex = (CurrentWeaponIndex + 1) % Weapons.Num();
    EquipWeapon(CurrentWeaponIndex);
}

void USTUWeaponComponent::StartFire()
{
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
