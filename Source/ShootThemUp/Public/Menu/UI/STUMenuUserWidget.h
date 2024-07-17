// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "UI/STUBaseWidget.h"
#include "STUCoreTypes.h"
#include "STUMenuUserWidget.generated.h"

class UButton;
class UHorizontalBox;
class USTULevelItemWidget;
class USTUGameInstance;
class USoundCue;

UCLASS()
class SHOOTTHEMUP_API USTUMenuUserWidget : public USTUBaseWidget
{
	GENERATED_BODY()
	
 private:
    UFUNCTION()
    void OnGameStart();

    UFUNCTION()
    void QuitGame();

    void InitializeLevels();

    USTUGameInstance *GetLevelInstance();

    TArray<USTULevelItemWidget *> CreatedLevels;

  protected:
    UPROPERTY(meta = (BindWidget))
    UButton *StartGameButton;

    UPROPERTY(meta = (BindWidget))
    UButton *QuitGameButton;

    UPROPERTY(meta = (BindWidget))
    UHorizontalBox* LevelHorizontalBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LevelData")
    TSubclassOf<UUserWidget> SpawnedLevelClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* StartGameSound;

    virtual void NativeOnInitialized() override;

    UFUNCTION()
    void OnSelectedLevelChange(const FLevelData NewLevel);

    protected:
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation * HideAnim;

    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation *Animation) override;

};
