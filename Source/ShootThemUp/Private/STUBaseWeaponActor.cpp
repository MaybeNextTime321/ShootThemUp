// Shoot Them Up. Project from Udemy course

#include "STUBaseWeaponActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"

DEFINE_LOG_CATEGORY_STATIC(BaseWeaponLog, All, All)
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

void ASTUBaseWeaponActor::Fire()
{
    UE_LOG(BaseWeaponLog, Display, TEXT("FIRE"));
    MakeShoot();
}

void ASTUBaseWeaponActor::MakeShoot()
{
    FVector Location;
    FRotator Rotation;

    ACharacter *CharacterOwner = Cast<ACharacter>(GetOwner());
    CharacterOwner->Controller->GetPlayerViewPoint(Location, Rotation);

    FVector LineStart = Location;
    // SkeletalMesh->GetSocketLocation("MuzzleSoket");
    FVector SoketForward = Rotation.Vector();
    // SkeletalMesh->GetSocketQuaternion("MuzzleSoket").GetForwardVector();
    FVector LineEnd = LineStart + SoketForward * ShootDistance;

    FHitResult HitResult;
    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());

    GetWorld()->LineTraceSingleByChannel(HitResult, LineStart, LineEnd, ECollisionChannel::ECC_Visibility,
                                         CollisionParams);
    if (HitResult.bBlockingHit)
    {
        DrawDebugLine(GetWorld(), SkeletalMesh->GetSocketLocation("MuzzleSoket"), HitResult.ImpactPoint, FColor::Blue,
                      false, 3.0f, 0, 3.0f);
        DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 3.0f, 0, 3.0f);

        UE_LOG(BaseWeaponLog, Display, TEXT("Bone on road : %s"), *HitResult.BoneName.ToString());
    }
    else
    {

        DrawDebugLine(GetWorld(), SkeletalMesh->GetSocketLocation("MuzzleSoket"), LineEnd, FColor::Blue, false, 3.0f, 0,
                      3.0f);
    }
}
