// Shoot Them Up. Project from Udemy course

#include "Animation/STUEquipAnimNotify.h"

void USTUEquipAnimNotify::Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation)
{
    OnNotified.Broadcast(MeshComp);
    Super::Notify(MeshComp, Animation);
}
