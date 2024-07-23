// Shoot Them Up. Project from Udemy course


#include "STUGameInstance.h"
#include "Sound/STUSoundFuncLib.h"
#include "Sound/SoundClass.h"

void USTUGameInstance::ToggleGameSound()
{
    USTUSoundFuncLib::ToggleSoundClassValue(ParentSoundClass);
}
