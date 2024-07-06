// Shoot Them Up. Project from Udemy course


#include "Menu/UI/STUMenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "STUGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(STUMenuWigetLog, All, All)

void USTUMenuUserWidget::OnGameStart()
{
    if (!GetWorld())
    {
        return;
    }
    const auto GameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
    const FName LevelName = GameInstance->GetStartLevelName();

    if (LevelName == NAME_None)
    {
        UE_LOG(STUMenuWigetLog, Error, TEXT("Setup First Level Name in Game Instance"));
    }

    UGameplayStatics::OpenLevel(this, LevelName);
}

void USTUMenuUserWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();
    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &USTUMenuUserWidget::OnGameStart);
    }
}
