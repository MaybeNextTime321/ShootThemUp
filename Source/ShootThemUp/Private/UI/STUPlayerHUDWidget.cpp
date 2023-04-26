// Shoot Them Up. Project from Udemy course

#include "UI/STUPlayerHUDWidget.h"
#include "Components/STUHealthComponent.h"

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
