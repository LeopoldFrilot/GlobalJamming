﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "BBBoss.generated.h"

UCLASS()
class BUBBABOI_API ABBBoss : public ACharacter
{
	GENERATED_BODY()

public:
	ABBBoss();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	
};
