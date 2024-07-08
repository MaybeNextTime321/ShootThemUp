// Shoot Them Up. Project from Udemy course


#include "Menu/UI/STUMenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "STUGameInstance.h"
#include "STUCoreTypes.h"
#include "Menu/UI/STULevelItemWidget.h"
#include "Components/HorizontalBox.h"


DEFINE_LOG_CATEGORY_STATIC(STUMenuWigetLog, All, All)

void USTUMenuUserWidget::OnGameStart()
{
    if (!GetWorld())
    {
        return;
    }
    const auto GameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();

    if (!GameInstance)
    {
        return;
    }

    const FName LevelName = GameInstance->GetStartLevel().LevelName;

    if (LevelName == NAME_None)
    {
        UE_LOG(STUMenuWigetLog, Error, TEXT("Setup First Level Name in Game Instance"));
    }

    UGameplayStatics::OpenLevel(this, LevelName);
}

void USTUMenuUserWidget::QuitGame()
{
    UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayer(), EQuitPreference::Quit, true);
}

void USTUMenuUserWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &USTUMenuUserWidget::OnGameStart);
    }

    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &USTUMenuUserWidget::QuitGame);
    }

    InitializeLevels();
}

void USTUMenuUserWidget::InitializeLevels()
{
    const auto GameInstance = GetLevelInstance();

    if (!GameInstance)
    {
        return;
    }

    checkf(GameInstance->GetGameLevels().Num() != 0, TEXT("Levels data must not be empty!"));

    if (!LevelHorizontalBox || !SpawnedLevelClass)
    {
        return;
    }

    LevelHorizontalBox->ClearChildren();

    for (auto Level : GameInstance->GetGameLevels())
    {
        const auto NewWidget = CreateWidget<USTULevelItemWidget>(GetWorld(), SpawnedLevelClass);
       
        if (!NewWidget)
        {
            continue;
        }

        NewWidget->SetLevelData(Level);
        NewWidget->OnLevelSelectedDelegate.AddUObject(this, &USTUMenuUserWidget::OnSelectedLevelChange);
        
        LevelHorizontalBox->AddChild(NewWidget);
        CreatedLevels.Add(NewWidget);
    
    }

    if (GameInstance->GetStartLevel().LevelName.IsNone())
    {
        OnSelectedLevelChange(GameInstance->GetGameLevels()[0]);
    }
    else
    {
        OnSelectedLevelChange(GameInstance->GetStartLevel());
    }
 
}

USTUGameInstance *USTUMenuUserWidget::GetLevelInstance()
{
    if (!GetWorld())
    {
        return nullptr;
    }

    return GetWorld()->GetGameInstance<USTUGameInstance>();
}

void USTUMenuUserWidget::OnSelectedLevelChange(const FLevelData NewLevel)
{
    const auto GameInstnce = GetLevelInstance();

    if (!GameInstnce)
    {
        return;
    }

    GameInstnce->SetStartedLevel(NewLevel);

    for (auto Level : CreatedLevels)
    {
        if (!Level)
        {
            continue;
        }
        const auto LevelData = Level->GetLevelData();
        Level->SetImageVisibility(LevelData.LevelName == NewLevel.LevelName);
        
    }
}