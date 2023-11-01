// Shoot Them Up. Project from Udemy course

#include "Weapon/STURiffleWeaponActor.h"
#include <DrawDebugHelpers.h>
#include <STUBaseCharacter.h>
#include <STUBaseWeaponActor.h>
#include "Weapon/Components/STUWeaponFXComponent.h"
#include <Kismet/GameplayStatics.h>

DEFINE_LOG_CATEGORY_STATIC(RiffleWeaponLog, All, All)
void ASTURiffleWeaponActor::StartFire()
{
    SetMuzzleVisibility(true);
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ASTURiffleWeaponActor::MakeShoot, ShootTimer, true);
    MakeShoot();
}

void ASTURiffleWeaponActor::EndFire()
{
    SetMuzzleVisibility(false);
    GetWorldTimerManager().ClearTimer(TimerHandle);
}

void ASTURiffleWeaponActor::MakeShoot()
{
    if (IsAmmoEmpty())
        return;
    DecreaseAmmo();
    FVector LineStart, SoketForward, LineEnd;

    GetTraceData(LineStart, SoketForward, LineEnd);

    FHitResult HitResult;
    MakeHit(LineStart, LineEnd, HitResult);

    if (HitResult.bBlockingHit)
    {

        WeaponFXComponent->PlayImpactFX(HitResult);
        if (IsValid(HitResult.GetActor()))
        {
            MakeHitWithDamage(HitResult);
        }
    }
    else
    {
        DrawDebugLine(GetWorld(), GetSoketLocation(), LineEnd, FColor::Blue, false, 3.0f, 0, 3.0f);
    }
}

ASTURiffleWeaponActor::ASTURiffleWeaponActor()
{
    WeaponFXComponent = CreateDefaultSubobject<USTUWeaponFXComponent>("WeaponFXComponent");
}

void ASTURiffleWeaponActor::BeginPlay()
{
    Super::BeginPlay();

    if (MuzzleFlash)
    {
        MuzzleFlashComponent = UGameplayStatics::SpawnEmitterAttached(MuzzleFlash,         //
                                                                                          SkeletalMesh,        //
                                                                                          MuzzleSoketName,     //
                                                                                          FVector::ZeroVector, //
                                                                                          FRotator::ZeroRotator);
    }
    //SetMuzzleVisibility(false);

    check(WeaponFXComponent);
}

bool ASTURiffleWeaponActor::GetTraceData(FVector &TraceStart, FVector &SoketForward, FVector &TraceEnd)
{
    FVector Location;
    FRotator Rotation;

    GetPlayerViewPoint(Location, Rotation);

    TraceStart = Location;

    const auto ConeHalfRad = FMath::DegreesToRadians(HalfRad);
    SoketForward = FMath::VRandCone(Rotation.Vector(), ConeHalfRad);
    TraceEnd = TraceStart + SoketForward * ShootDistance;
    return true;
}

void ASTURiffleWeaponActor::SetMuzzleVisibility(bool IsVisible)
{
    if (!MuzzleFlashComponent)
    {
        UE_LOG(RiffleWeaponLog, Warning, TEXT("Invalid Muzzle Flash Component"));
    }

    MuzzleFlashComponent->SetVisibility(IsVisible);
}

void ASTURiffleWeaponActor::MakeHitWithDamage(FHitResult HitResult)
{
    ASTUBaseCharacter *Character = Cast<ASTUBaseCharacter>(HitResult.GetActor());
    if (!Character)
        return;
    Character->TakeDamage(DamageValue, FDamageEvent{}, Character->Controller, GetOwner());
}
