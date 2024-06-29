// Shoot Them Up. Project from Udemy course


#include "Player/STUPlayerController.h"
#include "Components/STURespawnComponent.h"
ASTUPlayerController::ASTUPlayerController()
{
    RespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("RespawnComponent");
}
