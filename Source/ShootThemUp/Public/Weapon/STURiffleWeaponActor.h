// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "STUBaseWeaponActor.h"
#include "STURiffleWeaponActor.generated.h"

class USTUWeaponFXComponent;

UCLASS()
class SHOOTTHEMUP_API ASTURiffleWeaponActor : public ASTUBaseWeaponActor
{
    GENERATED_BODY()

  public:
    void StartFire() override;
    void EndFire() override;
    void MakeShoot() override;
    ASTURiffleWeaponActor();
  protected:

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    USTUWeaponFXComponent* WeaponFXComponent;

    virtual void BeginPlay() override;

    FTimerHandle TimerHandle;
    virtual bool GetTraceData(FVector &TraceStart, FVector &SoketForward, FVector &TraceEnd) override;

  private:
    void MakeHitWithDamage(FHitResult HitResult);
};
