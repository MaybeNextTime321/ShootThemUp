#pragma once
#include "STUCoreTypes.generated.h"

class ASTUBaseWeaponActor;
class UNiagaraSystem;
// weapon
DECLARE_MULTICAST_DELEGATE_OneParam(FOnClipEmptySignature, ASTUBaseWeaponActor *)

    USTRUCT(BlueprintType) struct FAmmoData
{
  public:
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    int32 Bullet;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    int32 Clips;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    bool Infinite;
};

USTRUCT(BlueprintType)
struct FWeaponData
{
    GENERATED_USTRUCT_BODY()

  public:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<ASTUBaseWeaponActor> WeaponClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon");
    UAnimMontage *ReloadMontage;
};

// health
DECLARE_MULTICAST_DELEGATE(FOnDeadSignature)
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnTakeDamageSignature, float, float)

    // ui

    USTRUCT(BlueprintType) struct FWeaponUIData
{
    GENERATED_USTRUCT_BODY()

  public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    UTexture2D *CrossImage;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    UTexture2D *DefaultImage;
};

// vfx
USTRUCT(BlueprintType) struct FDecalData
{
    GENERATED_USTRUCT_BODY()

  public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    UMaterial *DecalMaterial;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    FVector DecalSize = FVector(10.0f);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    float LiveTime = 5.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    float FadeTime = 2.0f;
};

USTRUCT(BlueprintType) struct FImpactData
{
    GENERATED_USTRUCT_BODY()

  public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Impact")
    UNiagaraSystem *NiagaraSystem;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    FDecalData DecalImpact;
};

USTRUCT(BlueprintType) struct FGameData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game", meta = (ClampMin = 0, ClampMax = 100))
    int32 NumberOfPlayers = 4;
};