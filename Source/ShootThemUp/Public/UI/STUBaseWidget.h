// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUBaseWidget.generated.h"

class USoundCue;


UCLASS()
class SHOOTTHEMUP_API USTUBaseWidget : public UUserWidget
{
	GENERATED_BODY()

  public:
    void ShowAnimation();

  protected:
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation *ShowAnim;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue *ShowWidgetSound;
};
