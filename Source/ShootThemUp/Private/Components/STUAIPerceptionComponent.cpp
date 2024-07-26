// Shoot Them Up. Project from Udemy course

#include "Components/STUAIPerceptionComponent.h"
#include "AIController.h"
#include "Components/STUHealthComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISense_Damage.h"
#include "STUUtils.h"

AActor *USTUAIPerceptionComponent::GetClosedEnemy() const
{
    TArray<AActor *> Perseptions;
    GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), Perseptions);

    if (Perseptions.Num() == 0)
    {
        GetCurrentlyPerceivedActors(UAISense_Damage::StaticClass(), Perseptions);

        if (Perseptions.Num() == 0)
        {
            return nullptr;
        }
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
        const auto PerceptedPawn = Cast<APawn>(PerceptedActor);
        const bool AreEnemy = STUUtils::AreEnemy(Controller, PerceptedPawn->Controller);
        if (HealthComponent && !HealthComponent->IsDead() && AreEnemy)
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
