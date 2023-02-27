// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LootableAmmo.generated.h"

UCLASS()
class SIMPLESHOOTER_API ALootableAmmo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALootableAmmo();

	UFUNCTION()
	int GetAmmoAmount() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "AmmoType")
	FString AmmoType = "";

private:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
	int AmmoAmount;
	// match the gun class (shotgun, rifle etc.)
	

};
