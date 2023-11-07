// Shoot Them Up. Project from Udemy course

#include "AI/Service/STUFindEnemyService.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/STUAIPerceptionComponent.h"
#include "STUUtils.h"

USTUFindEnemyService::USTUFindEnemyService()
{
    NodeName = "Find Enemy Service";
}

void USTUFindEnemyService::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    const auto BlackBoardComponent = OwnerComp.GetBlackboardComponent();

    if (BlackBoardComponent)
    {
        const auto Controller = OwnerComp.GetAIOwner();
        const auto PerceptionComponent = STUUtils::GetPlayerComponent<USTUAIPerceptionComponent>(Controller);

        if (PerceptionComponent)
        {
            BlackBoardComponent->SetValueAsObject(EmenyActorKey.SelectedKeyName, PerceptionComponent->GetClosedEnemy());
        }
    }

    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
