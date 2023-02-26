// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUProjectile : public AActor
{
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    ASTUProjectile();
    void SetShootDirection(const FVector &Direction)
    {

        ShootVector = Direction;
    }

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
    UProjectileMovementComponent *MovementComponent;

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

  public:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    USphereComponent *CollisionComponent;

  private:
    FVector ShootVector;
};
