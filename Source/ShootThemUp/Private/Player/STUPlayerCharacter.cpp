// Shoot Them Up. Project from Udemy course

#include "Player/STUPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/STUWeaponComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

ASTUPlayerCharacter::ASTUPlayerCharacter(const FObjectInitializer &ObjInit) : Super(ObjInit)
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
    SpringArmComp->bUsePawnControlRotation = true;
    SpringArmComp->SetupAttachment(GetRootComponent());
    SpringArmComp->SocketOffset = FVector(0.0f, 100.0f, 80.0f);

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
    CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

    CameraSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CameraSphereComponent"));
    CameraSphereComponent->SetupAttachment(SpringArmComp);
    CameraSphereComponent->SetSphereRadius(10.0f);
    CameraSphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

void ASTUPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    CameraSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ASTUPlayerCharacter::CameraSphereBeginOverlap);
    CameraSphereComponent->OnComponentEndOverlap.AddDynamic(this, &ASTUPlayerCharacter::CameraSphereEndOverlap);
}

void ASTUPlayerCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASTUPlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASTUPlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ASTUPlayerCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("LookAround", this, &ASTUPlayerCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASTUPlayerCharacter::Jump);
    PlayerInputComponent->BindAction("Shift is Pressed", IE_Pressed, this, &ASTUPlayerCharacter::SetShiftValue);
    PlayerInputComponent->BindAction("Shift is Pressed", IE_Released, this, &ASTUPlayerCharacter::SetShiftValue);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &USTUWeaponComponent::StartFire);
    PlayerInputComponent->BindAction("Fire", IE_Released, WeaponComponent, &USTUWeaponComponent::EndFire);
    PlayerInputComponent->BindAction("NextWeapon", IE_Pressed, WeaponComponent, &USTUWeaponComponent::NextWeapon);
    PlayerInputComponent->BindAction("Reload", IE_Pressed, WeaponComponent, &USTUWeaponComponent::Reload);
}


bool ASTUPlayerCharacter::IsRunning() const
{
    return (!GetVelocity().IsZero()) && ShiftIsPressed && IsMoveForward;
}


void ASTUPlayerCharacter::MoveForward(float Amount)
{
    IsMoveForward = Amount > 0.0f;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ASTUPlayerCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void ASTUPlayerCharacter::SetShiftValue()
{

    ShiftIsPressed = !ShiftIsPressed;
}

void ASTUPlayerCharacter::CameraSphereBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
                                                   UPrimitiveComponent *OtherComp, int32 OtherBodyIndex,
                                                   bool bFromSweep, const FHitResult &SweepResult)
{
    CheckCameraOverlap();
}

void ASTUPlayerCharacter::CameraSphereEndOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
                                                 UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
    CheckCameraOverlap();
}

void ASTUPlayerCharacter::CheckCameraOverlap()
{
    const bool HideMesh = CameraSphereComponent->IsOverlappingComponent(GetCapsuleComponent());
    GetMesh()->SetOwnerNoSee(HideMesh);

    TArray<USceneComponent*> ChildrenComponents;

    GetMesh()->GetChildrenComponents(true, ChildrenComponents);

    for (auto item : ChildrenComponents)
    {
      const auto CastingItem = Cast<UPrimitiveComponent>(item);
        if (CastingItem)
        {
            CastingItem->SetOwnerNoSee(HideMesh);
        }
    }
}
