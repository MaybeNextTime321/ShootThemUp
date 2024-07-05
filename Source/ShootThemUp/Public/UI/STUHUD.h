// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STUCoreTypes.h"
#include "STUHUD.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTUHUD : public AHUD
{
    GENERATED_BODY()

  public:
    void DrawHUD() override;

  protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerHUD;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PauseHUD;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> GameOverHUD;

    virtual void BeginPlay() override;

  private:
    UPROPERTY()
    TMap<ESTUMathState, UUserWidget *> MatchStateHUD;
    UPROPERTY()
    UUserWidget *CurrenntWidget = nullptr;
    void MathStateUpated(ESTUMathState NewState);
    void DrawAim();
};
