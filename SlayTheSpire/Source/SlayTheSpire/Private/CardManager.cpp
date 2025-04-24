// Fill out your copyright notice in the Description page of Project Settings.


#include "SlayTheSpire/Public/CardManager.h"

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

	AddCard(1);
	AddCard(2);
	AddCard(3);
	AddCard(4);
	AddCard(5);
	AddCard(6);

	{
		for (int i = 0 ; i < DeckCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DeckCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DeckCards"));

		for (int i = 0 ; i < HandCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), HandCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("HandCards"));
	
		for (int i = 0 ; i < DiscardCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DiscardCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DicardCards"));
	}

	RemoveCard(4);
	RemoveCard(5);
	RemoveCard(6);
	
	{
		for (int i = 0 ; i < DeckCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DeckCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DeckCards"));

		for (int i = 0 ; i < HandCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), HandCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("HandCards"));
	
		for (int i = 0 ; i < DiscardCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DiscardCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DicardCards"));
	}

	CardDrow();

	{
		for (int i = 0 ; i < DeckCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DeckCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DeckCards"));

		for (int i = 0 ; i < HandCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), HandCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("HandCards"));
	
		for (int i = 0 ; i < DiscardCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DiscardCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DicardCards"));
	}
	CardDrow();
	
	{
		for (int i = 0 ; i < DeckCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DeckCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DeckCards"));
	
		for (int i = 0 ; i < HandCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), HandCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("HandCards"));
	
		for (int i = 0 ; i < DiscardCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DiscardCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DicardCards"));
	}
	
	CardDrow();
	
	{
		for (int i = 0 ; i < DeckCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DeckCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DeckCards"));
	
		for (int i = 0 ; i < HandCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), HandCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("HandCards"));
	
		for (int i = 0 ; i < DiscardCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DiscardCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DicardCards"));
	}
	
	UseCard(0);
	UseCard(0);
	UseCard(0);
	
	{
		for (int i = 0 ; i < DeckCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DeckCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DeckCards"));
	
		for (int i = 0 ; i < HandCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), HandCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("HandCards"));
	
		for (int i = 0 ; i < DiscardCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DiscardCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DicardCards"));
	}
	
	CardShuffle();
	
	{
		for (int i = 0 ; i < DeckCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DeckCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DeckCards"));
	
		for (int i = 0 ; i < HandCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), HandCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("HandCards"));
	
		for (int i = 0 ; i < DiscardCards.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d "), DiscardCards[i]);
		}
		UE_LOG(LogTemp, Warning, TEXT("DicardCards"));
	}
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

void ACardManager::UseCard(int32 index)
{
	DiscardCards.Add(HandCards[index]);
	HandCards.RemoveSingle(HandCards[index]);
}