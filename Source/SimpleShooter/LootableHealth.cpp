// Fill out your copyright notice in the Description page of Project Settings.


#include "LootableHealth.h"

// Sets default values
ALootableHealth::ALootableHealth()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALootableHealth::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALootableHealth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ALootableHealth::GetHealthAmount() const
{
	return HealthAmount;
}

