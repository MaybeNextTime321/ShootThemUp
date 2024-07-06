// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUMenuUserWidget.generated.h"

class UButton;


UCLASS()
class SHOOTTHEMUP_API USTUMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
 private:
    UFUNCTION()
    void OnGameStart();


  protected:
    UPROPERTY(meta = (BindWidget))
    UButton *StartGameButton;

    virtual void NativeOnInitialized() override;
};
