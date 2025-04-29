// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardManager.generated.h"

UENUM()
enum ECardType
{
	Attack,
	Skill,
	Power
};

USTRUCT()
struct FCardInfo
{
	GENERATED_BODY()
	
	FString CardName;
	UTexture2D* CardImage;
	ECardType CardType;
	int32 CardCost;
};

UCLASS()
class SLAYTHESPIRE_API ACardManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACardManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	void CardShuffle();

	UFUNCTION(BlueprintCallable)
	void CardDrow();

	UFUNCTION(BlueprintCallable)
	void AddCard(int32 index);

	UFUNCTION(BlueprintCallable)
	void UseCard(int32 index);

	UFUNCTION(BlueprintCallable)
	void RemoveCard(int32 index);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ASlayPlayer* player;
	
	TArray<int32> DeckCards;
	TArray<int32> HandCards;
	TArray<int32> DiscardCards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UTexture2D*> CardTextureArray;
	
	UPROPERTY(EditAnywhere)
	TMap<int32, FCardInfo> CardDictionary;

	UFUNCTION(BlueprintCallable)
	UTexture2D* GetCardTexture(int index);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AEnemy* enemy;
};
