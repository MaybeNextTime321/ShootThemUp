// Shoot Them Up. Project from Udemy course

#include "Components/STUHealthComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(HealthComponentLog, All, All)

// Sets default values for this component's properties
USTUHealthComponent::USTUHealthComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these
    // features off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;

    // ...
}

// Called when the game starts
void USTUHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    World = GetWorld();
    SetHealth(MaxHealth);
    AActor *Owner = GetOwner();
    Owner->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage);
    // ...
    checkf(MaxHealth > 0, TEXT("Max Helth must be >0"));
}

void USTUHealthComponent::OnAutoHeal()
{

    SetHealth(Health + AutoHealValue);

    if (Health == MaxHealth)
        StopAutoHeal();
}

void USTUHealthComponent::SetHealth(float NewHealth)
{
    Health = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
    OnHealthChange.Broadcast(Health);
}

void USTUHealthComponent::OnTakeAnyDamage(AActor *DamagedActor, float Damage, const UDamageType *DamageType,
                                          AController *InstigatedBy, AActor *DamageCauser)
{

    if (Damage == 0.0f || IsDead())
        return;

    if (HealTimer.IsValid())
        StopAutoHeal();

    SetHealth(Health - Damage);

    if (IsDead())
        OnDead.Broadcast();

    else if (Autoheal)
        StartAutoHeal();
}

void USTUHealthComponent::StartAutoHeal()
{
    World->GetTimerManager().SetTimer(HealTimer, this, &USTUHealthComponent::OnAutoHeal, TimerRate, true, TimerDelay);
}

void USTUHealthComponent::StopAutoHeal()
{
    World->GetTimerManager().ClearTimer(HealTimer);
}
