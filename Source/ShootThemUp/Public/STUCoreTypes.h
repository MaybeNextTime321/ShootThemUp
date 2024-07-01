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

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game", meta = (ClampMin = 0, ClampMax = 10))
    int32 NumberOfRounds = 3;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game", meta = (ClampMin = 3, ClampMax = 300))
    int32 RoundDurationInSecond = 3;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game", meta = (ClampMin = 3, ClampMax = 20))
    int32 RespawnTime = 5;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game", meta = (ClampMin = 3, ClampMax = 20))
    int32 MinimumTimerValueAfterRespawn = 5;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game")
    FLinearColor DefaultColor = FLinearColor::Red;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game")
    TArray<FLinearColor> TeamColors;
};

UENUM(BlueprintType)
enum class ESTUMathState: uint8
{
    WaitingToStart = 0,
    InProgress,
    InPause,
    GameOver
};
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeMathState, ESTUMathState);
