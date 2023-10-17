// Shoot Them Up. Project from Udemy course


#include "Pickup/STUAmmoPickup.h"

DEFINE_LOG_CATEGORY_STATIC(AmmoPickupLog, All, All);

bool ASTUAmmoPickup::GivePickupTo(APawn *PlayerPawn)
{
    UE_LOG(AmmoPickupLog, Display, TEXT("Ammo was taken"));
    return true;
}
