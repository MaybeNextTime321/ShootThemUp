// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "STUNextLocationTask.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUNextLocationTask : public UBTTaskNode
{
	GENERATED_BODY()
	
	public:
    USTUNextLocationTask();
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;

	protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
      float SphereRadius = 1000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
      FBlackboardKeySelector AimLocationKey;
    
};
