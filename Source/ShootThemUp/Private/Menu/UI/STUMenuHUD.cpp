// Shoot Them Up. Project from Udemy course


#include "Menu/UI/STUMenuHUD.h"
#include "Blueprint/UserWidget.h"

void ASTUMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (!MenuHUD)
    {
        return;
    }

    const auto Widget = CreateWidget(GetWorld(), MenuHUD);

    if (!Widget)
    {
        return;
    }

    Widget->AddToViewport();
}
