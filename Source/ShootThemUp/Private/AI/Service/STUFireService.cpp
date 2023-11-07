// Shoot Them Up. Project from Udemy course

#include "AI/Service/STUFireService.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/STUAIPerceptionComponent.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"

USTUFireService::USTUFireService()
{
    NodeName = "Fire Service";
}

void USTUFireService::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    const auto Controller = OwnerComp.GetAIOwner();
    const auto BlackBoardComponent = OwnerComp.GetBlackboardComponent();

    const auto HasAim = BlackBoardComponent && BlackBoardComponent->GetValueAsObject(EmenyActorKey.SelectedKeyName);

    if (Controller)
    {
        const auto WeaponComponent = STUUtils::GetPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());

        if (WeaponComponent)
        {
            HasAim ? WeaponComponent->StartFire() : WeaponComponent->EndFire();
        }
    }

    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
