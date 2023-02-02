// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "STUBaseCharacter.generated.h"

class UCameraComponent;
class USTUHealthComponent;
class UTextRenderComponent;

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

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
    UCameraComponent *CameraComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
    USpringArmComponent *SpringArmComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
    USTUHealthComponent *HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
    UTextRenderComponent *TextRenderComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage")
    FVector2D LandedDamageVelocity = {900, 1200};

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage")
    FVector2D LandedDamage = {10, 20};

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable)
    bool IsRunning() const;

    UFUNCTION(BlueprintCallable)
    float GetDegree();

    UPROPERTY(EditAnyWhere, Category = "Animation")
    UAnimMontage *AnimMontage;

  private:
    UFUNCTION()
    void OnHealthChange(float HP);
    void CharacterIsDead();
    void MoveForward(float Amount);
    void MoveRight(float Amount);
    void SetShiftValue();
    bool ShiftIsPressed = false;
    bool IsMoveForward = true;
    UFUNCTION()
    void OnGroupned(const FHitResult &Hit);
};