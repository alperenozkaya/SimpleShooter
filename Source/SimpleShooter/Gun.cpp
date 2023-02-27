// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);


}

void AGun::PullTrigger()
{
	if (CurrentMagazineAmmo <= 0) return;
	else
	{
		
		UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
		UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
		FHitResult Hit;
		FVector ShotDirection;
		bool bSuccess = GunTrace(Hit, ShotDirection);
		if (bSuccess)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, Hit.Location);
			
			AActor* HitActor = Hit.GetActor();
			if (HitActor != nullptr)
			{
				FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
				AController* OwnerController = GetOwnerController();
				HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
			}
		}
		TotalAmmo--;
		CurrentMagazineAmmo--;
	}
	UE_LOG(LogTemp, Display, TEXT("Total Remaining ammos are %i"), TotalAmmo);
	UE_LOG(LogTemp, Display, TEXT("CurrentMagazine ammos are %i"), CurrentMagazineAmmo);
				
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	TotalAmmo = MaxAmmo;
	CurrentMagazineAmmo = MagazineAmmo;
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// drop gun

	if (bIsDropping)
	{
		FHitResult Hit;
		FVector Start = GetActorLocation();
		FVector End = Start + FVector(0, 0, -400);
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());
		bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
		// if the gun arrives at the hit location, stop dropping
		if (GetActorLocation().Z <= Hit.Location.Z)
		{
			bIsDropping = false;
		}

		else if (bSuccess)
		{
			SetActorLocation(FMath::VInterpTo(Start, Hit.Location, DeltaTime, 5.f));

		}
		
	}

}

USkeletalMeshComponent* AGun::GetMesh() const
{
	return Mesh;
}

void AGun::SetIsDropping(bool IsDropping)
{
	bIsDropping = IsDropping;
}


bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr)  return false;

	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShotDirection = -Rotation.Vector();

	FVector End = Location + Rotation.Vector() * MaxRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr)  return nullptr;
	return OwnerPawn->GetController();
	
}

FText AGun::GetAmmoInfo() const
{
	FText InfoText = FText::FromString(FString::Printf(TEXT("%i / %i"), CurrentMagazineAmmo, TotalAmmo - CurrentMagazineAmmo));
	return InfoText;
}


void AGun::Reload()
{
	if (TotalAmmo <= 0) return;
	else
	{
		if (bCanReload)
		{
			bCanReload = false;
			GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &AGun::ResetCanReload, ReloadTime, false);
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), ReloadSound, GetActorLocation());
		
			int AmmosRemainingInMagazine = MagazineAmmo - CurrentMagazineAmmo;
			int RemainingReloadableAmmos = TotalAmmo - CurrentMagazineAmmo;
			int ReloadableAmmos = FMath::Min(AmmosRemainingInMagazine, RemainingReloadableAmmos);

			CurrentMagazineAmmo += ReloadableAmmos;
		}
		
	}
	UE_LOG(LogTemp, Warning, TEXT("Total ammos are %i"), TotalAmmo);
	UE_LOG(LogTemp, Warning, TEXT("Current Magazine Ammos are %i"), CurrentMagazineAmmo);
}

int AGun::GetCurrentMagazineAmmo() const
{
	return CurrentMagazineAmmo;
}

void AGun::Drop()
{
	// Detach the gun from shooter character and drop it to the ground
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	bIsDropping = true;	

}

void AGun::ResetCanReload()
{
	bCanReload = true;
}

void AGun::DropGunInterp()
{
		
}



