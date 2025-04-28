// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicianGremlin.h"

void AMagicianGremlin::BeginPlay()
{
	Super::BeginPlay();
}

void AMagicianGremlin::Attack(int32 index)
{
	switch(index)
	{
	case 0:
		Charge();
		break;
	case 1:
		MagicAttack();
		break;
	}
}

void AMagicianGremlin::Charge()
{
	UE_LOG(LogTemp, Warning, TEXT("Charge"));
}

void AMagicianGremlin::MagicAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("MagicAttack"));
}

void AMagicianGremlin::StartTurn()
{
	Attack(TurnIndex);
	TurnOver();
}
