// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "STUPlayerState.generated.h"

/**
 * 
 */

UCLASS()
class SHOOTTHEMUP_API ASTUPlayerState : public APlayerState
{
    GENERATED_BODY()

  public:
    void SetTeamNumber(int32 Number)
    {
        PlayerTeamNumber = Number;
    }
    void SetTeamColor(FLinearColor Color)
    {
        PlayerColor = Color;
    }
    int32 GetTeamNumber()
    {
        return PlayerTeamNumber;
    }
    FLinearColor GetPlayerColor()
    {
        return PlayerColor;
    }
    int32 GetKills() const
    {
        return KillsCount;
    }
    int32 GetDeath() const
    {
        return DeathCount;
    }

    void AddKills()
    {
        ++KillsCount;
    }
    void AddDeath()
    {
        ++DeathCount;
    }
    void DisplayStatistic() const;

  private:
    int32 PlayerTeamNumber;
    FLinearColor PlayerColor;
    int32 DeathCount;
    int32 KillsCount;
};
