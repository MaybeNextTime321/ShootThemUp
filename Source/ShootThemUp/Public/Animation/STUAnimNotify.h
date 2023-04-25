// Shoot Them Up. Project from Udemy course

#pragma once

#include "Animation/AnimNotifies/AnimNotify.h"
#include "CoreMinimal.h"
#include "STUAnimNotify.generated.h"

/**
 *
 */
DECLARE_MULTICAST_DELEGATE_OneParam(FOnEquipedSignature, USkeletalMeshComponent *)

    UCLASS() class SHOOTTHEMUP_API USTUAnimNotify : public UAnimNotify
{
    GENERATED_BODY()
  protected:
    virtual void Notify(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation) override;

  public:
    FOnEquipedSignature OnNotified;
};
