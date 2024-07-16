// Shoot Them Up. Project from Udemy course


#include "Menu/UI/STUMenuHUD.h"
#include "UI/STUBaseWidget.h"

void ASTUMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (!MenuHUD)
    {
        return;
    }

    const auto Widget = CreateWidget<USTUBaseWidget>(GetWorld(), MenuHUD);

    if (!Widget)
    {
        return;
    }

    Widget->AddToViewport();
    Widget->ShowAnimation();
}
