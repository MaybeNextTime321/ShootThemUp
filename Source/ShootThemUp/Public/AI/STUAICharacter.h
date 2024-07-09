// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Player/STUBaseCharacter.h"
#include "STUAICharacter.generated.h"

class UBehaviorTree;
class UWidgetComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUAICharacter : public ASTUBaseCharacter
{
    GENERATED_BODY()

  public:
    ASTUAICharacter(const FObjectInitializer &ObjInit);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    UBehaviorTree *BehaviorTreeAsset;

    protected:

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widget")
      UWidgetComponent *UserHealthWidget;

    virtual void OnHealthChange(float HP, float HPDelta) override;

    virtual void BeginPlay() override;

  private:
    virtual void CharacterIsDead() override;
};
