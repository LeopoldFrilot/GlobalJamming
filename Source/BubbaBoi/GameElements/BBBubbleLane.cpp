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

void ABBBubbleLane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (TTuple<TObjectPtr<ABubble>, float>& Timer : BubbleTimers)
	{
		if (!IsValid(Timer.Key))
		{
			//BubbleTimers.Remove(Timer.Key);
			continue;
		}

		float Alpha = Timer.Value / TimeToEnd;
		float Distance = FMath::Lerp(0, Spline->GetSplineLength(), Alpha);
		FVector TargetLocation = Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);

		Timer.Key->SetActorLocation(TargetLocation);
		Timer.Value += DeltaTime;
	}
}

void ABBBubbleLane::SpawnBubble(TSubclassOf<ABubble> BubbleClass)
{
	FActorSpawnParameters SpawnInfo;
	ABubble* Bubble = Cast<ABubble>(GetWorld()->SpawnActor(BubbleClass, &GetActorTransform(), SpawnInfo));
	BubbleTimers.FindOrAdd(Bubble);
	BubbleTimers[Bubble] = 0;
}
