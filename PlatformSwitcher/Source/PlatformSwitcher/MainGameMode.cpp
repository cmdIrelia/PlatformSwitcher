// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Character.h>
#include "GameWidget.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->InputComponent
		->BindAction("Switch", IE_Pressed, this, &AMainGameMode::OnSwitch);

	Switched = false;

	ChangeMenuWidget(StartingWidgetClass);
	((UGameWidget*)CurrentWidget)->Load();
}

void AMainGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainGameMode::OnSwitch()
{
	if (Switched) {
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
		NewLocation.X = 1200.f;
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorLocation(NewLocation);
	}
	else {
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
		NewLocation.X = 370.f;
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorLocation(NewLocation);
	}
	Switched = !Switched;
}

void AMainGameMode::OnGameOver(bool win)
{
	((UGameWidget*)CurrentWidget)->OnGameOver(win);
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void AMainGameMode::ChangeMenuWidget(TSubclassOf<class UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr) {
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr) {
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);

		if (CurrentWidget != nullptr) {
			CurrentWidget->AddToViewport();
		}
	}
}

void AMainGameMode::OnRestart()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRestart."));
}
