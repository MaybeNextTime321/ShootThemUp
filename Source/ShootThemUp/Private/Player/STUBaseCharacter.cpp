// Shoot Them Up. Project from Udemy course

#include "Player/STUBaseCharacter.h"
#include "Camera/CameraComponent.h"
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
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need
    // it.
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
    SpringArmComp->bUsePawnControlRotation = true;
    SpringArmComp->SetupAttachment(GetRootComponent());
    SpringArmComp->SocketOffset = FVector(0.0f, 100.0f, 80.0f);

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
    CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

    UCharacterMovementComponent *MovementComponent = ASTUBaseCharacter::GetCharacterMovement();

    HealthComponent = CreateDefaultSubobject<USTUHealthComponent>("HealthComponent");

    TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComponent");
    TextRenderComponent->SetupAttachment(GetRootComponent());
    TextRenderComponent->SetOwnerNoSee(true);

    WeaponComponent = CreateDefaultSubobject<USTUWeaponComponent>("WeaponComponent");
}

// Called when the game starts or when spawned
void ASTUBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
    OnHealthChange(HealthComponent->GetHealth());
    HealthComponent->OnDead.AddUObject(this, &ASTUBaseCharacter::CharacterIsDead);
    HealthComponent->OnHealthChange.AddUObject(this, &ASTUBaseCharacter::OnHealthChange);
    LandedDelegate.AddDynamic(this, &ASTUBaseCharacter::OnGroupned);
}

// Called every frame
void ASTUBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASTUBaseCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASTUBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASTUBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ASTUBaseCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("LookAround", this, &ASTUBaseCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASTUBaseCharacter::Jump);
    PlayerInputComponent->BindAction("Shift is Pressed", IE_Pressed, this, &ASTUBaseCharacter::SetShiftValue);
    PlayerInputComponent->BindAction("Shift is Pressed", IE_Released, this, &ASTUBaseCharacter::SetShiftValue);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &USTUWeaponComponent::StartFire);
    PlayerInputComponent->BindAction("Fire", IE_Released, WeaponComponent, &USTUWeaponComponent::EndFire);
    PlayerInputComponent->BindAction("NextWeapon", IE_Pressed, WeaponComponent, &USTUWeaponComponent::NextWeapon);
    PlayerInputComponent->BindAction("Reload", IE_Pressed, WeaponComponent, &USTUWeaponComponent::Reload);
}

bool ASTUBaseCharacter::IsRunning() const
{
    return (!GetVelocity().IsZero()) && ShiftIsPressed && IsMoveForward;
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

void ASTUBaseCharacter::OnHealthChange(float HP)
{
    TextRenderComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), HP)));
}

void ASTUBaseCharacter::CharacterIsDead()
{
    PlayAnimMontage(AnimMontage);
    GetCharacterMovement()->DisableMovement();
    Controller->ChangeState(NAME_Spectating);
    SetLifeSpan(5.0f);
    GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    WeaponComponent->DestuctWeapon();
}

void ASTUBaseCharacter::MoveForward(float Amount)
{
    IsMoveForward = Amount > 0.0f;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ASTUBaseCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void ASTUBaseCharacter::SetShiftValue()
{

    ShiftIsPressed = !ShiftIsPressed;
}

void ASTUBaseCharacter::OnGroupned(const FHitResult &Hit)
{
    float Velocity = -GetVelocity().Z;

    if (Velocity <= LandedDamageVelocity.X)
        return;

    float FinalDamage = FMath::GetMappedRangeValueClamped(LandedDamageVelocity, LandedDamage, Velocity);
    TakeDamage(FinalDamage, FDamageEvent{}, nullptr, nullptr);
}
