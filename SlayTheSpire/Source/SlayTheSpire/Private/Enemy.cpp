// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::TakeDamage(float value)
{
	if (true == bIsDebuff)
	{
		value *= 1.5f;
		value = floor(value + 0.5f);
	}

	CurHp -= value;
	
	if (CurHp <= 0)
	{
		CurHp = 0;
		Death();
	}
	UE_LOG(LogTemp, Warning, TEXT("%f"), CurHp);
}

void AEnemy::Death()
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), CurHp);
	
	this->Destroy();
}

void AEnemy::TurnOver()
{
	if (bIsDebuff)
	{
		DebuffDurationTurn -= 0;
		if (DebuffDurationTurn <= 0) bIsDebuff = false;
	}
}

