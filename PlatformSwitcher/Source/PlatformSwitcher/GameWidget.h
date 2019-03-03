// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "UMG.h"
#include "UMGStyle.h"
#include "IUMGModule.h"
#include "Slate/SObjectWidget.h"

#include "GameWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMSWITCHER_API UGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Load();

	void OnGameOver(bool win);

	UPROPERTY()
	UTextBlock *MessageText;
	
};
