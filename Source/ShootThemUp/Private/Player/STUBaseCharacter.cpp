// Shoot Them Up. Project from Udemy course

#include "Player/STUBaseCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/STUCharacterMovementComponent.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

DEFINE_LOG_CATEGORY_STATIC(CharacterLog, All, All)

// Sets default values
ASTUBaseCharacter::ASTUBaseCharacter(const FObjectInitializer &ObjInit)
    : Super(
          ObjInit.SetDefaultSubobjectClass<USTUCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
    PrimaryActorTick.bCanEverTick = true;

    UCharacterMovementComponent *MovementComponent = ASTUBaseCharacter::GetCharacterMovement();

    HealthComponent = CreateDefaultSubobject<USTUHealthComponent>("HealthComponent");
    WeaponComponent = CreateDefaultSubobject<USTUWeaponComponent>("WeaponComponent");
}

// Called when the game starts or when spawned
void ASTUBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
    OnHealthChange(HealthComponent->GetHealth(), 0.0f);
    HealthComponent->OnDead.AddUObject(this, &ASTUBaseCharacter::CharacterIsDead);
    HealthComponent->OnHealthChange.AddUObject(this, &ASTUBaseCharacter::OnHealthChange);
    LandedDelegate.AddDynamic(this, &ASTUBaseCharacter::OnGroupned);
}

// Called every frame
void ASTUBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}


bool ASTUBaseCharacter::IsRunning() const
{
    return false;
}

float ASTUBaseCharacter::GetDegree()
{
    if (GetVelocity().IsZero())
        return 0.0f;
    FVector Velocity = GetVelocity().GetSafeNormal();
    FVector ForwardVector = GetActorForwardVector();
    float Angle = FMath::Acos(FVector::DotProduct(ForwardVector, Velocity));
    FVector CrossProduct = FVector::CrossProduct(ForwardVector, Velocity);
    float Degree = FMath::RadiansToDegrees(Angle);
    return Degree * FMath::Sign(CrossProduct.Z);
}

void ASTUBaseCharacter::SetColor(FLinearColor& Color)
{
    const auto MaterialInstance = GetMesh()->CreateAndSetMaterialInstanceDynamic(0);

    if (!MaterialInstance)
    {
        return;
    }

    MaterialInstance->SetVectorParameterValue(MaterialColorName, Color);
}

void ASTUBaseCharacter::OnHealthChange(float HP, float HPDelta)
{

}

void ASTUBaseCharacter::CharacterIsDead()
{
    GetCharacterMovement()->DisableMovement();
    Controller->ChangeState(NAME_Spectating);
    SetLifeSpan(5.0f);
    GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    WeaponComponent->DestuctWeapon();

    GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    GetMesh()->SetSimulatePhysics(true);
}

void ASTUBaseCharacter::OnGroupned(const FHitResult &Hit)
{
    float Velocity = -GetVelocity().Z;

    if (Velocity <= LandedDamageVelocity.X)
        return;

    float FinalDamage = FMath::GetMappedRangeValueClamped(LandedDamageVelocity, LandedDamage, Velocity);
    TakeDamage(FinalDamage, FDamageEvent{}, nullptr, nullptr);
}
