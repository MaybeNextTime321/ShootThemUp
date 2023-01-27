// Shoot Them Up. Project from Udemy course

#include "Components/STUCharacterMovementComponent.h"
#include "Player/STUBaseCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const
{
    ASTUBaseCharacter *Player = Cast<ASTUBaseCharacter>(GetPawnOwner());
    const float MaxSpeed = Super::GetMaxSpeed();

    return Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}
