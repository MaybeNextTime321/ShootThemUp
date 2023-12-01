// Shoot Them Up. Project from Udemy course

#include "STUGameModeBaseSplit.h"
#include "AIController.h"
#include "Player/STUBaseCharacter.h"
#include "Player/STUPlayerController.h"
#include "UI/STUHUD.h"

ASTUGameModeBaseSplit::ASTUGameModeBaseSplit()
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();
    HUDClass = ASTUHUD::StaticClass();
}

void ASTUGameModeBaseSplit::StartPlay()
{
    Super::StartPlay();
    SpawnBots();
}

UClass *ASTUGameModeBaseSplit::GetDefaultPawnClassForController_Implementation(AController *InController)
{
    if (InController && InController->IsA<AAIController>())
    {
        return AIPawnClass;
    }

    return Super::GetDefaultPawnClassForController_Implementation(InController);
}

void ASTUGameModeBaseSplit::SpawnBots()
{
    if (!GetWorld())
    {
        return;
    }

    for (int i = 0; i < Gamemode.NumberOfPlayers - 1; ++i)
    {
        FActorSpawnParameters SpawnParam;
        SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        const auto AIController = GetWorld()->SpawnActor<AAIController>(AIControllerClass, SpawnParam);
        RestartPlayer(AIController);
    }
}
