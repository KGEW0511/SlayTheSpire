// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardManager.generated.h"

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
	UFUNCTION()
	void CardShuffle();

	UFUNCTION()
	void CardDrow();

	UFUNCTION()
	void AddCard(int32 index);

	UFUNCTION()
	void UseCard(int32 index);

	UFUNCTION()
	void RemoveCard(int32 index);
	
	TArray<int32> DeckCards;
	TArray<int32> HandCards;
	TArray<int32> DiscardCards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UTexture2D*> CardTextureArray;

	UPROPERTY()
	TMap<int32, UTexture2D*> CardDictionary;

	UFUNCTION(BlueprintCallable)
	UTexture2D* GetCardTexture(int index);
};
