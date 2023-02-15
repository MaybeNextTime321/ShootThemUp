// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBaseWeaponActor.generated.h"

UCLASS()
class SHOOTTHEMUP_API ASTUBaseWeaponActor : public AActor
{
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    ASTUBaseWeaponActor();

  protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    USkeletalMeshComponent *SkeletalMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    float ShootDistance = 1500;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    float DamageValue = 10.0f;

    virtual void BeginPlay() override;

  public:
    virtual void Fire();
    void MakeShoot();
    virtual void DestructWeapon();

  private:
    bool GetPlayerViewPoint(FVector &Location, FRotator &Rotation);
    FVector GetSoketLocation();
    bool GetTraceData(FVector &TraceStart, FVector &SoketForward, FVector &TraceEnd);
    bool MakeHit(FVector &TraceStart, FVector &TraceEnd, FHitResult &HitResult);
    void MakeHit(FHitResult HitResult);
};
