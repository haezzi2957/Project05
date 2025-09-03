// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECT05_API AMyActor : public AActor
{
	GENERATED_BODY()
	int32 evCnt = 0; // �� �̺�Ʈ �߻� Ƚ��
	float totDist = 0; // �� �̵� �Ÿ� 

public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float distance(FVector2D first, FVector2D second); //distance Ŀ���� �Լ�
	void move(); // �̵�
	int32 step(); // �̵��Ÿ�
	int32 creatEvent(); // �̺�Ʈ
};
