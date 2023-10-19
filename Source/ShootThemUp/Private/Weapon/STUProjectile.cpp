// Shoot Them Up. Project from Udemy course

#include "Weapon/STUProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include <DrawDebugHelpers.h>
#include "Weapon/Components/STUWeaponFXComponent.h"


ASTUProjectile::ASTUProjectile()
{

    PrimaryActorTick.bCanEverTick = false;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(5.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
    SetRootComponent(CollisionComponent);

    MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
    MovementComponent->InitialSpeed = 2000.0f;
    MovementComponent->ProjectileGravityScale = 1.0f;

    WeaponFXComponent = CreateDefaultSubobject<USTUWeaponFXComponent>("WeaponFXComponent");
}

void ASTUProjectile::BeginPlay()
{
    Super::BeginPlay();
    MovementComponent->Velocity = ShootVector * MovementComponent->InitialSpeed;

    CollisionComponent->OnComponentHit.AddDynamic(this, &ASTUProjectile::OnHit);
    SetLifeSpan(LiveSpan);

    check(WeaponFXComponent);
}

void ASTUProjectile::OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp,
                           FVector NormalImpulse, const FHitResult &Hit)
{
    MovementComponent->StopMovementImmediately();
    UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), SphereRadius,
                                        UDamageType::StaticClass(), {GetOwner()}, this, nullptr, ApplyAllDamage);
    WeaponFXComponent->PlayImpactFX(Hit);
    Destroy();
    DrawDebugSphere(GetWorld(), GetActorLocation(), SphereRadius, 30, FColor::Red, ApplyAllDamage, LiveSpan);
}

AController *ASTUProjectile::GetController() const
{
    APawn *Pawn = Cast<APawn>(GetOwner());

    return Pawn ? Pawn->GetController() : nullptr;
}
