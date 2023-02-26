// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"


class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SwitchGunNext();

public:	

	UFUNCTION(BlueprintPure)
	// check if the player is dead
	bool IsDead() const;
	
	
	// to add shooting animation
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
	bool bIsShooting;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
	float ShootAnimationFlagDelay = 0.1f;
	
	FTimerHandle ShootAnimationTimerHandle;

	void ResetIsShooting();

	// 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Combat")
	bool bCanShoot = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Combat")
	float ShootCooldown = 0.8f;

	void ResetCanShoot();



	FTimerHandle ShootCooldownTimerHandle;
	

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;
	
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void Shoot();

	UFUNCTION(BlueprintCallable)
	AGun* CurrentGun() const;

	UFUNCTION(BlueprintCallable)
	void PickUpGun(AGun* GunToPickUp);

	UFUNCTION(BlueprintCallable)
	void PickUpHealth(ALootableHealth* LootableHealth);

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Weapon")
	TArray<AGun*> Guns;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	// function to zoom in and out
	void ZoomInOut();



	UPROPERTY(EditAnywhere)
	float RotationRate = 10.f;
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere)
	float Health;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

	UPROPERTY()
	ALootableHealth* LooatableHealth;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AGun>> GunClasses;

	
	int ActiveGunIndex;


	// Input component to handle gun functions
	UInputComponent* PlayerInputComponent2;
	void GunInputBindings();



	

	

	

	

	


	

};
