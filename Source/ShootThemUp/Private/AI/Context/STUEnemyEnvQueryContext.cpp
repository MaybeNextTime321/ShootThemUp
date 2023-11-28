// Shoot Them Up. Project from Udemy course


#include "AI/Context/STUEnemyEnvQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

void USTUEnemyEnvQueryContext::ProvideContext(FEnvQueryInstance &QueryInstance, FEnvQueryContextData &ContextData) const
{
    AActor *QueryOwner = Cast<AActor>(QueryInstance.Owner.Get());
    const auto BlackBoard = UAIBlueprintHelperLibrary::GetBlackboard(QueryOwner);
    
    if (!BlackBoard)
        return;

    const auto ContextActor = BlackBoard->GetValueAsObject(EnemyActorKeyName);

    
    UEnvQueryItemType_Actor::SetContextHelper(ContextData, Cast<AActor>(ContextActor));
}
