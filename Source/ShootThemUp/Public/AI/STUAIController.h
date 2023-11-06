// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "STUAIController.generated.h"


UCLASS()
class SHOOTTHEMUP_API ASTUAIController : public AAIController
{
	GENERATED_BODY()
    virtual void OnPossess(APawn *InPawn) override;
};
