// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "ProjectMarblePlayerController.generated.h"

/** PlayerController class used to enable cursor */
UCLASS()
class AProjectMarblePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AProjectMarblePlayerController();

private:
	void onInputPressed();
};


