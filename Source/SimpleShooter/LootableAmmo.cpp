// Fill out your copyright notice in the Description page of Project Settings.


#include "LootableAmmo.h"
#include "Components/StaticMeshComponent.h"
#include "Gun.h"


// Sets default values
ALootableAmmo::ALootableAmmo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int ALootableAmmo::GetAmmoAmount() const
{
	return AmmoAmount;
}

// Called when the game starts or when spawned
void ALootableAmmo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALootableAmmo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

