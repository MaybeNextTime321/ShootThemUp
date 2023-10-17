// Shoot Them Up. Project from Udemy course

#include "Weapon/STURiffleWeaponActor.h"
#include <DrawDebugHelpers.h>
#include <STUBaseCharacter.h>
#include <STUBaseWeaponActor.h>

void ASTURiffleWeaponActor::StartFire()
{
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ASTURiffleWeaponActor::MakeShoot, ShootTimer, true);
    MakeShoot();
}

void ASTURiffleWeaponActor::EndFire()
{
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
        DrawDebugLine(GetWorld(), GetSoketLocation(), HitResult.ImpactPoint, FColor::Blue, false, 3.0f, 0, 3.0f);
        DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 3.0f, 0, 3.0f);

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

void ASTURiffleWeaponActor::MakeHitWithDamage(FHitResult HitResult)
{
    ASTUBaseCharacter *Character = Cast<ASTUBaseCharacter>(HitResult.GetActor());
    if (!Character)
        return;
    Character->TakeDamage(DamageValue, FDamageEvent{}, Character->Controller, GetOwner());
}
