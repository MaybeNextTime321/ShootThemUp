// Shoot Them Up. Project from Udemy course

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "STUCoreTypes.h"
#include "STUPlayerHUDWidget.generated.h"

class USTUWeaponComponent;
class USTUHealthComponent;
/**
 *
 */
UCLASS()
class SHOOTTHEMUP_API USTUPlayerHUDWidget : public UUserWidget
{
    GENERATED_BODY()

  public:
    UFUNCTION(BlueprintCallable, Category = "PlayerHUDWidget")
    float GetHealthProcent() const;

    UFUNCTION(BlueprintCallable, Category = "PlayerHUDWidget")
    bool GetWeaponUIData(FWeaponUIData &WeaponUI);

    UFUNCTION(BlueprintCallable, Category = "PlayerHUDWidget")
    bool GetAmmoData(FAmmoData &WeaponData);

    UFUNCTION(BlueprintCallable, Category = "PlayerHUDWidget")
    bool IsAlive() const;
    UFUNCTION(BlueprintCallable, Category = "PlayerHUDWidget")
    bool IsSpectating() const;

  private:
    const USTUWeaponComponent *GetWeaponComponent() const;
    const USTUHealthComponent *GetHealthComponent() const;
};
