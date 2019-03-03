// Fill out your copyright notice in the Description page of Project Settings.

#include "GameWidget.h"
#include <iostream>

void UGameWidget::Load()
{
	const FName TextBlockName = FName(TEXT("MessageBox"));
	if (MessageText == nullptr) {
		MessageText = (UTextBlock*)(WidgetTree->FindWidget(TextBlockName));
		MessageText->SetText(FText::FromString(FString(TEXT("Run Gump!"))));
	}
}

void UGameWidget::OnGameOver(bool win)
{
	if (MessageText != nullptr) {
		if (win == true) {
			MessageText->SetText(FText::FromString(FString(TEXT("You Win!\nPress R to play again."))));
		}
		else {
			MessageText->SetText(FText::FromString(FString(TEXT("Failed\nPress R to try again."))));
		}
	}
}
