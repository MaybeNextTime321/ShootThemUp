// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "STUBaseCharacter.generated.h"

class UCameraComponent;

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

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable)
    bool IsRunning() const;

    UFUNCTION(BlueprintCallable)
    float GetDegree();

  private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);
    void SetShiftValue();
    bool ShiftIsPressed = false;
    bool IsMoveForward = true;
};
