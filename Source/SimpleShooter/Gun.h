// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();
	// used in ShooterCharacter
	void Reload();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// used in ShooterCharacter
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
	USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
	USoundBase* ImpactSound;

	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactEffect;
	
	UPROPERTY(EditAnywhere)
	float MaxRange = 1000.f;

	UPROPERTY(EditAnywhere)
	float Damage = 10.f;

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	int TotalAmmo = 50;
	
	UPROPERTY(EditAnywhere, Category = "Weapon")
	int MagazineAmmo = 30;

	int CurrentMagazineAmmo;

	UFUNCTION(BlueprintPure)
	FText GetAmmoInfo() const;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	USoundBase* ReloadSound;

	void ResetCanReload();

	UPROPERTY(EditAnywhere, Category = "Combat")
	bool bCanReload = true;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	float ReloadTime = 3.f;

	FTimerHandle ReloadTimerHandle;
	

};
