// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUBaseCharacter.generated.h"


class USTUHealthComponent;
class ASTUBaseWeaponActor;
class USTUWeaponComponent;
class USoundCue;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseCharacter : public ACharacter
{
    GENERATED_BODY()

  public:
    // Sets default values for this character's properties
    ASTUBaseCharacter(const FObjectInitializer &ObjInit);

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
    USTUHealthComponent *HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    USTUWeaponComponent *WeaponComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage")
    FVector2D LandedDamageVelocity = {900, 1200};

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage")
    FVector2D LandedDamage = {10, 20};

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Maerial")
    FName MaterialColorName = "Paint Color";

    virtual void CharacterIsDead();

    UFUNCTION()
    virtual void OnHealthChange(float HP, float HPDelta);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue *DeathSound;

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    virtual bool IsRunning() const;

    UFUNCTION(BlueprintCallable)
    float GetDegree();

    UPROPERTY(EditAnyWhere, Category = "Animation")
    UAnimMontage *AnimMontage;

    void SetColor(FLinearColor& Color);

  private:
    UFUNCTION()
    void OnGroupned(const FHitResult &Hit);
};