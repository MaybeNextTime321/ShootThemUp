// Shoot Them Up. Project from Udemy course

#include "Weapon/Components/STUWeaponFXComponent.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

// Sets default values for this component's properties
USTUWeaponFXComponent::USTUWeaponFXComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these
    // features off to improve performance if you don't need them.
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
void USTUWeaponFXComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}

void USTUWeaponFXComponent::PlayImpactFX(FHitResult HitResult)
{
    auto Impact = DefaultImpactData;

    if (HitResult.PhysMaterial.IsValid())
    {
        auto PhysMaterial = HitResult.PhysMaterial.Get();

        if (MapImpacts.Contains(PhysMaterial))
        {
            Impact = MapImpacts[PhysMaterial];
        }
    }

    // spawn niagara
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),            //
                                                   Impact.NiagaraSystem,  //
                                                   HitResult.ImpactPoint, //
                                                   HitResult.ImpactNormal.Rotation());

    // spawn decal
    auto Decal = UGameplayStatics::SpawnDecalAtLocation(GetWorld(),                       //
                                                        Impact.DecalImpact.DecalMaterial, //
                                                        Impact.DecalImpact.DecalSize,     //
                                                        HitResult.ImpactPoint,            //
                                                        HitResult.ImpactNormal.Rotation());

    Decal->SetFadeOut(Impact.DecalImpact.LiveTime, Impact.DecalImpact.FadeTime);
}
