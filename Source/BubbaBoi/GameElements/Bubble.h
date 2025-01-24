// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "GameFramework/Actor.h"
#include "Bubble.generated.h"

UCLASS()
class BUBBABOI_API ABubble : public AActor
{
	GENERATED_BODY()

public:
	ABubble();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "+BB")
	void PopBubble();

protected:
	virtual void BeginPlay() override;

private:
};
