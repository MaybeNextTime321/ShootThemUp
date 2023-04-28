// Shoot Them Up. Project from Udemy course

#include "UI/STUPlayerHUDWidget.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"

float USTUPlayerHUDWidget::GetHealthProcent() const
{

    const USTUHealthComponent *HealthComponent = GetHealthComponent();

    if (HealthComponent)
        return HealthComponent->GetHealthProcent();
    else
        return 0.0f;
}

bool USTUPlayerHUDWidget::GetWeaponUIData(FWeaponUIData &WeaponUI)
{
    const USTUWeaponComponent *WeaponComponent = GetWeaponComponent();

    if (!WeaponComponent)
        return false;

    return WeaponComponent->GetFWeaponUIData(WeaponUI);
}

bool USTUPlayerHUDWidget::GetAmmoData(FAmmoData &WeaponData)
{
    const USTUWeaponComponent *WeaponComponent = GetWeaponComponent();

    if (!WeaponComponent)
        return false;

    return WeaponComponent->GetAmmoData(WeaponData);
}

bool USTUPlayerHUDWidget::IsAlive() const
{
    const USTUHealthComponent *HealthComponent = GetHealthComponent();

    return HealthComponent && !HealthComponent->IsDead();
}

bool USTUPlayerHUDWidget::IsSpectating() const
{
    const auto Controler = GetOwningPlayer();
    return Controler && Controler->GetStateName() == NAME_Spectating;
}

const USTUWeaponComponent *USTUPlayerHUDWidget::GetWeaponComponent() const
{
    const APawn *Pawn = GetOwningPlayerPawn();
    if (!Pawn)
        return false;
    const UActorComponent *Component = Pawn->GetComponentByClass(USTUWeaponComponent::StaticClass());
    const auto *WeaponComponent = Cast<USTUWeaponComponent>(Component);

    return WeaponComponent;
}

const USTUHealthComponent *USTUPlayerHUDWidget::GetHealthComponent() const
{
    const APawn *Pawn = GetOwningPlayerPawn();
    if (!Pawn)
        return false;
    const UActorComponent *Component = Pawn->GetComponentByClass(USTUHealthComponent::StaticClass());
    const auto *HealthComponent = Cast<USTUHealthComponent>(Component);

    return HealthComponent;
}