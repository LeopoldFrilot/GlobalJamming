// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "GameFramework/Actor.h"
#include "BBBubbleLane.generated.h"

UCLASS()
class BUBBABOI_API ABBBubbleLane : public AActor
{
	GENERATED_BODY()

public:
	ABBBubbleLane();
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void SpawnItem(AActor* ActorToSpawn);

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	USplineComponent* Spline;
};
