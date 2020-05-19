// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ProjectMarble.h"
#include "ProjectMarblePlayerController.h"

AProjectMarblePlayerController::AProjectMarblePlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = false;
	bEnableTouchEvents = true;

	// set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("LeftAction", EInputEvent::IE_Pressed, this, &AProjectMarblePlayerController::onInputPressed);
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AProjectMarblePlayerController::onInputPressed()
{

}
