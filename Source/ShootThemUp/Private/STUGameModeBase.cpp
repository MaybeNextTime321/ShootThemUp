// Shoot Them Up. Project from Udemy course


#include "STUGameModeBase.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Components/STUWeaponComponent.h"
#include "Player/STUBaseCharacter.h"
#include "Player/STUPlayerController.h"
#include "Player/STUPlayerState.h"
#include "UI/STUHUD.h"

DEFINE_LOG_CATEGORY_STATIC(GameModeBase, All, All)

ASTUGameModeBase::ASTUGameModeBase()
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();
    HUDClass = ASTUHUD::StaticClass();
    PlayerStateClass = ASTUPlayerState::StaticClass();
}

void ASTUGameModeBase::StartPlay()
{
    Super::StartPlay();
    SpawnBots();
    SetupTeams();
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

void ASTUGameModeBase::SetKill(AController *Killer, AController *VictimController)
{
    const auto KillerState = Killer ? Cast<ASTUPlayerState>(Killer->PlayerState) : nullptr;
    const auto VictimState = VictimController ? Cast<ASTUPlayerState>(VictimController->PlayerState) : nullptr;

    if (KillerState)
    {
        KillerState->AddKills();
    }

    if (VictimState)
    {
        VictimState->AddDeath();
    }
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
        RestartPlayers();
    }
    else
    {
        UE_LOG(GameModeBase, Display, TEXT("============ GAME OVER ============"));
        DisplayPlayerStatictic();
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

void ASTUGameModeBase::DisplayPlayerStatictic() const
{
    if (!GetWorld())
    {
        return;
    }

    for (auto it = GetWorld()->GetControllerIterator(); it; ++it)
    {
        const auto Controller = it->Get();
        if (!Controller)
        {
            continue;
        }

        const auto PlayerState = Cast<ASTUPlayerState>(Controller->PlayerState);
        if (!PlayerState)
        {
            continue;
        }

        PlayerState->DisplayStatistic();
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

void ASTUGameModeBase::RestartPlayers()
{
    if (!GetWorld())
    {
        return;
    }

    for (auto it = GetWorld()->GetControllerIterator(); it; ++it)
    {
        RestartSinglePlayer(it->Get());
    }
}

void ASTUGameModeBase::RestartSinglePlayer(AController *PawnController)
{
    if (PawnController && PawnController->GetPawn())
    {
        auto WeaponComponent = STUUtils::GetPlayerComponent<USTUWeaponComponent>(PawnController->GetPawn());
        if (WeaponComponent)
        {
            WeaponComponent->DestuctWeapon();
        }
        PawnController->GetPawn()->Reset();
    }

    RestartPlayer(PawnController);
    SetPlayerColor(PawnController);
}

void ASTUGameModeBase::SetupTeams()
{
    if (!GetWorld())
    {
        return;
    }

    int32 TeamNumber = 1;
    for (auto it = GetWorld()->GetControllerIterator(); it; ++it)
    {
        const auto PlayerController = it->Get();
        if (!PlayerController)
            continue;

        auto PlayerState = Cast<ASTUPlayerState>(PlayerController->PlayerState);
        if (!PlayerState)
            continue;

        PlayerState->SetTeamNumber(TeamNumber);
        PlayerState->SetTeamColor(GetColorByTeamID(TeamNumber));

        SetPlayerColor(PlayerController);

        TeamNumber = TeamNumber == 1 ? 2 : 1;
    }

}

FLinearColor ASTUGameModeBase::GetColorByTeamID(int32 TeamID)
{
    const int32 TeamIndexID = TeamID - 1;

    if (TeamIndexID < Gamemode.TeamColors.Num())
    {
        return Gamemode.TeamColors[TeamIndexID];
    }

    UE_LOG(GameModeBase, Display, TEXT("CHECK STEUPED TEAM COLORS"));
    return Gamemode.DefaultColor;
}

void ASTUGameModeBase::SetPlayerColor(AController *PlayerController)
{
    if (!PlayerController)
        return;

    const auto PlayerState = Cast<ASTUPlayerState>(PlayerController->PlayerState);
    if (!PlayerState)
        return;

    FLinearColor SetupColor = PlayerState->GetPlayerColor();

    auto Character = Cast<ASTUBaseCharacter>(PlayerController->GetPawn());

    if (!Character)
    {
        return;
    }

    Character->SetColor(SetupColor);
}
