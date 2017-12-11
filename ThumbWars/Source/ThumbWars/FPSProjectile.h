// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime\Engine\Classes\Components\StaticMeshComponent.h"
#include "Runtime\Engine\Classes\GameFramework\ProjectileMovementComponent.h"
#include "FPSProjectile.generated.h"

UCLASS()
class THUMBWARS_API AFPSProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleDefaultOnly)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleDefaultOnly)
	UStaticMeshComponent* CollisionMesh;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void FireInDirection(const FVector& ShootDirection);
};
