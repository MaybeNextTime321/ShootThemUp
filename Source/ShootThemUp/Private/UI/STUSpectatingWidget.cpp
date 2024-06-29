// Shoot Them Up. Project from Udemy course


#include "UI/STUSpectatingWidget.h"
#include "STUUTils.h"
#include "Components/STURespawnComponent.h"

bool USTUSpectatingWidget::GetRespwanTime(int32 &RespawnTime)
{
    const auto RespawnComponent = STUUtils::GetPlayerComponent<USTURespawnComponent>(GetOwningPlayer());
     
    if (!RespawnComponent || !RespawnComponent->RespawnInProgress())
    {
        return false;
    }

    RespawnTime = RespawnComponent->GetRespawnTime(); 
    return true;
}
