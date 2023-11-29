// Shoot Them Up. Project from Udemy course

#pragma once

#include "Components/STUWeaponComponent.h"
#include "CoreMinimal.h"
#include "STUWeaponAIComponent.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API USTUWeaponAIComponent : public USTUWeaponComponent
{
    GENERATED_BODY()

  public:
    virtual void StartFire() override;
    virtual void NextWeapon() override;
    bool NeedAmmo(TSubclassOf<ASTUBaseWeaponActor> Weapon) const;
};
