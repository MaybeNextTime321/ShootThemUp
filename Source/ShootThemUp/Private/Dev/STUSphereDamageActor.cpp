// Shoot Them Up. Project from Udemy course

#include "Dev/STUSphereDamageActor.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASTUSphereDamageActor::ASTUSphereDamageActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
    SceneComponent->AttachTo(GetRootComponent());
}

// Called when the game starts or when spawned
void ASTUSphereDamageActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ASTUSphereDamageActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 30, SphereColor, ApplyAllDamage);
    UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), Radius, nullptr, {}, this, nullptr,
                                        ApplyAllDamage);
}
