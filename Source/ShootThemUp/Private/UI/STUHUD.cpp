// Shoot Them Up. Project from Udemy course

#include "UI/STUHUD.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Canvas.h"

void ASTUHUD::DrawHUD()
{

    Super::DrawHUD();
    DrawAim();
}

void ASTUHUD::BeginPlay()
{
    Super::BeginPlay();
    UUserWidget *PlayerHUDWidget = CreateWidget(GetWorld(), PlayerHUD);
    if (PlayerHUDWidget)
        PlayerHUDWidget->AddToViewport();
}

void ASTUHUD::DrawAim()
{
    float CenterX = 0.0f;
    float CenterY = 0.0f;
    float HalfLineSize = 15.0f;
    float LineThickness = 2.0f;
    Canvas->GetCenter(CenterX, CenterY);
    DrawLine(CenterX - HalfLineSize, CenterY, CenterX + HalfLineSize, CenterY, FLinearColor::Green, LineThickness);
    DrawLine(CenterX, CenterY - HalfLineSize, CenterX, CenterY + HalfLineSize, FLinearColor::Green, LineThickness);
}
