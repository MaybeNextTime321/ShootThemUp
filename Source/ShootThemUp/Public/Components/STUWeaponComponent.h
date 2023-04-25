// Shoot Them Up. Project from Udemy course

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "STUWeaponComponent.generated.h"

class ASTUBaseWeaponActor;

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
    void Reload();

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

    UPROPERTY(EditDefaultsOnly, Category = "Weapon");
    UAnimMontage *CurrentReloadAnimMontage = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<FWeaponData> WeaponComponent;

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
    void OnReloadFinished(USkeletalMeshComponent *MeshComponent);
    bool WeaponChangeInProgress = false;
    bool WeaponReloadInProgress = false;
    bool CanFireAndReload() const;
    bool CanEquip() const;

    template <typename T> T *FindNotifyByClass(UAnimSequenceBase *Animation)
    {
        if (!Animation)
            return nullptr;
        const TArray<FAnimNotifyEvent> NotifyEvents = Animation->Notifies;
        for (FAnimNotifyEvent NotifyEvent : NotifyEvents)
        {
            auto AnimNotify = Cast<T>(NotifyEvent.Notify);
            if (AnimNotify)
            {
                return AnimNotify;
            }
        }
        return nullptr;
    }
};
