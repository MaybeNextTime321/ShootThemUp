// Shoot Them Up. Project from Udemy course

#include "UI/STUGameOverWidget.h"
#include "UI/STUSingleStatWidget.h"
#include "STUGameModeBase.h"
#include "Player/STUPlayerState.h"
#include "STUUtils.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void USTUGameOverWidget::NativeOnInitialized()
{
    
    Super::NativeOnInitialized();

    if (GetWorld() && GetWorld()->GetAuthGameMode())
    {
        const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnChangeMathStateDelegate.AddUObject(this, &USTUGameOverWidget::OnMathStateChange);
        }
    }
    if (ResetLevelButton)
    {
        ResetLevelButton->OnClicked.AddDynamic(this, &USTUGameOverWidget::OnLevelReset);
    }

}

void USTUGameOverWidget::OnLevelReset()
{
    const auto LevelName = UGameplayStatics::GetCurrentLevelName(this);
    UGameplayStatics::OpenLevel(this, FName(LevelName));
}

void USTUGameOverWidget::OnMathStateChange(ESTUMathState NewMatchState)
{
    if (NewMatchState == ESTUMathState::GameOver)
    {
        UpdatePlayerState();
    }
}

void USTUGameOverWidget::UpdatePlayerState()
{
    if (!GetWorld() || !PlayerStatBox)
    {
        return;
    }


    PlayerStatBox->ClearChildren();


    for (auto it = GetWorld()->GetControllerIterator(); it; ++it)
    {
        const auto Controller = it->Get();
        if (!Controller)
        {
            continue;
        }
  
        const auto PlayerState = Cast<ASTUPlayerState>(Controller->PlayerState);

        if (!PlayerState)
        {
            continue;
        }

        const auto Row = CreateWidget<USTUSingleStatWidget>(GetWorld(), PlayerStatRow);

        if (!Row)
        {
            continue;
        }

        Row->SetPlayerName(FText::FromString(PlayerState->GetPlayerName()));
        Row->SetPlayerKills(STUUtils::TextFromInt(PlayerState->GetKills()));
        Row->SetPlayerDeath(STUUtils::TextFromInt(PlayerState->GetDeath()));
        Row->SetPlayerTeam(STUUtils::TextFromInt(PlayerState->GetTeamNumber()));
        Row->SetPlayerImageVisibility(Controller->IsPlayerController());
        Row->SetPlayerImageColor(PlayerState->GetPlayerColor().ToFColor(true));
        PlayerStatBox->AddChild(Row);
    }
}
