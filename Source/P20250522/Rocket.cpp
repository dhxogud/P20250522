// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocket.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFrameWork/ProjectileMovementComponent.h"

// Sets default values
ARocket::ARocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/ Script / Engine.StaticMesh'/Game/Resources/SM_Rocket.SM_Rocket'"));

	if (SM_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_Body.Object);
	}
	Body->SetupAttachment(Box);
	Body->AddRelativeRotation(FRotator(0.0f, 0.0f, -90.0f));

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));

	MoveSpeed = 2000.0f;

	Movement->InitialSpeed = MoveSpeed;
	Movement->MaxSpeed = MoveSpeed;
}

// Called when the game starts or when spawned
void ARocket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

