// Shoot Them Up. Project from Udemy course

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "STUWeaponComponent.generated.h"

class ASTUBaseWeaponActor;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    // Sets default values for this component's properties
    USTUWeaponComponent();
    void StartFire();
    void EndFire();
    void DestuctWeapon();
    void NextWeapon();

  protected:
    // Called when the game starts
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    FName WeaponEquipSoket = "WeaponPoint";

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    FName WeaponArmorySoket = "ArmorySocket";

    UPROPERTY()
    TArray<ASTUBaseWeaponActor *> Weapons;

    int32 CurrentWeaponIndex = 0;

    virtual void BeginPlay() override;
    void SpawnWeapons();

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<TSubclassOf<ASTUBaseWeaponActor>> WeaponClass;

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    UAnimMontage *EquipAnimMontage;

    UPROPERTY()
    ASTUBaseWeaponActor *CurrentWeapon;

    void AttachWeaponToSoket(ASTUBaseWeaponActor *Weapon, USceneComponent *SceneComponent, FName SoketName);
    void EquipWeapon(int32 WeaponIndex);

  private:
    void LaunchAnimMontage(UAnimMontage *AnimMontage);
    void InitAnimation();
    void OnEquipFinished(USkeletalMeshComponent *MeshComponent);
    bool WeaponChangeInProgress = false;
    bool CanFire() const;
    bool CanEquip() const;
};
