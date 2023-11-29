// Shoot Them Up. Project from Udemy course

#include "Components/STUWeaponAIComponent.h"
#include "STUBaseWeaponActor.h"

void USTUWeaponAIComponent::StartFire()
{
    if (!CanFire())
    {
        return;
    }

    if (CurrentWeapon->IsAmmoEmpty())
    {
        NextWeapon();
    }
    else
    {
        CurrentWeapon->StartFire();
    }
}

void USTUWeaponAIComponent::NextWeapon()
{
    if (!CanEquip() || Weapons.Num() == 0)
    {
        return;
    }

    int32 NextIndex = (CurrentWeaponIndex + 1) % Weapons.Num();

    while (NextIndex != CurrentWeaponIndex)
    {
        if (!Weapons[NextIndex]->IsAmmoEmpty())
        {
            break;
        }
        NextIndex = (CurrentWeaponIndex + 1) % Weapons.Num();
    }

    if (CurrentWeaponIndex != NextIndex)
    {
        CurrentWeaponIndex = NextIndex;
        EquipWeapon(CurrentWeaponIndex);
    }
}

bool USTUWeaponAIComponent::NeedAmmo(TSubclassOf<ASTUBaseWeaponActor> Weapon) const
{

    for (const auto WeaponInArray : Weapons)
    {
        if (WeaponInArray->IsA(Weapon))
        {
            return !WeaponInArray->IsAmmoFull();
        }
    }
    return false;
}
