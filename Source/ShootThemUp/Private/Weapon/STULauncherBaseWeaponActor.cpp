// Shoot Them Up. Project from Udemy course

#include "Weapon/STULauncherBaseWeaponActor.h"
#include "Weapon/STUProjectile.h"
#include <Kismet/GameplayStatics.h>

void ASTULauncherBaseWeaponActor::StartFire()
{

    MakeShoot();
}

void ASTULauncherBaseWeaponActor::MakeShoot()
{
    if (IsAmmoEmpty())
        return;
    DecreaseAmmo();
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
        if (MuzzleFlash)
        {
            UParticleSystemComponent *ParticleSystem = UGameplayStatics::SpawnEmitterAttached(MuzzleFlash,         //
                                                                                              SkeletalMesh,        //
                                                                                              MuzzleSoketName,     //
                                                                                              FVector::ZeroVector, //
                                                                                              FRotator::ZeroRotator);
        }
        Projectile->SetShootDirection(Direction);
        Projectile->SetOwner(GetOwner());
        Projectile->FinishSpawning(SpawnTransform);
    }
}
