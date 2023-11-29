// Shoot Them Up. Project from Udemy course

#include "AI/Decorator/STUHealthPersentDecorator.h"
#include "AIController.h"
#include "Components/STUHealthComponent.h"
#include "STUUtils.h"

USTUHealthPersentDecorator::USTUHealthPersentDecorator()
{
    NodeName = "Health Persent";
}

bool USTUHealthPersentDecorator::CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const
{
    const auto Owner = OwnerComp.GetAIOwner();
    if (!Owner)
    {
        return false;
    }

    const auto HealthComponent = STUUtils::GetPlayerComponent<USTUHealthComponent>(Owner->GetPawn());

    if (!HealthComponent || HealthComponent->IsDead() || HealthComponent->GetHealthProcent() > HealthPersent)
    {
        return false;
    }

    return true;
}
