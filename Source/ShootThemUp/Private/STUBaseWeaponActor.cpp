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
    if (ClipsEsEmpty())
        return;

    --CurrentAmmo.Bullet;
    LogAmmo();

    if (IsClipEmpty() && !IsAmmoEmpty())
    {
        EndFire();
        OnClipEmpty.Broadcast();
    }
}

bool ASTUBaseWeaponActor::IsAmmoEmpty()
{

    return (!CurrentAmmo.Infinite && CurrentAmmo.Clips == 0 && CurrentAmmo.Bullet == 0);
}

bool ASTUBaseWeaponActor::IsClipEmpty()
{
    return CurrentAmmo.Bullet == 0;
}

void ASTUBaseWeaponActor::LogAmmo()
{
    FString ShowAmmo = "Ammo: " + FString::FromInt(CurrentAmmo.Bullet) + " / ";
    ShowAmmo += CurrentAmmo.Infinite ? "Infinite" : FString::FromInt(CurrentAmmo.Clips) + " Clips";
    UE_LOG(BaseWeaponLog, Display, TEXT("%s"), *ShowAmmo);
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

bool ASTUBaseWeaponActor::MakeHit(FVector &TraceStart, FVector &TraceEnd, FHitResult &HitResult)
{

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());

    GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility,
                                         CollisionParams);
    return true;
}