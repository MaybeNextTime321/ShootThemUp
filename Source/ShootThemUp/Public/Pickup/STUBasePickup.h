// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBasePickup.generated.h"

class USphereComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBasePickup : public AActor
{
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    ASTUBasePickup();

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    USphereComponent *CollisionComponent;
    virtual void NotifyActorBeginOverlap(AActor *OtherActor) override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float RespawnTime = 5.0f;

    virtual bool GivePickupTo(APawn *PlayerPawn);

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    private:
    void PickupWasTaken();
    void RespawnPickup();
    void GenerateYAW();
    float RotationYAW = 2.0f;
};
