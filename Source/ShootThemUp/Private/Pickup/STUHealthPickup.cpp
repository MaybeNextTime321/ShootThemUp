// Shoot Them Up. Project from Udemy course


#include "Pickup/STUHealthPickup.h"
#include "Components/STUHealthComponent.h"

DEFINE_LOG_CATEGORY_STATIC(HealthPickupLog, All, All);

bool ASTUHealthPickup::GivePickupTo(APawn *PlayerPawn)
{
    USTUHealthComponent *HealthComponent = PlayerPawn->GetComponentByClass<USTUHealthComponent>();

    if (!HealthComponent || HealthComponent->IsDead() || HealthComponent->IsFullHealth())
    {
        return false;
    }
    HealthComponent->AddHealth(PickupHealthAmount);
    return true;
}