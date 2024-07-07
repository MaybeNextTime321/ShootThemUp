// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "STUGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUGameInstance : public UGameInstance
{
	GENERATED_BODY()
	public:
		FName GetStartLevelName()
		{
            return FirstLevelName;
		}

		FName GetMenuLevelName()
        {
            return MenuLevelName;
        }

	protected:
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LevelData")
		FName FirstLevelName = NAME_None;

        UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LevelData")
        FName MenuLevelName = NAME_None;
};
