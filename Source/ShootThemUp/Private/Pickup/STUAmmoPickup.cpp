// Shoot Them Up. Project from Udemy course


#include "Pickup/STUAmmoPickup.h"
#include "Components/STUWeaponComponent.h"
#include "Components/STUHealthComponent.h"
#include "STUBaseWeaponActor.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(AmmoPickupLog, All, All);

bool ASTUAmmoPickup::GivePickupTo(APawn *PlayerPawn)
{
    USTUHealthComponent *HealthComponent = PlayerPawn->GetComponentByClass<USTUHealthComponent>();

    if (!HealthComponent && HealthComponent->IsDead())
    {
        return false;
    }

    USTUWeaponComponent *WeaponComponent = PlayerPawn->GetComponentByClass<USTUWeaponComponent>();
    
    if (!WeaponComponent)
    {
        return false;
    }

    return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
    
}
