// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUSphereDamageActor.generated.h"

UCLASS()
class SHOOTTHEMUP_API ASTUSphereDamageActor : public AActor
{
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    ASTUSphereDamageActor();

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    USceneComponent *SceneComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ApplyAllDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Radius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FColor SphereColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Damage;
};
