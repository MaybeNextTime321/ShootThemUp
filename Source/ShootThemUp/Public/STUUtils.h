#pragma once

class STUUtils
{
  public:
    template <typename T> static T *GetPlayerComponent(APawn *PlayerPawn)
    {
        if (!PlayerPawn)
            return nullptr;
        UActorComponent *PawnComponent = PlayerPawn->GetComponentByClass(T::StaticClass());
        return Cast<T>(PawnComponent);
    }
};