// Shoot Them Up. Project from Udemy course


#include "Pickup/STUAmmoPickup.h"
#include "Components/STUWeaponComponent.h"
#include "Components/STUHealthComponent.h"
#include "STUBaseWeaponActor.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(AmmoPickupLog, All, All);

bool ASTUAmmoPickup::GivePickupTo(APawn *PlayerPawn)
{
    USTUHealthComponent *HealthComponent = STUUtils::GetPlayerComponent<USTUHealthComponent>(PlayerPawn);


    if (!HealthComponent && HealthComponent->IsDead())
    {
        return false;
    }

    USTUWeaponComponent *WeaponComponent = STUUtils::GetPlayerComponent<USTUWeaponComponent>(PlayerPawn);
    
    if (!WeaponComponent)
    {
        return false;
    }

    return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
    
}
