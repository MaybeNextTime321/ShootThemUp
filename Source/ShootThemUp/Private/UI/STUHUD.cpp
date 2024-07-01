// Shoot Them Up. Project from Udemy course

#include "UI/STUHUD.h"
#include "Blueprint/UserWidget.h"
#include "STUGameModeBase.h"
#include "Engine/Canvas.h"

DEFINE_LOG_CATEGORY_STATIC(LogHUD, All, All)

void ASTUHUD::DrawHUD()
{

    Super::DrawHUD();
    // DrawAim();
}

void ASTUHUD::BeginPlay()
{
    Super::BeginPlay();
    UUserWidget *PlayerHUDWidget = CreateWidget(GetWorld(), PlayerHUD);
    if (PlayerHUDWidget)
        PlayerHUDWidget->AddToViewport();


    if (!GetWorld())
    {
        return;
    }

    const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());

    if (!GameMode)
    {
        return;
    }
    
    GameMode->OnChangeMathStateDelegate.AddUObject(this, &ASTUHUD::MathStateUpated);
 }

void ASTUHUD::MathStateUpated(ESTUMathState NewState)
 {
    UE_LOG(LogHUD, Display, TEXT("New Match State is %s"), *UEnum::GetValueAsString(NewState));
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
