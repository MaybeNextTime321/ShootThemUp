// Shoot Them Up. Project from Udemy course

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "STUAIController.generated.h"

class USTUAIPerceptionComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUAIController : public AAIController
{

    GENERATED_BODY()
    virtual void OnPossess(APawn *InPawn) override;

  public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    USTUAIPerceptionComponent *Component;

  protected:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    FName FocusOnKeyName = "EnemyActor";

    ASTUAIController();

  private:
    AActor *GetFocusedActor() const;
};
