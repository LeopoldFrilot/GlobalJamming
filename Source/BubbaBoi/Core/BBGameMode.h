// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BBGameMode.generated.h"

UCLASS()
class BUBBABOI_API ABBGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "+BB")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category = "+BB")
	void DealDamageToPlayer(int Damage);
	
	UFUNCTION(BlueprintCallable, Category = "+BB")
	void DealDamageToBoss(int Damage);

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossHurt, int32, Previous, int32, New);
	UPROPERTY(BlueprintAssignable, Category = "+BB")
	FOnBossHurt OnBossHurt;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerHurt, int32, Previous, int32, New);
	UPROPERTY(BlueprintAssignable, Category = "+BB")
	FOnPlayerHurt OnPlayerHurt;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBossDied);
	UPROPERTY(BlueprintAssignable, Category = "+BB")
	FOnBossDied OnBossDied;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDied);
	UPROPERTY(BlueprintAssignable, Category = "+BB")
	FOnPlayerDied OnPlayerDied;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "+BB")
	int DefaultBossHealth = 1000;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "+BB")
	int DefaultPlayerHealth = 5;

private:
	int CurrentBossHealth = 0;
	int CurrentPlayerHealth = 0;
};
