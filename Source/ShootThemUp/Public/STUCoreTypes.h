#pragma once
#include "STUCoreTypes.generated.h"

class ASTUBaseWeaponActor;

// weapon
DECLARE_MULTICAST_DELEGATE(FOnClipEmptySignature)

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
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTakeDamageSignature, float)

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