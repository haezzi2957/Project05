// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECT05_API AMyActor : public AActor
{
	GENERATED_BODY()
	int32 evCnt = 0; // 총 이벤트 발생 횟수
	float totDist = 0; // 총 이동 거리 

public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float distance(FVector2D first, FVector2D second); //distance 커스텀 함수
	void move(); // 이동
	int32 step(); // 이동거리
	int32 creatEvent(); // 이벤트
};
