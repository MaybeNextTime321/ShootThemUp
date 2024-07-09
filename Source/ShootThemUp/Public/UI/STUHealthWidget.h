// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUHealthWidget.generated.h"

class UProgressBar;

UCLASS()
class SHOOTTHEMUP_API USTUHealthWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
		void SetProgress(float ProgressValue);
	
	protected:
		UPROPERTY(meta = (BindWidget))
		UProgressBar *HealthProgressBar;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthWidget")
		float PersentForVisibility = 0.8;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthWidget")
		float PersentForBadColor = 0.3;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthWidget")
        FColor GoodColor = FColor::White;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthWidget")
		FColor BadColor = FColor::Red;
};
