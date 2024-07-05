// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STUGameOverWidget.generated.h"

class UVerticalBox;

UCLASS()
class SHOOTTHEMUP_API USTUGameOverWidget : public UUserWidget
{
    GENERATED_BODY()
  public:
          virtual bool Initialize() override;

  private:


    UFUNCTION()
    void OnMathStateChange(ESTUMathState NewMatchState);

    void UpdatePlayerState();

  protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerStatRow;

    UPROPERTY(meta = (BindWidget))
    UVerticalBox *PlayerStatBox;
};
