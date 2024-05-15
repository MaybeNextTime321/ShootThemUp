// Shoot Them Up. Project from Udemy course


#include "Pickup/STUHealthPickup.h"
#include "STUUtils.h"
#include "Components/STUHealthComponent.h"

DEFINE_LOG_CATEGORY_STATIC(HealthPickupLog, All, All);

bool ASTUHealthPickup::GivePickupTo(APawn *PlayerPawn)
{
    USTUHealthComponent *HealthComponent = STUUtils::GetPlayerComponent<USTUHealthComponent>(PlayerPawn);

    if (!HealthComponent || HealthComponent->IsDead() || HealthComponent->IsFullHealth())
    {
        return false;
    }
    HealthComponent->AddHealth(PickupHealthAmount);
    return true;
}