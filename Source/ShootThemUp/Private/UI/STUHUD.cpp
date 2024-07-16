// Shoot Them Up. Project from Udemy course

#include "UI/STUHUD.h"
#include "UI/STUBaseWidget.h"
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

    if (!GetWorld())
    {
        return;
    }

    MatchStateHUD.Add(ESTUMathState::InProgress, CreateWidget<USTUBaseWidget>(GetWorld(), PlayerHUD));
    MatchStateHUD.Add(ESTUMathState::InPause, CreateWidget<USTUBaseWidget>(GetWorld(), PauseHUD));
    MatchStateHUD.Add(ESTUMathState::GameOver, CreateWidget<USTUBaseWidget>(GetWorld(), GameOverHUD));

    for (const auto Widget : MatchStateHUD)
    {
        const auto HUD = Widget.Value;
        if (!HUD)
        {
            continue;
        }

        HUD->AddToViewport();
        HUD->SetVisibility(ESlateVisibility::Hidden);
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
    if (!MatchStateHUD.Contains(NewState))
    {
        return;
    }

    if (CurrenntWidget)
    {
        CurrenntWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    CurrenntWidget = MatchStateHUD[NewState];

    CurrenntWidget->SetVisibility(ESlateVisibility::Visible);
    CurrenntWidget->ShowAnimation();
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
