// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STULevelItemWidget.generated.h"

class UButton;
class UTextBlock;
class UImage;


UCLASS()
class SHOOTTHEMUP_API USTULevelItemWidget : public UUserWidget
{
    GENERATED_BODY()

  public:
    FOnLevelSelected OnLevelSelectedDelegate;

    void SetImageVisibility(bool IsVisible);

    FLevelData GetLevelData()
    {
        return CurrentLevelData;
    }

    void SetLevelData(FLevelData NewLevelData);

  protected:
    UPROPERTY(meta = (BindWidget))
    UImage *LevelBorder;

    UPROPERTY(meta = (BindWidget))
    UImage *LevelImage;

    UPROPERTY(meta = (BindWidget))
    UButton *SelectLevelButton;

    UPROPERTY(meta = (BindWidget))
    UTextBlock *LevelName;

    virtual void NativeOnInitialized() override;

  private:
    FLevelData CurrentLevelData;

    UFUNCTION()
    void OnLevelSelected();

};
