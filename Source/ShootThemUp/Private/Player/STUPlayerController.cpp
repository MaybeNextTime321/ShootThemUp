// Shoot Them Up. Project from Udemy course


#include "Player/STUPlayerController.h"
#include "Components/STURespawnComponent.h"
#include "STUGameInstance.h"
#include "STUGameModeBase.h"

ASTUPlayerController::ASTUPlayerController()
{
    RespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("RespawnComponent");
}

void ASTUPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (InputComponent)
    {
        InputComponent->BindAction("Pause", EInputEvent::IE_Pressed, this, &ASTUPlayerController::PauseGame);
        InputComponent->BindAction("Mute", EInputEvent::IE_Pressed, this, &ASTUPlayerController::ToggleSound);
    }
}

void ASTUPlayerController::BeginPlay()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode())
    {
        return;
    }

    const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());

    if (GameMode)
    {
        GameMode->OnChangeMathStateDelegate.AddUObject(this, &ASTUPlayerController::ChangeMatchState);
    }
}

void ASTUPlayerController::PauseGame()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode())
    {
        return;
    }

    const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());

    if (GameMode)
    {
        GameMode->PauseGame(this);
    }
}

void ASTUPlayerController::ToggleSound()
{
    const auto GameInstance = Cast<USTUGameInstance>(GetGameInstance());
    if (GameInstance)
    {
        GameInstance->ToggleGameSound();
    }
}

void ASTUPlayerController::ChangeMatchState(ESTUMathState NewState)
{
    if (NewState == ESTUMathState::InProgress)
    {
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
    else
    {
        SetInputMode(FInputModeUIOnly());
        bShowMouseCursor = true;
    }
}
