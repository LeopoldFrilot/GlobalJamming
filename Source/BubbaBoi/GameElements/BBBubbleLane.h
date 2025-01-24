// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bubble.h"
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
	
	UFUNCTION(BlueprintCallable, Category = "+BB")
	void SpawnBubble(TSubclassOf<ABubble> BubbleClass);

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "+BB")
	USplineComponent* Spline;

private:
	UPROPERTY(EditAnywhere, Category = "+BB")
	float TimeToEnd = 10.f;
	
	TMap<TObjectPtr<ABubble>, float> BubbleTimers;
};
