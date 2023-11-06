// Shoot Them Up. Project from Udemy course

#include "AI/STUAIController.h"
#include "AI/STUAICharacter.h"
#include "Components/STUAIPerceptionComponent.h"
#include "Perception/AIPerceptionComponent.h"

void ASTUAIController::OnPossess(APawn *InPawn)
{
    Super::OnPossess(InPawn);

    const auto STUCharacter = Cast<ASTUAICharacter>(InPawn);

    if (STUCharacter)
    {
        RunBehaviorTree(STUCharacter->BehaviorTreeAsset);
    }
}

void ASTUAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    const auto AimActor = Component->GetClosedEnemy();
    SetFocus(AimActor);
}

ASTUAIController::ASTUAIController()
{
    Component = CreateDefaultSubobject<USTUAIPerceptionComponent>("PerseptionComponent");
    SetPerceptionComponent(*Component);
}
