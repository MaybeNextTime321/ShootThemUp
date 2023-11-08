// Shoot Them Up. Project from Udemy course

#include "AI/STUAICharacter.h"
#include "AI/STUAIController.h"
#include "Components/STUWeaponAIComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASTUAICharacter::ASTUAICharacter(const FObjectInitializer &ObjInit)
    : Super(ObjInit.SetDefaultSubobjectClass<USTUWeaponAIComponent>("WeaponComponent"))
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = ASTUAIController::StaticClass();

    bUseControllerRotationYaw = false;

    if (GetCharacterMovement())
    {
        GetCharacterMovement()->bUseControllerDesiredRotation = true;
        GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
    }
}
