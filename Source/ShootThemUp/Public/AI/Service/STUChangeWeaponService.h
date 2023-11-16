// Shoot Them Up. Project from Udemy course

#pragma once

#include "BehaviorTree/BTService.h"
#include "CoreMinimal.h"
#include "STUChangeWeaponService.generated.h"

class USTUWeaponComponent;

UCLASS()
class SHOOTTHEMUP_API USTUChangeWeaponService : public UBTService
{
    GENERATED_BODY()

  protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float ReloadTimerRate = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (ClampMin = "0", ClampMax = "1.0"))
    float ReloadChanse = 0.5f;

  public:
    USTUChangeWeaponService();
    virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

  private:
    FTimerHandle Timer;
    USTUWeaponComponent *WeaponComponent;
};
