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
    virtual bool Initialize() override;
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

    UFUNCTION(BlueprintImplementableEvent, Category = "UI")
    void OnTakeDamage();

    UFUNCTION()
    void OnHealthChange(float HP, float HPDelta);

  private:
};
