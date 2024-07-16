// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STUCoreTypes.h"
#include "STUHUD.generated.h"

class USTUBaseWidget;
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
    TSubclassOf<USTUBaseWidget> PlayerHUD;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<USTUBaseWidget> PauseHUD;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<USTUBaseWidget> GameOverHUD;

    virtual void BeginPlay() override;

  private:
    UPROPERTY()
    TMap<ESTUMathState, USTUBaseWidget *> MatchStateHUD;
    UPROPERTY()
    USTUBaseWidget *CurrenntWidget = nullptr;
    void MathStateUpated(ESTUMathState NewState);
    void DrawAim();
};
