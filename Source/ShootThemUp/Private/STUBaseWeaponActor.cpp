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
    CurrentAmmo = DefaultAmmo;
    check(SkeletalMesh);
    checkf(DefaultAmmo.Bullet > 0, TEXT("Default Ammo Bullet must be > 0"));
    checkf(DefaultAmmo.Clips > 0, TEXT("Default Ammo Clips must be > 0"));
}

void ASTUBaseWeaponActor::StartFire()
{
}

FAmmoData ASTUBaseWeaponActor::GetAmmoData() const
{
    return CurrentAmmo;
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

void ASTUBaseWeaponActor::DecreaseAmmo()
{
    if (ClipsEsEmpty() && IsAmmoEmpty())
        return;

    --CurrentAmmo.Bullet;

    if (IsClipEmpty() && !IsAmmoEmpty())
    {
        EndFire();
        OnClipEmpty.Broadcast(this);
    }
}

bool ASTUBaseWeaponActor::IsAmmoEmpty()
{

    return (!CurrentAmmo.Infinite && CurrentAmmo.Clips == 0 && //
        CurrentAmmo.Bullet == 0);
}

bool ASTUBaseWeaponActor::IsAmmoFull()
{
    return (CurrentAmmo.Bullet == DefaultAmmo.Bullet && //
        CurrentAmmo.Clips == DefaultAmmo.Clips);
}

bool ASTUBaseWeaponActor::IsClipEmpty()
{
    return CurrentAmmo.Bullet == 0;
}

bool ASTUBaseWeaponActor::ClipsEsEmpty()
{
    if (CurrentAmmo.Clips == 0)
    {
        UE_LOG(BaseWeaponLog, Display, TEXT("No More Clips"))
        return true;
    }
    return false;
}

void ASTUBaseWeaponActor::ChangeClip()
{
    if (!CurrentAmmo.Infinite)
    {
        if (ClipsEsEmpty())
            return;
    }
    --CurrentAmmo.Clips;
    CurrentAmmo.Bullet = DefaultAmmo.Bullet;
}

bool ASTUBaseWeaponActor::CanReload() const
{
    return CurrentAmmo.Bullet < DefaultAmmo.Bullet && CurrentAmmo.Clips > 0;
}

FWeaponUIData ASTUBaseWeaponActor::GetUIData() const
{

    return WeaponUI;
}

void ASTUBaseWeaponActor::AddAmmo(int32 ClipsAmount)
{
    if (CurrentAmmo.Infinite || IsAmmoFull() || ClipsAmount <= 0)
    {
        return;
    }

    if (IsAmmoEmpty())
    {
        CurrentAmmo.Clips = FMath::Clamp(ClipsAmount, 0, DefaultAmmo.Clips);
        OnClipEmpty.Broadcast(this);
    }
    else if (CurrentAmmo.Clips < DefaultAmmo.Clips)
    {
        const auto NextClipAmount = CurrentAmmo.Clips + ClipsAmount;

        if (DefaultAmmo.Clips - NextClipAmount >= 0)
        {
            CurrentAmmo.Clips = NextClipAmount;
        }
        else
        {
            CurrentAmmo.Bullet = DefaultAmmo.Bullet;
            CurrentAmmo.Clips = DefaultAmmo.Clips;
        }
    }
    else
    {
        CurrentAmmo.Bullet = DefaultAmmo.Bullet;
    }
}

bool ASTUBaseWeaponActor::MakeHit(FVector &TraceStart, FVector &TraceEnd, FHitResult &HitResult)
{

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());
    CollisionParams.bReturnPhysicalMaterial = true;
    GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility,
                                         CollisionParams);
    return true;
}