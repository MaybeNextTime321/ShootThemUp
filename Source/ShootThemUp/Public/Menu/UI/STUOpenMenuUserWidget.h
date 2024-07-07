// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUOpenMenuUserWidget.generated.h"

class UButton;

UCLASS()
class SHOOTTHEMUP_API USTUOpenMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

  private:
    UFUNCTION()
    void OnOpenMenu();

  protected:
    UPROPERTY(meta = (BindWidget))
    UButton *OpenMenuButton;

    virtual void NativeOnInitialized() override;
};
