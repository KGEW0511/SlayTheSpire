// Fill out your copyright notice in the Description page of Project Settings.


#include "SlayTheSpire/Public/SlayPlayer.h"

#include "CardManager.h"
#include "Enemy.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASlayPlayer::ASlayPlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASlayPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlayPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlayPlayer::Attack(int index)
{
	targetEnemy = cardManager->enemy;
	
	switch (index)
	{
	case 1001:
		targetEnemy->TakeDamage(1);
		break;
	case 1002:
		targetEnemy->TakeDamage(1);
		break;
	}
}

void ASlayPlayer::Damage(int value)
{
	if (bIsDebuff)
	{
		value *= 1.5f;
		value = floor(value + 0.5f);
	}

	CurHp -= value;

	if (CurHp <= 0)
	{
		CurHp = 0;
		
	}
}

