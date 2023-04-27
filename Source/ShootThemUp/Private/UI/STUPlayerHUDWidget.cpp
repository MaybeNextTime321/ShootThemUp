// Shoot Them Up. Project from Udemy course

#include "UI/STUPlayerHUDWidget.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"

float USTUPlayerHUDWidget::GetHealthProcent() const
{
    const APawn *Pawn = GetOwningPlayerPawn();
    if (!Pawn)
        return 0.0f;

    const UActorComponent *Component = Pawn->GetComponentByClass(USTUHealthComponent::StaticClass());
    const USTUHealthComponent *HealthComponent = Cast<USTUHealthComponent>(Component);

    if (HealthComponent)
        return HealthComponent->GetHealthProcent();
    else
        return 0.0f;
}

bool USTUPlayerHUDWidget::GetWeaponUIData(FWeaponUIData &WeaponUI)
{
    const auto *WeaponComponent = GetWeaponComponent();

    if (!WeaponComponent)
        return false;

    return WeaponComponent->GetFWeaponUIData(WeaponUI);
}

bool USTUPlayerHUDWidget::GetAmmoData(FAmmoData &WeaponData)
{
    const auto *WeaponComponent = GetWeaponComponent();

    if (!WeaponComponent)
        return false;

    return WeaponComponent->GetAmmoData(WeaponData);
}

const USTUWeaponComponent *USTUPlayerHUDWidget::GetWeaponComponent()
{
    const APawn *Pawn = GetOwningPlayerPawn();
    if (!Pawn)
        return false;
    const UActorComponent *Component = Pawn->GetComponentByClass(USTUWeaponComponent::StaticClass());
    const auto *WeaponComponent = Cast<USTUWeaponComponent>(Component);

    return WeaponComponent;
}
