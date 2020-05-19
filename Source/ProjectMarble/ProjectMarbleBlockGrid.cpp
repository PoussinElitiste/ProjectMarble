// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ProjectMarble.h"
#include "ProjectMarbleBlockGrid.h"
#include "ProjectMarbleBlock.h"
#include "Components/TextRenderComponent.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

AProjectMarbleBlockGrid::AProjectMarbleBlockGrid()
	: Width(5)
	, MinHeight(5)
	, BlockSpacing(300.f)
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));
	ScoreText->SetRelativeLocation(FVector(200.f,0.f,0.f));
	ScoreText->SetRelativeRotation(FRotator(90.f,0.f,0.f));
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(0)));
	ScoreText->AttachTo(DummyRoot);
}


void AProjectMarbleBlockGrid::BeginPlay()
{
	Super::BeginPlay();

	// Number of blocks
	const int32 NumBlocks = Width * MinHeight;

	// Loop to spawn each block
	for(int32 BlockIndex=0; BlockIndex<NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex / Width) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex % Width) * BlockSpacing; // Modulo gives remainder

		// Make postion vector, offset from Grid location
		const FVector BlockLocation = GetActorLocation() + FVector(XOffset, YOffset, 0.f);

		// Spawn a block
		AProjectMarbleBlock* NewBlock = GetWorld()->SpawnActor<AProjectMarbleBlock>(BlockLocation, FRotator(0,0,0));

		// Tell the block about its owner
		if(NewBlock != NULL)
		{
			NewBlock->OwningGrid = this;
		}
	}


// 	NumBlocks
// 	if (!bIsActive)
// 	{
// 		bIsActive = true;
// 
// 		// Change material
// 		BlockMesh->SetMaterial(0, OrangeMaterial);
// 
// 		// Tell the Grid
// 		if (OwningGrid != NULL)
// 		{
// 			OwningGrid->AddScore();
// 		}
// 	}
}


void AProjectMarbleBlockGrid::AddScore()
{
	// Increment score
	Score++;

	// Update text
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));
}

#undef LOCTEXT_NAMESPACE
