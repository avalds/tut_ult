// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "tut_ultGameMode.h"
#include "tut_ultCharacter.h"
#include "UObject/ConstructorHelpers.h"

Atut_ultGameMode::Atut_ultGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
