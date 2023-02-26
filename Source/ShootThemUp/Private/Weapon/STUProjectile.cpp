// Shoot Them Up. Project from Udemy course

#include "Weapon/STUProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ASTUProjectile::ASTUProjectile()
{

    PrimaryActorTick.bCanEverTick = false;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(5.0f);
    SetRootComponent(CollisionComponent);

    MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
    MovementComponent->InitialSpeed = 2000.0f;
    MovementComponent->ProjectileGravityScale = 1.0f;
}

void ASTUProjectile::BeginPlay()
{
    Super::BeginPlay();
    MovementComponent->Velocity = ShootVector * MovementComponent->InitialSpeed;
    SetLifeSpan(5.0f);
}
