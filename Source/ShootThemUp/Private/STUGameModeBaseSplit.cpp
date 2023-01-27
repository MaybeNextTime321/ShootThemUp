// Shoot Them Up. Project from Udemy course

#include "STUGameModeBaseSplit.h"
#include "Player/STUBaseCharacter.h"
#include "Player/STUPlayerController.h"

ASTUGameModeBaseSplit::ASTUGameModeBaseSplit()
{
    DefaultPawnClass = ASTUBaseCharacter::StaticClass();
    PlayerControllerClass = ASTUPlayerController::StaticClass();
}