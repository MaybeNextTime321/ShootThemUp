// Shoot Them Up. Project from Udemy course

#pragma once

#include "BehaviorTree/BTDecorator.h"
#include "CoreMinimal.h"
#include "STUWeaponDecorator.generated.h"

/**
 *
 */
class ASTUBaseWeaponActor;

UCLASS()
class SHOOTTHEMUP_API USTUWeaponDecorator : public UBTDecorator
{
    GENERATED_BODY()

  public:
    USTUWeaponDecorator();

  protected:
  protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    TSubclassOf<ASTUBaseWeaponActor> CheckinWeapon;

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const override;
};
