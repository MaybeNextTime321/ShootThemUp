// Shoot Them Up. Project from Udemy course

#include "UI/STUPlayerHUDWidget.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"
#include "Player/STUPlayerState.h"
#include "STUUtils.h"
bool USTUPlayerHUDWidget::Initialize()
{
    const auto HealthComponent = STUUtils::GetPlayerComponent<USTUHealthComponent>(GetOwningPlayerPawn());

    if (HealthComponent)
    {
        HealthComponent->OnHealthChange.AddUObject(this, &USTUPlayerHUDWidget::OnHealthChange);
    }

    return Super::Initialize();
}
float USTUPlayerHUDWidget::GetHealthProcent() const
{

    const USTUHealthComponent *HealthComponent =
        STUUtils::GetPlayerComponent<USTUHealthComponent>(GetOwningPlayerPawn());

    if (HealthComponent)
        return HealthComponent->GetHealthProcent();
    else
        return 0.0f;
}

bool USTUPlayerHUDWidget::GetWeaponUIData(FWeaponUIData &WeaponUI)
{
    const USTUWeaponComponent *WeaponComponent =
        STUUtils::GetPlayerComponent<USTUWeaponComponent>(GetOwningPlayerPawn());

    if (!WeaponComponent)
        return false;

    return WeaponComponent->GetFWeaponUIData(WeaponUI);
}

bool USTUPlayerHUDWidget::GetAmmoData(FAmmoData &WeaponData)
{
    const USTUWeaponComponent *WeaponComponent =
        STUUtils::GetPlayerComponent<USTUWeaponComponent>(GetOwningPlayerPawn());

    if (!WeaponComponent)
        return false;

    return WeaponComponent->GetAmmoData(WeaponData);
}

bool USTUPlayerHUDWidget::IsAlive() const
{
    const USTUHealthComponent *HealthComponent =
        STUUtils::GetPlayerComponent<USTUHealthComponent>(GetOwningPlayerPawn());

    return HealthComponent && !HealthComponent->IsDead();
}

bool USTUPlayerHUDWidget::IsSpectating() const
{
    const auto Controler = GetOwningPlayer();
    return Controler && Controler->GetStateName() == NAME_Spectating;
}

void USTUPlayerHUDWidget::OnHealthChange(float HP, float HPDelta)
{
    if (HPDelta < 0.0f)
    {
        OnTakeDamage();
    }
}
