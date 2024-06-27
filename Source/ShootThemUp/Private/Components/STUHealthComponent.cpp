// Shoot Them Up. Project from Udemy course

#include "Components/STUHealthComponent.h"
#include "Camera/CameraShakeBase.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "TimerManager.h"
#include "STUGameModeBase.h"
#include "Player/STUPlayerController.h"

DEFINE_LOG_CATEGORY_STATIC(HealthComponentLog, All, All)

void USTUHealthComponent::AddHealth(float HealthAmount)
{
    SetHealth(Health + HealthAmount);
}

// Sets default values for this component's properties
USTUHealthComponent::USTUHealthComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these
    // features off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;

    // ...
}

bool USTUHealthComponent::IsFullHealth()
{
    return FMath::IsNearlyEqual(Health, MaxHealth);
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
    const float NextHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
    const float HealthDelta = NextHealth - Health;

    Health = NextHealth;
    OnHealthChange.Broadcast(Health, HealthDelta);
}

void USTUHealthComponent::OnTakeAnyDamage(AActor *DamagedActor, float Damage, const UDamageType *DamageType,
                                          AController *InstigatedBy, AActor *DamageCauser)
{
    PlayCameraShake();

    if (Damage == 0.0f || IsDead())
        return;

    if (HealTimer.IsValid())
        StopAutoHeal();

    SetHealth(Health - Damage);

    if (IsDead())
    {
        Killed(InstigatedBy);
        OnDead.Broadcast();
    }


    else if (Autoheal)
        StartAutoHeal();
}

void USTUHealthComponent::Killed(AController *KilledBy)
{

    if (!GetWorld())
    {
        return;
    }

    const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());

    if (!GameMode)
    {
        return;
    }

    const auto Player = Cast<APawn>(GetOwner());
    const auto VictimController = Player ? Player->GetController() : nullptr;
    GameMode->SetKill(KilledBy, VictimController);
    

}

void USTUHealthComponent::StartAutoHeal()
{
    World->GetTimerManager().SetTimer(HealTimer, this, &USTUHealthComponent::OnAutoHeal, TimerRate, true, TimerDelay);
}

void USTUHealthComponent::PlayCameraShake()
{
    if (IsDead())
    {
        return;
    }

    const APawn *PlayerPawn = Cast<APawn>(GetOwner());

    const APlayerController *PlayerController = PlayerPawn->GetController<APlayerController>();
    if (PlayerController && PlayerController->PlayerCameraManager)
    {
        PlayerController->PlayerCameraManager->StartCameraShake(DamageCamaeraShake);
    }
}

void USTUHealthComponent::StopAutoHeal()
{
    World->GetTimerManager().ClearTimer(HealTimer);
}
