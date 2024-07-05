// Shoot Them Up. Project from Udemy course

#include "UI/STUSingleStatWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"


void USTUSingleStatWidget::SetPlayerName(FText Name)
{
    if (!PlayerName)
    {
        return;
    }

    PlayerName->SetText(Name);
}

void USTUSingleStatWidget::SetPlayerKills(FText NumberOfKills)
{
    if (!PlayerKills)
    {
        return;
    }
    PlayerKills->SetText(NumberOfKills);
}

void USTUSingleStatWidget::SetPlayerDeath(FText NumberOfDeath)
{
    if (!PlayerDeath)
    {
        return;
    }
    PlayerDeath->SetText(NumberOfDeath);
}

void USTUSingleStatWidget::SetPlayerTeam(FText TeamName)
{
    if (!PlayerTeam)
    {
        return;
    }
    PlayerTeam->SetText(TeamName);
}

void USTUSingleStatWidget::SetPlayerImageVisibility(bool IsVisible)
{
    if (!BackgroundImage)
    {
        return;
    }
    BackgroundImage->SetVisibility(IsVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void USTUSingleStatWidget::SetPlayerImageColor(FColor NewColor)
{
    if (!BackgroundImage)
    {
        return;
    }
    FColor ChangedColor = NewColor;
    NewColor.A = 255;
    BackgroundImage->SetColorAndOpacity(NewColor);
}
