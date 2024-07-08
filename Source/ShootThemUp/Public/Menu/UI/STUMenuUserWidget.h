// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STUMenuUserWidget.generated.h"

class UButton;
class UHorizontalBox;
class USTULevelItemWidget;
class USTUGameInstance;

UCLASS()
class SHOOTTHEMUP_API USTUMenuUserWidget : public UUserWidget
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

    virtual void NativeOnInitialized() override;

    UFUNCTION()
    void OnSelectedLevelChange(const FLevelData NewLevel);

};
