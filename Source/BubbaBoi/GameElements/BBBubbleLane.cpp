// Fill out your copyright notice in the Description page of Project Settings.


#include "BBBubbleLane.h"

ABBBubbleLane::ABBBubbleLane()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("SplineMesh"));
	Spline->SetupAttachment(RootComponent);
}

void ABBBubbleLane::BeginPlay()
{
	Super::BeginPlay();
}

void ABBBubbleLane::SpawnItem(AActor* ActorToSpawn)
{
	UE_LOG(LogTemp, Display, TEXT("SpawnItem: %s"), *ActorToSpawn->GetName());
}

void ABBBubbleLane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}