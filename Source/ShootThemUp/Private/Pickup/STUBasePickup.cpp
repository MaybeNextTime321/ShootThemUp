// Shoot Them Up. Project from Udemy course

#include "Pickup/STUBasePickup.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

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
    GenerateYAW();
}

void ASTUBasePickup::NotifyActorBeginOverlap(AActor *OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    APawn *Pawn = Cast<APawn>(OtherActor);

    if (!Pawn)
    {
        return;
    }

    if (GivePickupTo(Pawn))
    {
        PickupWasTaken();
    }
}

bool ASTUBasePickup::GivePickupTo(APawn *PlayerPawn)
{
    return false;
}

// Called every frame
void ASTUBasePickup::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AddActorLocalRotation(FRotator(0, RotationYAW, 0));
}

bool ASTUBasePickup::CouldBeTaken() const
{
    return !GetWorldTimerManager().IsTimerActive(TimerHandle);
}

void ASTUBasePickup::PickupWasTaken()
{
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    GetRootComponent()->SetVisibility(false, true);
    UGameplayStatics::SpawnSoundAtLocation(GetWorld(), TakeSound, GetActorLocation());
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ASTUBasePickup::RespawnPickup, RespawnTime);
}

void ASTUBasePickup::RespawnPickup()
{
    GenerateYAW();
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    GetRootComponent()->SetVisibility(true, true);
}

void ASTUBasePickup::GenerateYAW()
{
    const auto Reverse = FMath::RandBool() ? 1 : -1;
    RotationYAW = FMath::RandRange(1.0f, 2.0f) * Reverse;
}
