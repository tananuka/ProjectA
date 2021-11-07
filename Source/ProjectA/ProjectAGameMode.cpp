// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectAGameMode.h"
#include "ProjectAPlayerController.h"
#include "ProjectACharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectAGameMode::AProjectAGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AProjectAPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}