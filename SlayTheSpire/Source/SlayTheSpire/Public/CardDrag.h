// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "CardDrag.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API UCardDrag : public UDragDropOperation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UUserWidget* WidgetReference;

	UPROPERTY(EditAnywhere)
	FVector2D DragOffset;

	UPROPERTY(EditAnywhere)
	int32 CardIndex;
};
