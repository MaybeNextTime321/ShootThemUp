// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Pickup/STUBasePickup.h"
#include "STUHealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTUHealthPickup : public ASTUBasePickup
{
	GENERATED_BODY()
	
	protected:
		virtual bool GivePickupTo(APawn *PlayerPawn);

      UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthPickup",
                meta = (ClampMin = "0", ClampMax = "100.0"))
      float PickupHealthAmount = 30.0f;
};
