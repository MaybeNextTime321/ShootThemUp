// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STUHUD.generated.h"

/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API ASTUHUD : public AHUD
{
    GENERATED_BODY()

  public:
    void DrawHUD() override;

  private:
    void DrawAim();
};
