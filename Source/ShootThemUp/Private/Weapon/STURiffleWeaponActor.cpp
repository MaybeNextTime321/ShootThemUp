// Shoot Them Up. Project from Udemy course

#include "Weapon/STURiffleWeaponActor.h"
#include <DrawDebugHelpers.h>
#include <STUBaseCharacter.h>
#include <STUBaseWeaponActor.h>
#include "Weapon/Components/STUWeaponFXComponent.h"
#include <Kismet/GameplayStatics.h>
#include <NiagaraComponent.h>
#include <NiagaraFunctionLibrary.h>
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"

DEFINE_LOG_CATEGORY_STATIC(RiffleWeaponLog, All, All)
void ASTURiffleWeaponActor::StartFire()
{
    SetVFXVisibility(true);
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ASTURiffleWeaponActor::MakeShoot, ShootTimer, true);
    MakeShoot();
}

void ASTURiffleWeaponActor::EndFire()
{
    SetVFXVisibility(false);
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

    FVector TraceEndPoint = LineEnd;



    if (HitResult.bBlockingHit)
    {
        WeaponFXComponent->PlayImpactFX(HitResult);
        if (IsValid(HitResult.GetActor()))
        {
            TraceEndPoint = HitResult.ImpactPoint;
            MakeHitWithDamage(HitResult);
        }
    }

    SpawnTraceAtLocation(GetSoketLocation(), TraceEndPoint);
    
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
    if (FireSound)
    {
        FireAudioComponent = UGameplayStatics::SpawnSoundAttached(FireSound, SkeletalMesh, MuzzleSoketName);
    }

    SetVFXVisibility(false);

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

void ASTURiffleWeaponActor::SpawnTraceAtLocation(const FVector &StartLocation, const FVector &EndLocation)
{
    if (TraceNiagaraSystem)
    {
        const auto NiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), TraceNiagaraSystem, StartLocation);
        if (NiagaraComponent)
        {
            NiagaraComponent->SetNiagaraVariableVec3(TraceTargetName,EndLocation);
        }
    }
}

void ASTURiffleWeaponActor::SetVFXVisibility(bool IsActive)
{
    if (!MuzzleFlashComponent)
    {
        UE_LOG(RiffleWeaponLog, Warning, TEXT("Invalid Muzzle Flash Component"));
    }

    MuzzleFlashComponent->SetVisibility(IsActive);

    if (FireAudioComponent)
    {
        IsActive ? FireAudioComponent->Play() : FireAudioComponent->Stop();
    }
}

void ASTURiffleWeaponActor::MakeHitWithDamage(FHitResult HitResult)
{
    ASTUBaseCharacter *Character = Cast<ASTUBaseCharacter>(HitResult.GetActor());
    if (!Character)
        return;
    Character->TakeDamage(DamageValue, FDamageEvent{}, GetController(), GetOwner());
}


AController *ASTURiffleWeaponActor::GetController() const
{
    APawn *Pawn = Cast<APawn>(GetOwner());

    return Pawn ? Pawn->GetController() : nullptr;
}