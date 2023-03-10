// Shoot Them Up. Project from Udemy course

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "STUHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeadSignature)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTakeDamageSignature, float)

    UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) class SHOOTTHEMUP_API USTUHealthComponent
    : public UActorComponent
{
    GENERATED_BODY()

  public:
    // Sets default values for this component's properties
    USTUHealthComponent();
    float GetHealth() const
    {
        return Health;
    }

    UFUNCTION(BlueprintCallable)
    bool IsDead()
    {
        return Health <= 0.0f;
    }

    FOnDeadSignature OnDead;
    FOnTakeDamageSignature OnHealthChange;

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

    void StartAutoHeal();
    void StopAutoHeal();
};
