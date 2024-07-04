// Shoot Them Up. Project from Udemy course

#include "UI/STUPauseWidget.h"
#include "STUGameModeBase.h"
#include "Components/Button.h"

bool USTUPauseWidget::Initialize()
{
    bool InitializeParent = Super::Initialize();

    if (ClearPauseButton)
    {
        ClearPauseButton->OnClicked.AddDynamic(this, &USTUPauseWidget::ClearPause);
    }

    return InitializeParent;

}

void USTUPauseWidget::ClearPause()
{
    if (!GetWorld())
    {
        return;
    }

    const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());

    if (!GameMode)
    {
        return;
    }

    GameMode->Unpause();
}
