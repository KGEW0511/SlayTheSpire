// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DragWidget.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API UDragWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	UPROPERTY()
	UUserWidget* WidgetReference;

	UPROPERTY(meta=(BindWidget))
	class UImage* CardAfterImage;

	UPROPERTY(meta=(BindWidget))
	class USizeBox* WidgetSize;
};
