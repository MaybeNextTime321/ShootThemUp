// Shoot Them Up. Project from Udemy course


#include "Player/STUPlayerState.h"
DEFINE_LOG_CATEGORY_STATIC(PlayerStateLog, All, All)


void ASTUPlayerState::DisplayStatistic() const
{
    UE_LOG(PlayerStateLog, Display, TEXT("TeamID: %i, Death: %i, Kills: %i"), PlayerTeamNumber, DeathCount, KillsCount);
}
