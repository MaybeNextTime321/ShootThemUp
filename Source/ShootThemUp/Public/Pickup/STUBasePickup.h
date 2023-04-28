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

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
