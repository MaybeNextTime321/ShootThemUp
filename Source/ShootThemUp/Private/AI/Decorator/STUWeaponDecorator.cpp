// Shoot Them Up. Project from Udemy course

#include "AI/Decorator/STUWeaponDecorator.h"
#include "AIController.h"
#include "Components/STUWeaponAIComponent.h"
#include "STUBaseWeaponActor.h"
#include "STUUtils.h"

USTUWeaponDecorator::USTUWeaponDecorator()
{
    NodeName = "WeaponDecorator";
}

bool USTUWeaponDecorator::CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const
{
    const auto Owner = OwnerComp.GetAIOwner();
    if (!Owner)
    {
        return false;
    }

    const auto WeaponComponent = STUUtils::GetPlayerComponent<USTUWeaponAIComponent>(Owner->GetPawn());

    return WeaponComponent->NeedAmmo(CheckinWeapon);
}
