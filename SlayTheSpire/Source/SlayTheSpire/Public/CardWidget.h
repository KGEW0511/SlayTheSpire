// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardWidget.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API UCardWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	
	UPROPERTY(EditAnywhere)
	class USizeBox* CardNameSizeBox;
	
	UPROPERTY(EditAnywhere)
	class UTextBlock* CardNameText;
	
	UPROPERTY(EditAnywhere)
	USizeBox* ImageSizeBox;
	
	UPROPERTY(EditAnywhere)
	class UImage* CardImage;

	UPROPERTY(EditAnywhere)
	FVector2D DragOffset;
	
	UPROPERTY(EditAnywhere)
	class UDragWidget* DragWidget;

	UPROPERTY(EditAnywhere)
	int32 CardIndex;

	UPROPERTY(EditAnywhere)
	class UTexture2D* CurCardTexture;
};
