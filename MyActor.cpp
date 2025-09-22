#include "MyActor.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h" // AMyactor 클래스를 포함
#include "Math/UnrealMathUtility.h" // 난수 및 수학함수 사용

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
		// 현재 위치 가져오기
		FVector CurrentLocation = GetActorLocation();

		// 랜덤 이동 범위 설정
		float MaxMoveDistance = 1.0; // 최대 1 유닛 이동
		float MoveAmountX = FMath::Floor(FMath::FRandRange(-MaxMoveDistance, MaxMoveDistance)); // X축 1씩 랜덤 이동
		float MoveAmountY = FMath::FRandRange(-MaxMoveDistance, MaxMoveDistance); // Y축 소수점 까지 랜덤 이동

		//int MaxMoveDistance = 1.0; // 최대 1 유닛 이동
		//int MoveAmountX = FMath::RandRange(-MaxMoveDistance, MaxMoveDistance); // X축 랜덤 이동
		//int MoveAmountY = FMath::RandRange(-MaxMoveDistance, MaxMoveDistance); // Y축 랜덤 이동


		// 새로운 위치 계산
		FVector NewLocation = CurrentLocation + FVector(MoveAmountX, MoveAmountY, 0.0f);

		// 액터 이동
		SetActorLocation(NewLocation);

		// 이동 위치 로그 출력
		UE_LOG(LogTemp, Warning, TEXT("Actor moved to: %s"), *NewLocation.ToString());
	}
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

