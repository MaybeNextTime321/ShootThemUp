// Shoot Them Up. Project from Udemy course

#include "STUBaseWeaponActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "Player/STUBaseCharacter.h"

DEFINE_LOG_CATEGORY_STATIC(BaseWeaponLog, All, All)
// Sets default values
ASTUBaseWeaponActor::ASTUBaseWeaponActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SceletalMesh");
    SetRootComponent(SkeletalMesh);
}

// Called when the game starts or when spawned
void ASTUBaseWeaponActor::BeginPlay()
{
    Super::BeginPlay();
}

void ASTUBaseWeaponActor::StartFire()
{
}

void ASTUBaseWeaponActor::EndFire()
{
}

void ASTUBaseWeaponActor::MakeShoot()
{
}

void ASTUBaseWeaponActor::DestructWeapon()
{
    SetLifeSpan(5.0f);
}

bool ASTUBaseWeaponActor::GetPlayerViewPoint(FVector &Location, FRotator &Rotation)
{
    ACharacter *CharacterOwner = Cast<ACharacter>(GetOwner());
    CharacterOwner->Controller->GetPlayerViewPoint(Location, Rotation);
    return true;
}

FVector ASTUBaseWeaponActor::GetSoketLocation()
{
    return SkeletalMesh->GetSocketLocation("MuzzleSoket");
}

bool ASTUBaseWeaponActor::GetTraceData(FVector &TraceStart, FVector &SoketForward, FVector &TraceEnd)
{
    FVector Location;
    FRotator Rotation;

    GetPlayerViewPoint(Location, Rotation);

    TraceStart = Location;

    const auto ConeHalfRad = FMath::DegreesToRadians(HalfRad);
    SoketForward = Rotation.Vector();
    TraceEnd = TraceStart + SoketForward * ShootDistance;
    return true;
}
bool ASTUBaseWeaponActor::MakeHit(FVector &TraceStart, FVector &TraceEnd, FHitResult &HitResult)
{

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());

    GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility,
                                         CollisionParams);
    return true;
}