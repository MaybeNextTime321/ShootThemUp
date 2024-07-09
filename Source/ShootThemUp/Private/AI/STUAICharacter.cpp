// Shoot Them Up. Project from Udemy course

#include "AI/STUAICharacter.h"
#include "AI/STUAIController.h"
#include "BrainComponent.h"
#include "Components/STUWeaponAIComponent.h"
#include "Components/WidgetComponent.h"
#include "UI/STUHealthWidget.h"
#include "Components/STUHealthComponent.h"
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

    UserHealthWidget = CreateDefaultSubobject<UWidgetComponent>("HealthWidget");
    UserHealthWidget->SetupAttachment(GetRootComponent());
    UserHealthWidget->SetWidgetSpace(EWidgetSpace::Screen);
}

void ASTUAICharacter::OnHealthChange(float HP, float HPDelta)
{
    Super::OnHealthChange(HP, HPDelta);

    const auto Widget = Cast<USTUHealthWidget>(UserHealthWidget->GetWidget());

    if (!Widget)
    {
        return;
    }

    Widget->SetProgress(HealthComponent->GetHealthProcent());
}

void ASTUAICharacter::BeginPlay()
{
    Super::BeginPlay();
    check(UserHealthWidget);
}

void ASTUAICharacter::CharacterIsDead()
{
    Super::CharacterIsDead();

    const auto STUController = Cast<AAIController>(Controller);

    if (STUController && STUController->BrainComponent)
    {
        STUController->BrainComponent->Cleanup();
    }
}
