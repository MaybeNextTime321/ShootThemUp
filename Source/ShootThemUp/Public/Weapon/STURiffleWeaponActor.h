// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "STUBaseWeaponActor.h"
#include "STURiffleWeaponActor.generated.h"

class USTUWeaponFXComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UAudioComponent;

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
    USTUWeaponFXComponent *WeaponFXComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    UNiagaraSystem *TraceNiagaraSystem;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    FString TraceTargetName;

    virtual void BeginPlay() override;

    FTimerHandle TimerHandle;
    virtual bool GetTraceData(FVector &TraceStart, FVector &SoketForward, FVector &TraceEnd) override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    UAudioComponent *FireAudioComponent;

  private: 
    AController * GetController() const;
    void SpawnTraceAtLocation(const FVector &StartLocation, const FVector &EndLocation);
    UParticleSystemComponent *MuzzleFlashComponent;
    void SetVFXVisibility(bool IsActive);
    void MakeHitWithDamage(FHitResult HitResult);
};
