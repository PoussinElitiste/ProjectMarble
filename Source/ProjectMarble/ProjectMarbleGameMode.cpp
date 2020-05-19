// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ProjectMarble.h"
#include "ProjectMarbleGameMode.h"
#include "ProjectMarblePlayerController.h"

AProjectMarbleGameMode::AProjectMarbleGameMode()
{
	// no pawn by default
	DefaultPawnClass = NULL;
	// use our own player controller class
	PlayerControllerClass = AProjectMarblePlayerController::StaticClass();
}
