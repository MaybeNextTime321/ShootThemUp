// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "STUBaseWeaponActor.h"
#include "STULauncherBaseWeaponActor.generated.h"

class USphereComponent;
class ASTUProjectile;
/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTULauncherBaseWeaponActor : public ASTUBaseWeaponActor
{
    GENERATED_BODY()

  protected:
    void StartFire() override;
    void MakeShoot() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<ASTUProjectile> ProjectileClass;
};
