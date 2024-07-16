// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "UI/STUBaseWidget.h"
#include "STUCoreTypes.h"
#include "STUGameOverWidget.generated.h"

class UVerticalBox;
class UButton;

UCLASS()
class SHOOTTHEMUP_API USTUGameOverWidget : public USTUBaseWidget
{
    GENERATED_BODY()

  private:
    UFUNCTION()
    void OnLevelReset();

    UFUNCTION()
    void OnMathStateChange(ESTUMathState NewMatchState);

    void UpdatePlayerState();

  protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerStatRow;

    UPROPERTY(meta = (BindWidget))
    UButton *ResetLevelButton;

    UPROPERTY(meta = (BindWidget))
    UVerticalBox *PlayerStatBox;

    virtual void NativeOnInitialized() override;
};
