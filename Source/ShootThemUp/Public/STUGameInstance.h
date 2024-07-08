// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "STUCoreTypes.h"
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
		FLevelData GetStartLevel()
		{
            return StartedLevel;
		}

        TArray<FLevelData> GetGameLevels()
        {
            return GameLevels;
        }

		FName GetMenuLevelName()
        {
            return MenuLevelName;
        }

		void SetStartedLevel(const FLevelData NewStartedLevel)
		{
            StartedLevel = NewStartedLevel;
		}

	protected:
        UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LevelData")
        TArray<FLevelData> GameLevels;

        UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LevelData")
        FName MenuLevelName = NAME_None;

	private:
        FLevelData StartedLevel;
        
};
