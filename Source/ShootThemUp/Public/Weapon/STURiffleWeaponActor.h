// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "STUBaseWeaponActor.h"
#include "STURiffleWeaponActor.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTURiffleWeaponActor : public ASTUBaseWeaponActor
{
    GENERATED_BODY()

  public:
    void StartFire() override;
    void EndFire() override;
    void MakeShoot() override;

  protected:
    FTimerHandle TimerHandle;
    virtual bool GetTraceData(FVector &TraceStart, FVector &SoketForward, FVector &TraceEnd) override;

  private:
    bool MakeHit(FVector &TraceStart, FVector &TraceEnd, FHitResult &HitResult);
    void MakeHit(FHitResult HitResult);
};
