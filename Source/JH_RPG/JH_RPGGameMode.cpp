// Copyright Epic Games, Inc. All Rights Reserved.

#include "JH_RPGGameMode.h"
#include "JH_RPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJH_RPGGameMode::AJH_RPGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
