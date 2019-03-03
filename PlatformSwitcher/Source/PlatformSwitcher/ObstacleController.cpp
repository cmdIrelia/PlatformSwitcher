// Fill out your copyright notice in the Description page of Project Settings.

#include "ObstacleController.h"

#include <Components/BoxComponent.h>
#include <Components/PrimitiveComponent.h>
#include "Kismet/GameplayStatics.h"
#include "MainGameMode.h"
#include "GameFramework/Character.h"

// Sets default values
AObstacleController::AObstacleController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootBox->SetGenerateOverlapEvents(true);
	RootBox->OnComponentBeginOverlap.AddDynamic(this, &AObstacleController::OnOverlap);
	SetRootComponent(RootBox);

}

// Called when the game starts or when spawned
void AObstacleController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacleController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacleController::OnOverlap(UPrimitiveComponent *OverlapComponent,
	AActor *OtherActor,
	UPrimitiveComponent *OtherComponent,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)) {

		float time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Player Overlap on %s. Game Loss."), time, *GetName());

		//ÓÎÏ·½áÊø
		((AMainGameMode*)GetWorld()->GetAuthGameMode())->OnGameOver(false);

		//UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}
