// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	
	UPROPERTY(EditAnywhere)
	class UCardWidget* CardWidget0;
	
	UPROPERTY(EditAnywhere)
	class UCardWidget* CardWidget1;
	
	UPROPERTY(EditAnywhere)
	class UCardWidget* CardWidget2;

	UPROPERTY(EditAnywhere)
	int32 CardIndex;
};
