// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterGameModeBase.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/InputComponent.h"


// Sets default values
AShooterCharacter::AShooterCharacter()
{
	ActiveGunIndex = 0;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	UE_LOG(LogTemp, Display, TEXT("BeginPlay is run"));
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	// attach guns in gun array
	Guns.SetNum(GunClasses.Num());
	for (int i = 0; i < GunClasses.Num(); i++)
	{
		Gun = GetWorld()->SpawnActor<AGun>(GunClasses[i]);
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
		Gun->SetOwner(this);

		Guns[i] = Gun;
	}

	// initialize the first gun
	
	GunInputBindings();
	
	// TODO: hide all other guns
	
	/* Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this); */
}

bool AShooterCharacter::IsDead() const
{
	return Health <= 0;
}


float AShooterCharacter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// hide all guns except the current one
	for (int i = 0; i < Guns.Num(); i++)
	{
		Guns[i]->SetActorHiddenInGame(true);
		Guns[i]->SetActorEnableCollision(false);
	}
	Guns[ActiveGunIndex]->SetActorHiddenInGame(false);
	Guns[ActiveGunIndex]->SetActorEnableCollision(true);

}



// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AShooterCharacter::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AShooterCharacter::LookRightRate);
	// no need for EInputEvent::IE_Pressed, because it's the default
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &AShooterCharacter::Shoot);

	PlayerInputComponent->BindAction(TEXT("SwitchGunNext"), IE_Pressed, this, &AShooterCharacter::SwitchGunNext);
	

}

float AShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health left: %f"), Health);

	if (IsDead())
	{
		ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}

		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			
	}

	return DamageToApply;

}

void AShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AShooterCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AShooterCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::ZoomInOut()
{
	
}

void AShooterCharacter::GunInputBindings()
{
	PlayerInputComponent2 = GetWorld()->GetFirstPlayerController()->FindComponentByClass<UInputComponent>();
    if (PlayerInputComponent2)
    {
		// first clear binding to avoid multiple bindings
		PlayerInputComponent2->ClearActionBindings();
        if (Guns.IsValidIndex(ActiveGunIndex))
		{
			AGun* ActiveGun = Guns[ActiveGunIndex];
			PlayerInputComponent2->BindAction(TEXT("Reload"), IE_Pressed, ActiveGun, &AGun::Reload);
		}
    }
}


void AShooterCharacter::SwitchGunNext()
{
	if (Guns[ActiveGunIndex])
	{
		if(ActiveGunIndex < Guns.Num() - 1)
		{
			ActiveGunIndex++;
		}
		else
		{
			ActiveGunIndex = 0;				
		}
	}
	GunInputBindings();
}


void AShooterCharacter::Shoot()
{
	UE_LOG(LogTemp, Display, TEXT("Shoot is called"));
	// return true for animation
	if (bCanShoot)
	{
		bCanShoot = false;
		GetWorld()->GetTimerManager().SetTimer(ShootCooldownTimerHandle, this, &AShooterCharacter::ResetCanShoot, ShootCooldown, false);
		Guns[ActiveGunIndex]->PullTrigger();
	}
	else return;
		
}

void AShooterCharacter::ResetCanShoot()
{
	bCanShoot = true;
}








