// Shoot Them Up. Project from Udemy course

#pragma once

#include "STUCoreTypes.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "STUBaseWeaponActor.generated.h"

class USkeletalMeshComponent;

UCLASS() class SHOOTTHEMUP_API ASTUBaseWeaponActor : public AActor
{
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    ASTUBaseWeaponActor();
    FOnClipEmptySignature OnClipEmpty;

  protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    USkeletalMeshComponent *SkeletalMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    float ShootDistance = 5000;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    float DamageValue = 10.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    float ShootTimer = 0.1f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
    float HalfRad = 1.5f;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FAmmoData DefaultAmmo{15, 10, false};

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Particles")
    UParticleSystem *MuzzleFlash;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName MuzzleSoketName = "MuzzleSoket";

    virtual void BeginPlay() override;

  public:
    virtual void StartFire();
    FAmmoData GetAmmoData() const;
    virtual void EndFire();
    virtual void MakeShoot();
    virtual void DestructWeapon();
    bool MakeHit(FVector &TraceStart, FVector &TraceEnd, FHitResult &HitResult);
    void ChangeClip();
    bool CanReload() const;
    FWeaponUIData GetUIData() const;
    void AddAmmo(int32 ClipsAmount);
    bool IsAmmoEmpty();
    bool IsAmmoFull();

  protected:
    bool GetPlayerViewPoint(FVector &Location, FRotator &Rotation);
    FVector GetSoketLocation();
    virtual bool GetTraceData(FVector &TraceStart, FVector &SoketForward, FVector &TraceEnd);
    void DecreaseAmmo();
    bool IsClipEmpty();
    bool ClipsEsEmpty();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    FWeaponUIData WeaponUI;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    FAmmoData CurrentAmmo;
};
