// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "STUCoreTypes.h"
#include "GameFramework/GameModeBase.h"
#include "STUGameModeBase.generated.h"

class AAIController;

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTUGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

  public:
    ASTUGameModeBase();

    virtual void StartPlay() override;
    virtual UClass *GetDefaultPawnClassForController_Implementation(AController *InController) override;

  protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game")
    FGameData Gamemode;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game")
    TSubclassOf<AAIController> AIControllerClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game")
    TSubclassOf<APawn> AIPawnClass;

    void RoundStart();
    void RoundTimerUpdate();

  private:
    void SpawnBots();
    FTimerHandle RoundTimer;
    int32 CurrentRound = 0;
    int32 TimeRemainInRound = 0;
    void RestartPlayers();
    void RestartSinglePlayer(AController *PawnController);
    void SetupTeams();
    FLinearColor GetColorByTeamID(int32 TeamID);
    void SetPlayerColor(AController *PlayerController);
};
