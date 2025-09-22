#include "MyActor.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h" // AMyactor Ŭ������ ����
#include "Math/UnrealMathUtility.h" // ���� �� �����Լ� ���

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	FVector StartLocation = FVector(0.0f);
	SetActorLocation(StartLocation);

	for (int32 Step = 1; Step <= 10; ++Step)
	{
		// ���� ��ġ ��������
		FVector CurrentLocation = GetActorLocation();

		// ���� �̵� ���� ����
		float MaxMoveDistance = 1.0; // �ִ� 1 ���� �̵�
		float MoveAmountX = FMath::Floor(FMath::FRandRange(-MaxMoveDistance, MaxMoveDistance)); // X�� 1�� ���� �̵�
		float MoveAmountY = FMath::FRandRange(-MaxMoveDistance, MaxMoveDistance); // Y�� �Ҽ��� ���� ���� �̵�

		//int MaxMoveDistance = 1.0; // �ִ� 1 ���� �̵�
		//int MoveAmountX = FMath::RandRange(-MaxMoveDistance, MaxMoveDistance); // X�� ���� �̵�
		//int MoveAmountY = FMath::RandRange(-MaxMoveDistance, MaxMoveDistance); // Y�� ���� �̵�


		// ���ο� ��ġ ���
		FVector NewLocation = CurrentLocation + FVector(MoveAmountX, MoveAmountY, 0.0f);

		// ���� �̵�
		SetActorLocation(NewLocation);

		// �̵� ��ġ �α� ���
		UE_LOG(LogTemp, Warning, TEXT("Actor moved to: %s"), *NewLocation.ToString());
	}
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

