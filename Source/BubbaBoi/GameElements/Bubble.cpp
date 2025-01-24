// Fill out your copyright notice in the Description page of Project Settings.


#include "Bubble.h"

ABubble::ABubble()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABubble::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABubble::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABubble::PopBubble_Implementation()
{
	Destroy();
}
