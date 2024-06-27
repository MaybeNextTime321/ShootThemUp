// Shoot Them Up. Project from Udemy course

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "STUCoreTypes.h"
#include "STUHealthComponent.generated.h"

class UCameraShakeBase;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    void AddHealth(float HealthAmount);
    // Sets default values for this component's properties
    USTUHealthComponent();
    float GetHealth() const
    {
        return Health;
    }

    UFUNCTION(BlueprintCallable)
    float GetHealthProcent() const
    {
        return Health / MaxHealth;
    }

    UFUNCTION(BlueprintCallable)
    bool IsDead() const
    {
        return Health <= 0.0f;
    }

    FOnDeadSignature OnDead;
    FOnTakeDamageSignature OnHealthChange;

    bool IsFullHealth();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Autoheal")
    bool Autoheal = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Autoheal",
              meta = (ClampMin = "0", ClampMax = "100.0", EditCondition = "Autoheal"))
    float TimerRate = 1.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Autoheal",
              meta = (ClampMin = "0", ClampMax = "100.0", EditCondition = "Autoheal"))
    float TimerDelay = 1.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Autoheal",
              meta = (ClampMin = "0", ClampMax = "100.0", EditCondition = "Autoheal"))
    float AutoHealValue = 1.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Autoheal")
    TSubclassOf<UCameraShakeBase> DamageCamaeraShake;

  protected:
    // Called when the game starts
    virtual void BeginPlay() override;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0", ClampMax = "100.0"))
    float MaxHealth = 100.0f;

    UFUNCTION()
    void OnAutoHeal();

  private:
    float Health = 0.0f;
    FTimerHandle HealTimer;
    UWorld *World;
    void SetHealth(float Health);

    UFUNCTION()
    void OnTakeAnyDamage(AActor *DamagedActor, float Damage, const class UDamageType *DamageType,
                         class AController *InstigatedBy, AActor *DamageCauser);
    void Killed(AController *KilledBy);
    void PlayCameraShake();
    void StartAutoHeal();
    void StopAutoHeal();
};
