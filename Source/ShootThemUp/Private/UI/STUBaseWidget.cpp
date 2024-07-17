// Shoot Them Up. Project from Udemy course


#include "UI/STUBaseWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

void USTUBaseWidget::ShowAnimation()
{
	PlayAnimation(ShowAnim);
    UGameplayStatics::PlaySound2D(GetWorld(), ShowWidgetSound);
}
