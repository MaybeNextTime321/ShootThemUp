#pragma once

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
};