// Shoot Them Up. Project from Udemy course

#pragma once

#include "BehaviorTree/BTService.h"
#include "CoreMinimal.h"
#include "STUFindEnemyService.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTUFindEnemyService : public UBTService
{
    GENERATED_BODY()

  protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector EmenyActorKey;

  public:
    USTUFindEnemyService();
    virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
