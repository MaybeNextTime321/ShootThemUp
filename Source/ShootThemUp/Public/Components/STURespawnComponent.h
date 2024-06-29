// Shoot Them Up. Project from Udemy course

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STURespawnComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMUP_API USTURespawnComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    USTURespawnComponent();
    void InitializeRespawn(int32 RespawnFullTime);
    bool RespawnInProgress() const;
    int32 GetRespawnTime() const;
  protected:
    virtual void BeginPlay() override;

  private:
    FTimerHandle RespawnTimer;
    int32 RespawnTime;
    void RespawnTick();


};
