// Fill out your copyright notice in the Description page of Project Settings.

#include "SpherePawnUlt.h"

#include "Classes/Components/InputComponent.h"
#include "Classes/GameFramework/FloatingPawnMovement.h"
#include "Classes/Camera/CameraComponent.h"
#include "Classes/Components/StaticMeshComponent.h"

// Sets default values
ASpherePawnUlt::ASpherePawnUlt()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");

	Camera = CreateDefaultSubobject<UCameraComponent>("CameraCompenent");
	Camera->SetRelativeLocation(FVector(-500.f, 0.f, 0.f));
	Camera->SetupAttachment(StaticMesh);

	SetRootComponent(StaticMesh);

}

// Called when the game starts or when spawned
void ASpherePawnUlt::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpherePawnUlt::MoveForward(float Amount){
	FloatingPawnMovement->AddInputVector(GetActorForwardVector()*Amount);
}

void ASpherePawnUlt::MoveRight(float Amount){
	FloatingPawnMovement->AddInputVector(GetActorRightVector()*Amount);
}

void ASpherePawnUlt::Turn(float Amount){
	//AddControllerYawInput();
}

void ASpherePawnUlt::LookUp(float Amount){
}

// Called every frame
void ASpherePawnUlt::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpherePawnUlt::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASpherePawnUlt::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASpherePawnUlt::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ASpherePawnUlt::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASpherePawnUlt::LookUp);
}

