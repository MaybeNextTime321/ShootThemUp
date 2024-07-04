// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "STUCoreTypes.h"
#include "GameFramework/PlayerController.h"
#include "STUPlayerController.generated.h"

class USTURespawnComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUPlayerController : public APlayerController
{
    GENERATED_BODY()
  public:
    ASTUPlayerController();

  protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
    USTURespawnComponent *RespawnComponent;
    virtual void SetupInputComponent() override;
    virtual void BeginPlay() override;

    private:
    void PauseGame();
    void ChangeMatchState(ESTUMathState NewState);
};
