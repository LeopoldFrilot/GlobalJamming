// Fill out your copyright notice in the Description page of Project Settings.


#include "BBGameMode.h"

void ABBGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ABBGameMode::StartGame()
{
	CurrentBossHealth = DefaultBossHealth;
	CurrentPlayerHealth = DefaultPlayerHealth;
}

void ABBGameMode::DealDamageToPlayer(int Damage)
{
	if (CurrentPlayerHealth <= 0)
	{
		return;
	}

	int32 PrevDamage = CurrentPlayerHealth;
	CurrentPlayerHealth -= Damage;
	OnPlayerHurt.Broadcast(PrevDamage, CurrentPlayerHealth);
	if (CurrentPlayerHealth <= 0)
	{
		OnPlayerDied.Broadcast();
	}
}

void ABBGameMode::DealDamageToBoss(int Damage)
{
	if (CurrentBossHealth <= 0)
	{
		return;
	}
	
	int32 PrevDamage = CurrentBossHealth;
	CurrentBossHealth -= Damage;
	OnBossHurt.Broadcast(PrevDamage, CurrentBossHealth);
	if (CurrentBossHealth <= 0)
	{
		OnBossDied.Broadcast();
	}
}
