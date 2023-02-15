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

    SpawnWeapon();
}

void USTUWeaponComponent::SpawnWeapon()
{
    ACharacter *OwnerCharacter = Cast<ACharacter>(GetOwner());
    CurrentWeapon = GetWorld()->SpawnActor<ASTUBaseWeaponActor>(WeaponClass);
    FAttachmentTransformRules AttachmentRules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
    CurrentWeapon->AttachToComponent(OwnerCharacter->GetMesh(), AttachmentRules, WeaponSoket);
    CurrentWeapon->SetOwner(OwnerCharacter);
}

void USTUWeaponComponent::Fire()
{
    CurrentWeapon->Fire();
}

void USTUWeaponComponent::DestuctWeapon()
{
    CurrentWeapon->DestructWeapon();
}
