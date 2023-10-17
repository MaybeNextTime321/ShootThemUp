// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Pickup/STUBasePickup.h"
#include "STUAmmoPickup.generated.h"

/**
 * 
 */
class ASTUBaseWeaponActor;

UCLASS()
class SHOOTTHEMUP_API ASTUAmmoPickup : public ASTUBasePickup
{
	GENERATED_BODY()

  protected:
    virtual bool GivePickupTo(APawn *PlayerPawn);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Puckup" , meta = (ClampMin = "1.0", ClampMax = "10.0"))
    int32 ClipsAmount = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Puckup") 
	TSubclassOf<ASTUBaseWeaponActor> WeaponType;
};
