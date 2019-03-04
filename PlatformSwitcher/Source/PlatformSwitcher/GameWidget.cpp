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

	const FName TimerBlockName = FName(TEXT("TimerTextBlock"));
	if (TimerText == nullptr) {
		TimerText = (UTextBlock*)(WidgetTree->FindWidget(TimerBlockName));
		TimerText->SetText(FText::FromString(FString::Printf(TEXT("%.2f"), 0)));
	}

	const FName HowToTextName = FName(TEXT("HowToTextBlock"));
	if (HowToText == nullptr) {
		HowToText = (UTextBlock*)(WidgetTree->FindWidget(HowToTextName));
		HowToText->SetText(FText::FromString(
			FString(TEXT("Press R to switch platform\nArrow keys to Move and Space key to jump\nTab to restart\nAvoid RED blocks and run to purple blocks.\nGood Luck!"))));
	}
}

void UGameWidget::OnGameOver(bool win)
{
	if (MessageText != nullptr) {
		if (win == true) {
			MessageText->SetText(FText::FromString(FString(TEXT("You Win!\nPress Tab to play again."))));
		}
		else {
			MessageText->SetText(FText::FromString(FString(TEXT("Failed\nPress Tab to try again."))));
		}
	}
}

void UGameWidget::SetTimer(float time)
{
	if (TimerText != nullptr) {
		TimerText->SetText(FText::FromString(FString::Printf(TEXT("%.2f"), time)));
	}
}
