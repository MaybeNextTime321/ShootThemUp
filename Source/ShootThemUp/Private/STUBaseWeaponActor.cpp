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

void ASTUBaseWeaponActor::Fire()
{
    MakeShoot();
}

void ASTUBaseWeaponActor::MakeShoot()
{

    FVector LineStart, SoketForward, LineEnd;

    GetTraceData(LineStart, SoketForward, LineEnd);

    FHitResult HitResult;
    MakeHit(LineStart, LineEnd, HitResult);

    if (HitResult.bBlockingHit)
    {
        DrawDebugLine(GetWorld(), GetSoketLocation(), HitResult.ImpactPoint, FColor::Blue, false, 3.0f, 0, 3.0f);
        DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 3.0f, 0, 3.0f);

        if (HitResult.Actor.IsValid())
        {
            MakeHit(HitResult);
        }
    }
    else
    {
        DrawDebugLine(GetWorld(), GetSoketLocation(), LineEnd, FColor::Blue, false, 3.0f, 0, 3.0f);
    }
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

void ASTUBaseWeaponActor::MakeHit(FHitResult HitResult)
{
    ASTUBaseCharacter *Character = Cast<ASTUBaseCharacter>(HitResult.Actor);
    if (!Character)
        return;
    Character->TakeDamage(DamageValue, FDamageEvent{}, Character->Controller, GetOwner());
}
