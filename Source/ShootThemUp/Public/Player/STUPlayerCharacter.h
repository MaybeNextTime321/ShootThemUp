// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Player/STUBaseCharacter.h"
#include "STUPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USphereComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUPlayerCharacter : public ASTUBaseCharacter
{
    GENERATED_BODY()
  public:
    ASTUPlayerCharacter(const FObjectInitializer &ObjInit);

  protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
    UCameraComponent *CameraComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
    USpringArmComponent *SpringArmComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
    USphereComponent *CameraSphereComponent;

  protected:
    virtual void BeginPlay() override;

  public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    virtual bool IsRunning() const override;

  private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);
    void SetShiftValue();
    bool ShiftIsPressed = false;
    bool IsMoveForward = true;
    UFUNCTION()
    void CameraSphereBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32
                                  OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
   
    UFUNCTION()
    void CameraSphereEndOverlap(UPrimitiveComponent * OverlappedComponent,
                                AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex);

    void CheckCameraOverlap();
};
