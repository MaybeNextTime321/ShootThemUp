// Shoot Them Up. Project from Udemy course

#include "UI/STUGameDataWidget.h"
#include "Player/STUPlayerState.h"
#include "STUGameModeBase.h"

int32 USTUGameDataWidget::GetRoundCount() const
{
    const auto GameMode = GetGameMode();
    return GameMode ? GameMode->GetMaxRound() : 0;
}

int32 USTUGameDataWidget::GetCurrentRound() const
{
    const auto GameMode = GetGameMode();
    return GameMode ? GameMode->GetCurrentRound() : 0;
}

int32 USTUGameDataWidget::GetRoundCurrentTime() const
{
    const auto GameMode = GetGameMode() ;
    return GameMode ? GameMode->GetRoundTime() : 0;
}

int32 USTUGameDataWidget::GetPlayerKills() const
{
    const auto PlayerState = GetPlayerState();
    return PlayerState ? PlayerState->GetKills() : 0;
}

int32 USTUGameDataWidget::GetPlayerDeath() const
{
    const auto PlayerState = GetPlayerState();
    return PlayerState ? PlayerState->GetDeath() : 0;
}

ASTUGameModeBase *USTUGameDataWidget::GetGameMode() const
{
    return GetWorld() ? Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
  
}

ASTUPlayerState *USTUGameDataWidget::GetPlayerState() const
{
    return GetOwningPlayer() ? Cast<ASTUPlayerState>(GetOwningPlayer()->PlayerState) : nullptr;
}
