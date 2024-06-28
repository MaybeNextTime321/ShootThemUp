// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUGameDataWidget.generated.h"

class ASTUPlayerState;
class ASTUGameModeBase;
/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUGameDataWidget : public UUserWidget
{
    GENERATED_BODY()
  public:
    UFUNCTION(BlueprintCallable)
    int32 GetRoundCount() const;
    UFUNCTION(BlueprintCallable)
    int32 GetCurrentRound() const;
    UFUNCTION(BlueprintCallable)
    int32 GetRoundCurrentTime() const;
    UFUNCTION(BlueprintCallable)
    int32 GetPlayerKills() const;
    UFUNCTION(BlueprintCallable)
    int32 GetPlayerDeath() const;
  private:
    ASTUGameModeBase *GetGameMode() const;
    ASTUPlayerState *GetPlayerState() const;
};
