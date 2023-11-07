#include "AI/Tasks/STUNextLocationTask.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

USTUNextLocationTask::USTUNextLocationTask()
{
    NodeName = "Next Location Task";
}

EBTNodeResult::Type USTUNextLocationTask::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    const auto Controller = OwnerComp.GetAIOwner();
    const auto BlackboardComponent = OwnerComp.GetBlackboardComponent();

    if (!Controller || !BlackboardComponent)
    {
        return EBTNodeResult::Failed;
    }

    const auto Pawn = Controller->GetPawn();

    if (!Pawn)
    {
        return EBTNodeResult::Failed;
    }

    const auto NavSys = UNavigationSystemV1::GetCurrent(Pawn);

    if (!NavSys)
    {
        return EBTNodeResult::Failed;
    }
    FNavLocation Result;

    auto Location = Pawn->GetActorLocation();

    if (!SelfCenter)
    {
        const auto Actor = Cast<AActor>(BlackboardComponent->GetValueAsObject(MovingActor.SelectedKeyName));
        if (!Actor)
        {
            return EBTNodeResult::Failed;
        }
        Location = Actor->GetActorLocation();
    }

    const auto Found = NavSys->GetRandomReachablePointInRadius(Location, SphereRadius, Result);

    if (!Found)
    {
        return EBTNodeResult::Failed;
    }

    BlackboardComponent->SetValueAsVector(AimLocationKey.SelectedKeyName, Result.Location);

    return EBTNodeResult::Succeeded;
}
