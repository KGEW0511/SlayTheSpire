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
	
	UPROPERTY(EditAnywhere)
	UUserWidget* WidgetReference;

	UPROPERTY(EditAnywhere)
	class UImage* CardImage;

	UPROPERTY(EditAnywhere)
	class USizeBox* WidgetSizeBox;
};
