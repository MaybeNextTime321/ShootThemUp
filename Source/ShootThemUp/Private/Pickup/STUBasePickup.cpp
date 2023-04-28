// Shoot Them Up. Project from Udemy course

#include "Pickup/STUBasePickup.h"
#include "Components/SphereComponent.h"

DEFINE_LOG_CATEGORY_STATIC(PickupLog, All, All);
// Sets default values
ASTUBasePickup::ASTUBasePickup()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);
}

// Called when the game starts or when spawned
void ASTUBasePickup::BeginPlay()
{
    Super::BeginPlay();
}

void ASTUBasePickup::NotifyActorBeginOverlap(AActor *OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);
    UE_LOG(PickupLog, Display, TEXT("Pickup taken"));
    Destroy();
}

// Called every frame
void ASTUBasePickup::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}