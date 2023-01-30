// Shoot Them Up. Project from Udemy course

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "STUHealthComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    // Sets default values for this component's properties
    USTUHealthComponent();
    float GetHealth() const
    {
        return Health;
    }

  protected:
    // Called when the game starts
    virtual void BeginPlay() override;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "0", ClampMax = "100.0"))
    float MaxHealth = 100.0f;

  private:
    float Health = 0.0f;
};