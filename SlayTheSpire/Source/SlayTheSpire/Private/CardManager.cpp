// Fill out your copyright notice in the Description page of Project Settings.


#include "SlayTheSpire/Public/CardManager.h"

#include "Enemy.h"
#include "SlayPlayer.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACardManager::ACardManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACardManager::BeginPlay()
{
	Super::BeginPlay();
	
	CardDictionary.Add(1001 ,FCardInfo{FString(TEXT("Attack")),CardTextureArray[0],ECardType::Attack,1});
	CardDictionary.Add(1002 ,FCardInfo{FString(TEXT("Shield")),CardTextureArray[1],ECardType::Skill,2});
	
	AddCard(1001);
	AddCard(1001);
	AddCard(1002);
	AddCard(1002);

	CardDrow();
	CardDrow();
	CardDrow();
}

// Called every frame
void ACardManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACardManager::CardShuffle()
{
	DeckCards.Append(DiscardCards);
	for (int32 i = 0; i < DeckCards.Num(); i++)
	{
		int32 RandomIndex = FMath::RandRange(0, i);
		
		if (i != RandomIndex)
		{
			DeckCards.Swap(i, RandomIndex);
		}
	}
	DiscardCards.Empty();
}

void ACardManager::CardDrow()
{
	if (DeckCards.Num() == 0)
	{
		CardShuffle();
	}
	
	HandCards.Add(DeckCards[0]);
	DeckCards.RemoveAt(0);
}

void ACardManager::AddCard(int32 index)
{
	DeckCards.Add(index);
}

void ACardManager::RemoveCard(int32 index)
{
	DeckCards.RemoveSingle(index);
}

void ACardManager::TurnOver()
{
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AEnemy::StaticClass(),actors);

	for (AActor* actor : actors)
	{
		enemy = Cast<AEnemy>(actor);
		if (enemy)
		{
			enemy->Attack(player);
		}
	}

	player-> CurCost = player-> MaxCost;
}

FCardInfo ACardManager::GetCard(int index)
{
	return CardDictionary[HandCards[index]];
}

void ACardManager::UseCard(int32 index)
{
	if (player->CurCost < CardDictionary[HandCards[index]].CardCost)
		return;
	
	player->Attack(HandCards[index]);
	DiscardCards.Add(HandCards[index]);
	HandCards.RemoveSingle(HandCards[index]);
}
