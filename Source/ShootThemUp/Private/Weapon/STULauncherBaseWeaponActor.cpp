// Shoot Them Up. Project from Udemy course

#include "Weapon/STULauncherBaseWeaponActor.h"
#include "Weapon/STUProjectile.h"

void ASTULauncherBaseWeaponActor::StartFire()
{
    MakeShoot();
}

void ASTULauncherBaseWeaponActor::MakeShoot()
{
    const FVector SoketLocation = GetSoketLocation();

    const FTransform SpawnTransform = FTransform(FRotator::ZeroRotator, SoketLocation);

    FVector LineStart, SoketForward, LineEnd;

    GetTraceData(LineStart, SoketForward, LineEnd);

    FHitResult HitResult;
    MakeHit(LineStart, LineEnd, HitResult);

    FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : LineEnd;
    FVector Direction = (EndPoint - SoketLocation).GetSafeNormal();

    ASTUProjectile *Projectile = GetWorld()->SpawnActorDeferred<ASTUProjectile>(ProjectileClass, SpawnTransform);
    if (Projectile)
    {
        Projectile->SetShootDirection(Direction);
        Projectile->FinishSpawning(SpawnTransform);
    }
}
