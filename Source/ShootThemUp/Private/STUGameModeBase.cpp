// Shoot Them Up. Project from Udemy course


#include "STUGameModeBase.h"
#include "AIController.h"
#include "Player/STUBaseCharacter.h"
#include "Player/STUPlayerController.h"
#include "UI/STUHUD.h"

DEFINE_LOG_CATEGORY_STATIC(GameModeBase, All, All)

ASTUGameModeBase::ASTUGameModeBase()
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();
    HUDClass = ASTUHUD::StaticClass();
}

void ASTUGameModeBase::StartPlay()
{
    Super::StartPlay();
    SpawnBots();
    RoundStart();
}

UClass *ASTUGameModeBase::GetDefaultPawnClassForController_Implementation(AController *InController)
{
    if (InController && InController->IsA<AAIController>())
    {
        return AIPawnClass;
    }

    return Super::GetDefaultPawnClassForController_Implementation(InController);
}

void ASTUGameModeBase::RoundStart()
{
    UE_LOG(GameModeBase, Display, TEXT("ROUND OVER"));
    ++CurrentRound;
    GetWorld()->GetTimerManager().ClearTimer(RoundTimer);

    if (CurrentRound <= Gamemode.NumberOfRounds)
    {
        GetWorld()->GetTimerManager().SetTimer(RoundTimer, this, &ASTUGameModeBase::RoundTimerUpdate, 1.0f, true);
        TimeRemainInRound = Gamemode.RoundDurationInSecond;
    }
    else
    {
        UE_LOG(GameModeBase, Display, TEXT("============ GAME OVER ============"));
    }
   
}

void ASTUGameModeBase::RoundTimerUpdate()
{
    --TimeRemainInRound;
    UE_LOG(GameModeBase, Display, TEXT("Round: %i/%i    Time Remain: %i/%i "),CurrentRound,Gamemode.NumberOfRounds,TimeRemainInRound,Gamemode.RoundDurationInSecond);
    if (TimeRemainInRound == 0)
    {
        RoundStart();
    }
}

void ASTUGameModeBase::SpawnBots()
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
