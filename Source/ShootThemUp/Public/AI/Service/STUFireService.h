// Shoot Them Up. Project from Udemy course

#pragma once

#include "BehaviorTree/BTService.h"
#include "CoreMinimal.h"
#include "STUFireService.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTUFireService : public UBTService
{
    GENERATED_BODY()

  protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector EmenyActorKey;

  public:
    USTUFireService();
    virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
