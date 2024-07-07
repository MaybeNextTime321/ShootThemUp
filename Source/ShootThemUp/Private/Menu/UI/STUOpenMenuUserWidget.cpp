// Shoot Them Up. Project from Udemy course


#include "Menu/UI/STUOpenMenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "STUGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(STUOpenMenuWigetLog, All, All)

void USTUOpenMenuUserWidget::OnOpenMenu()
{
    if (!GetWorld())
    {
        return;
    }
    const auto GameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();

    if (!GameInstance)
    {
        return;
    }


    const FName LevelName = GameInstance->GetMenuLevelName();

    if (LevelName == NAME_None)
    {
        UE_LOG(STUOpenMenuWigetLog, Error, TEXT("Setup Menu Level Name in Game Instance"));
    }

    UGameplayStatics::OpenLevel(this, LevelName);
}

void USTUOpenMenuUserWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();
    if (OpenMenuButton)
    {
        OpenMenuButton->OnClicked.AddDynamic(this, &USTUOpenMenuUserWidget::OnOpenMenu);
    }
}


