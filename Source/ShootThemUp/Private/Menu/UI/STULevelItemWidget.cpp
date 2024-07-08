// Shoot Them Up. Project from Udemy course


#include "Menu/UI/STULevelItemWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "STUGameInstance.h"



void USTULevelItemWidget::SetImageVisibility(bool IsVisible)
{
    if (LevelBorder)
    {
        LevelBorder->SetVisibility(IsVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
    }
}

void USTULevelItemWidget::SetLevelData(FLevelData NewLevelData)
{
    CurrentLevelData = NewLevelData;

    if (LevelName)
    {
        LevelName->SetText(FText::FromName(NewLevelData.DisplayedLevelName));
    }

    if (LevelImage)
    {
        LevelImage->SetBrushFromSoftTexture(NewLevelData.LevelThumb);
    }
}

void USTULevelItemWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (SelectLevelButton)
    {
        SelectLevelButton->OnClicked.AddDynamic(this, &USTULevelItemWidget::OnLevelSelected);
    }
}

void USTULevelItemWidget::OnLevelSelected()
{
    OnLevelSelectedDelegate.Broadcast(CurrentLevelData);
}
