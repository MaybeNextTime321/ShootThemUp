// Shoot Them Up. Project from Udemy course


#include "Sound/STUSoundFuncLib.h"
#include "Sound/SoundClass.h"

void USTUSoundFuncLib::ToggleSoundClassValue(USoundClass *SoundClass)
{
    bool SoundPlaying = SoundClass->Properties.Volume > 0;
    SetSoundClassVolume(SoundClass, SoundPlaying ? 0 : 1);
}

void USTUSoundFuncLib::SetSoundClassVolume(USoundClass *SoundClass, float NewValue)
{
    SoundClass->Properties.Volume = FMath::Clamp(NewValue, 0.0f, 1.0f);
}
