// Shoot Them Up. Project from Udemy course


#include "Menu/UI/STUMenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void USTUMenuUserWidget::OnGameStart()
{
    const FName NewLevel = "TestLevel";

    UGameplayStatics::OpenLevel(this, NewLevel);
}

void USTUMenuUserWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();
    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &USTUMenuUserWidget::OnGameStart);
    }
}
