// Shoot Them Up. Project from Udemy course

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "STUCoreTypes.h"
#include "STUPlayerHUDWidget.generated.h"

class USTUWeaponComponent;
class USTUHealthComponent;
class UProgressBar;


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

    UFUNCTION(BlueprintImplementableEvent, Category = "UI")
    void OnTakeDamage();

  protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UProgressBar *HealthProgressBar;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthWidget")
    float PersentForBadColor = 0.3;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthWidget")
    FColor GoodColor = FColor::Green;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthWidget")
    FColor BadColor = FColor::Red;
    
    UFUNCTION()
    virtual void OnHealthChange(float HP, float HPDelta);

    private:
    void SetProgressBarValue();
      
    UFUNCTION()
    void OnNewPawn(APawn* NewPawan);
};
