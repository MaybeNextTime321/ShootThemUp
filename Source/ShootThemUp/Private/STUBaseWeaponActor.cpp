// Shoot Them Up. Project from Udemy course

#include "STUBaseWeaponActor.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ASTUBaseWeaponActor::ASTUBaseWeaponActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SceletalMesh");
    SetRootComponent(SkeletalMesh);
}

// Called when the game starts or when spawned
void ASTUBaseWeaponActor::BeginPlay()
{
    Super::BeginPlay();
}
