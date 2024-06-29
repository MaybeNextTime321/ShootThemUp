// Shoot Them Up. Project from Udemy course


#include "Components/STURespawnComponent.h"
#include "STUGameModeBase.h"

USTURespawnComponent::USTURespawnComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USTURespawnComponent::InitializeRespawn(int32 RespawnFullTime)
{
	if (!GetWorld())
	{
        return;
	}
    RespawnTime = RespawnFullTime;
    GetWorld()->GetTimerManager().SetTimer(RespawnTimer, this, &USTURespawnComponent::RespawnTick, 1.0f, true);
}

bool USTURespawnComponent::RespawnInProgress() const
{
    if (!GetWorld())
    {
        return false;
    }
    return GetWorld()->GetTimerManager().IsTimerActive(RespawnTimer);
}

int32 USTURespawnComponent::GetRespawnTime() const
{
    return RespawnTime;
}

void USTURespawnComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USTURespawnComponent::RespawnTick()
{
    --RespawnTime;

	if (RespawnTime == 0 && GetWorld())
	{
        GetWorld()->GetTimerManager().ClearTimer(RespawnTimer);
        const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
        if (!GameMode)
        {
            return;
        }
        GameMode->RespawnPerson(Cast<AController>(GetOwner()));
	}
}

