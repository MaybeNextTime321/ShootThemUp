// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUSpectatingWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUSpectatingWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
    UFUNCTION(BlueprintCallable)
    bool GetRespwanTime(int32 &RespawnTime);

	
};
