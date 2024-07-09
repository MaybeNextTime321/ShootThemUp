// Shoot Them Up. Project from Udemy course


#include "UI/STUHealthWidget.h"
#include "Components/ProgressBar.h"

void USTUHealthWidget::SetProgress(float ProgressValue)
{
    if (!HealthProgressBar)
    {
        return;
    }

    const auto DisplayProgressBar = (ProgressValue <= PersentForVisibility) && !FMath::IsNearlyZero(ProgressValue);
    HealthProgressBar->SetVisibility(DisplayProgressBar ? ESlateVisibility::Visible : ESlateVisibility::Hidden);


    const auto ProgressBarColor = (ProgressValue <= PersentForBadColor) ? BadColor : GoodColor;
    HealthProgressBar->SetFillColorAndOpacity(ProgressBarColor);

    HealthProgressBar->SetPercent(ProgressValue);
}
