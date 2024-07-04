// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STUPauseWidget.generated.h"

class UButton;

UCLASS()
class SHOOTTHEMUP_API USTUPauseWidget : public UUserWidget
{
    GENERATED_BODY()
  public:
    virtual bool Initialize() override;

  protected:
    UPROPERTY(meta = (BindWidget))
    UButton *ClearPauseButton;

  private:
     UFUNCTION()
     void ClearPause();
};
