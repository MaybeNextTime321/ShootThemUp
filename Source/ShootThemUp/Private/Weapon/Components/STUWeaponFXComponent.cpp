// Shoot Them Up. Project from Udemy course


#include "Weapon/Components/STUWeaponFXComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "PhysicalMaterials/PhysicalMaterial.h"


// Sets default values for this component's properties
USTUWeaponFXComponent::USTUWeaponFXComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USTUWeaponFXComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USTUWeaponFXComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USTUWeaponFXComponent::PlayImpactFX(FHitResult HitResult)
{
    auto Effect = DefaultEffect;

    if (HitResult.PhysMaterial.IsValid())
    {
        auto PhysMaterial = HitResult.PhysMaterial.Get();

		if (MapEffects.Contains(PhysMaterial))
        {
            Effect = MapEffects[PhysMaterial];
		}
	}

    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, HitResult.ImpactPoint,
                                                   HitResult.ImpactPoint.Rotation());
    
}

