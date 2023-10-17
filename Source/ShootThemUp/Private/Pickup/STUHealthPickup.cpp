// Shoot Them Up. Project from Udemy course


#include "Pickup/STUHealthPickup.h"

DEFINE_LOG_CATEGORY_STATIC(HealthPickupLog, All, All);

bool ASTUHealthPickup::GivePickupTo(APawn *PlayerPawn)
{
    UE_LOG(HealthPickupLog, Display, TEXT("Health was taken"));
    return true;
}