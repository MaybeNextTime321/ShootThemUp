// Shoot Them Up. Project from Udemy course

#include "AI/Service/STUChangeWeaponService.h"
#include "AIController.h"
#include "Components/STUWeaponComponent.h"
#include "GameFramework/Actor.h"
#include "STUUtils.h"
#include "TimerManager.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY_STATIC(ChangeServiceLog, All, All)

USTUChangeWeaponService::USTUChangeWeaponService()
{
    NodeName = "Change Weapon";
}

void USTUChangeWeaponService::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
        if (!WeaponComponent)
        {
            const auto Controller = OwnerComp.GetAIOwner();
            WeaponComponent = STUUtils::GetPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
        }

        if (WeaponComponent)
        {
            if (FMath::RandRange(0, 1) <= ReloadChanse)
            {
                WeaponComponent->NextWeapon();
            }
        }
        else
        {
            UE_LOG(ChangeServiceLog, Warning, TEXT("Error with WeaponComponent"));
        }
}