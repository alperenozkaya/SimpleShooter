// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Gun.h"
#include "LootableHealth.h"
#include "LootableAmmo.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterGameModeBase.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/InputComponent.h"
#include "Animation/AnimSequence.h"
#include "Components/SkeletalMeshComponent.h"


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
		Gun->Children.Empty();

		Guns[i] = Gun;
	}

	GunInputBindings();

	
	// initialize the first gun
	for (int i = 0; i < Guns.Num(); i++)
	{
		Guns[i]->SetActorHiddenInGame(true);
		Guns[i]->SetActorEnableCollision(false);
	}
	Guns[ActiveGunIndex]->SetActorHiddenInGame(false);
	Guns[ActiveGunIndex]->SetActorEnableCollision(true);

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
		Guns[ActiveGunIndex]->Drop();
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
	else return;
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
	
	else return ;
	GunInputBindings();
	UE_LOG(LogTemp, Display, TEXT("SwitchGunNext is called, index is: %d"), ActiveGunIndex);

	// hide all guns except the current one
	for (int i = 0; i < Guns.Num(); i++)
	{
		Guns[i]->SetActorHiddenInGame(true);
		Guns[i]->SetActorEnableCollision(false);
	}
	Guns[ActiveGunIndex]->SetActorHiddenInGame(false);
	Guns[ActiveGunIndex]->SetActorEnableCollision(true);
}


void AShooterCharacter::Shoot()
{
	UE_LOG(LogTemp, Display, TEXT("Shoot is called"));
	// return true for animation
	if (bCanShoot && Guns[ActiveGunIndex]->GetCurrentMagazineAmmo() > 0)
	{
		
		bCanShoot = false;
		bIsShooting = true;
		Guns[ActiveGunIndex]->PullTrigger();
		GetWorld()->GetTimerManager().SetTimer(ShootAnimationTimerHandle, this, &AShooterCharacter::ResetIsShooting, ShootAnimationFlagDelay, false);
		
		
		// play shoot animation additively
		// TODO: implement it as blueprint function	

		GetWorld()->GetTimerManager().SetTimer(ShootCooldownTimerHandle, this, &AShooterCharacter::ResetCanShoot, ShootCooldown, false);	
	}
	else
	{
		
		return;
	} 
		
}

void AShooterCharacter::ResetIsShooting()
{
	bIsShooting = false;
}

AGun* AShooterCharacter::CurrentGun() const
{
	return Guns[ActiveGunIndex];
}

void AShooterCharacter::PickUpGun(AGun* GunToPickUp)
{
	if (GunToPickUp == nullptr) return;
	GunToPickUp->SetIsDropping(false);  // set isDropping to false to avoid dropping the gun when it's picked up
	Guns.Add(GunToPickUp);
	ActiveGunIndex = Guns.Num() - 1;
	GunToPickUp->GetMesh()->SetSimulatePhysics(false);
	GunToPickUp->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("WeaponSocket"));
	GunToPickUp->SetOwner(this);
	
	GunInputBindings();

	// hide all guns except the current one
	for (int i = 0; i < Guns.Num(); i++)
	{
		Guns[i]->SetActorHiddenInGame(true);
		Guns[i]->SetActorEnableCollision(false);
	}
	Guns[ActiveGunIndex]->SetActorHiddenInGame(false);
	Guns[ActiveGunIndex]->SetActorEnableCollision(true);


}

void AShooterCharacter::PickUpHealth(ALootableHealth* LootableHealth)
{
	if (LootableHealth == nullptr || Health == MaxHealth) return;
	float NewHealth = Health + LootableHealth->GetHealthAmount();
	if (NewHealth > MaxHealth)
	{
		Health = MaxHealth;
	}
	else
	{
		Health = NewHealth;
	}
	LootableHealth->Destroy();
}

void AShooterCharacter::PickUpAmmo(ALootableAmmo* LootableAmmo)
{

	if (LootableAmmo == nullptr || Guns[ActiveGunIndex]->TotalAmmo == Guns[ActiveGunIndex]->MaxAmmo || Guns[ActiveGunIndex]->GunAmmoType != LootableAmmo->AmmoType) return;
	int NewAmmo = Guns[ActiveGunIndex]->TotalAmmo + LootableAmmo->GetAmmoAmount();
	if (NewAmmo > Guns[ActiveGunIndex]->MaxAmmo)
	{
		Guns[ActiveGunIndex]->TotalAmmo = Guns[ActiveGunIndex]->MaxAmmo;
	}
	else
	{
		Guns[ActiveGunIndex]->TotalAmmo = NewAmmo;
	}
	LootableAmmo->Destroy();
}

void AShooterCharacter::ResetCanShoot()
{	
	bCanShoot = true;
	// TODO: change shoot animation implementation
}








