// Shoot Them Up. Project from Udemy course

#include "Components/STUAIPerceptionComponent.h"
#include "AIController.h"
#include "Components/STUHealthComponent.h"
#include "Perception/AISense_Sight.h"
#include "STUUtils.h"

AActor *USTUAIPerceptionComponent::GetClosedEnemy() const
{
    TArray<AActor *> Perseptions;
    GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), Perseptions);

    if (Perseptions.Num() == 0)
    {
        return nullptr;
    }

    const auto Controller = Cast<AAIController>(GetOwner());

    if (!Controller)
    {
        return nullptr;
    }

    const auto Pawn = Controller->GetPawn();

    if (!Pawn)
    {
        return nullptr;
    }

    float BestDistance = MAX_FLT;
    AActor *BestPawn = nullptr;

    for (const auto PerceptedActor : Perseptions)
    {
        const auto HealthComponent = STUUtils::GetPlayerComponent<USTUHealthComponent>(PerceptedActor);
        if (HealthComponent && !HealthComponent->IsDead())
        {
            const auto Distace = (PerceptedActor->GetActorLocation() - Pawn->GetActorLocation()).Size();

            if (Distace < BestDistance)
            {
                BestDistance = Distace;
                BestPawn = PerceptedActor;
            }
        }
    }

    return BestPawn;
}