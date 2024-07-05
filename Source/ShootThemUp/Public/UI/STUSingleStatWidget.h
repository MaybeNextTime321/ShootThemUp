// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUSingleStatWidget.generated.h"

class UTextBlock;
class UImage;

UCLASS()
class SHOOTTHEMUP_API USTUSingleStatWidget : public UUserWidget
{
	GENERATED_BODY()


public:
    void SetPlayerName(FText Name);
	void SetPlayerKills(FText NumberOfKills);
    void SetPlayerDeath(FText NumberOfDeath);
    void SetPlayerTeam(FText TeamName);
    void SetPlayerImageVisibility(bool IsVisible);
    void SetPlayerImageColor(FColor NewColor);

 protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock *PlayerName;

	UPROPERTY(meta = (BindWidget))
    UTextBlock *PlayerKills;
	
	UPROPERTY(meta = (BindWidget))
    UTextBlock *PlayerDeath;

	UPROPERTY(meta = (BindWidget))
    UTextBlock *PlayerTeam;

	UPROPERTY(meta = (BindWidget))
    UImage *BackgroundImage;
};
