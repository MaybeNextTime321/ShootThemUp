// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBaseWeaponActor.generated.h"
class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct FAmmoData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    int32 Bullet;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    int32 Clips;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    bool Infinite;
};

UCLASS() class SHOOTTHEMUP_API ASTUBaseWeaponActor : public AActor
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

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    float ShootTimer = 0.1f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    float HalfRad = 1.5f;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FAmmoData DefaultAmmo{15, 10, false};

    virtual void BeginPlay() override;

  public:
    virtual void StartFire();
    virtual void EndFire();
    virtual void MakeShoot();
    virtual void DestructWeapon();
    bool MakeHit(FVector &TraceStart, FVector &TraceEnd, FHitResult &HitResult);

  protected:
    bool GetPlayerViewPoint(FVector &Location, FRotator &Rotation);
    FVector GetSoketLocation();
    virtual bool GetTraceData(FVector &TraceStart, FVector &SoketForward, FVector &TraceEnd);
    void DecreaseAmmo();
    bool IsAmmoEmpty();
    bool IsClipEmpty();
    void LogAmmo();
    void ChangeClip();

  private:
    FAmmoData CurrentAmmo;
};
