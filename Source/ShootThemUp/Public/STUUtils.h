#pragma once
#include "Player/STUPlayerState.h"

class STUUtils
{
  public:
    template <typename T> static T *GetPlayerComponent(AActor *Actor)
    {
        if (!Actor)
            return nullptr;
        UActorComponent *PawnComponent = Actor->GetComponentByClass(T::StaticClass());
        return Cast<T>(PawnComponent);
    }
    bool static AreEnemy(const AController* Controller1, const AController* Controller2)
    {
        if (!Controller1 || !Controller2 || Controller1 == Controller2)
        {
            return false;
        }
        const auto PlayerState1 = Cast<ASTUPlayerState>(Controller1->PlayerState);
        const auto PlayerState2 = Cast<ASTUPlayerState>(Controller2->PlayerState);

        if (!PlayerState1 || !PlayerState2)
        {
            return false;
        }

        return PlayerState1->GetTeamNumber() != PlayerState2->GetTeamNumber();
    }
};