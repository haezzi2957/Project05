// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	move(); // -> 무브로 이동
	// 총 이벤트 발생 횟수 출력
	// LogTemp: Error: TotalEvent: [evCnt]
	UE_LOG(LogTemp, Error, TEXT("TotalEvent: %d"), evCnt);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

void AMyActor::move()
{
    //x, y 초기화
    int32 x = 0;
    int32 y = 0;

    UE_LOG(LogTemp, Error, TEXT("Step 0 : X = %d, Y = %d"), x, y);
    for (int32 i = 1; i <= 10; i++)
    {
        //이전 x, y값을 저장
        int32 prevX = x;
        int32 prevY = y;

        // 0 또는 1 만큼 이동
        x += step();
        y += step();

        //float dis = FVector2D::Distance(FVector2D(prevX,prevY), FVector2D(x,y))
        float dis = distance(FVector2D(prevX, prevY), FVector2D(x, y)); //이동 거리 계산
        totDist += dis; // 총 이동 거리에 더해준다

        // 출력 예상 
        // -> LogTemp: Warning: Step  [i] : X = [prevX], Y = [prevY] -> X = [x], Y = [y] | distance : [dis]
        // %2d  -> 출력결과 자리수를 2자리로 설정하고 빈곳은 공백으로 채운다  ex) [ 1]
        // %02d -> 출력결과 자리수를 2자리로 설정하고 빈곳은 0으로 채운다     ex) [01]
        // %0.2f -> 출력결과 소수점 2자리까지 나오게 한다. ex) [0.00]
        UE_LOG(LogTemp, Warning,
            TEXT("Step %2d : X = %d, Y = %d -> X = %d, Y = %d | distance : %0.2f "), i, prevX, prevY, x, y, dis);

        // 이벤트가 발생했는지 리턴값으로 확인 후 출력
        // ->LogTemp: Warning: Event!
        if (creatEvent() == 1) {
            UE_LOG(LogTemp, Warning, TEXT("Event!"));
        }
    }
    // 총 이동 거리 출력
    // LogTemp: Error: totDist : [totDist]
    UE_LOG(LogTemp, Error, TEXT("totDist : %0.2f"), totDist);
}

int32 AMyActor::step()
{
    // 랜덤 0 ~ 1 리턴
    return FMath::RandRange(0, 1);
}

int32 AMyActor::creatEvent()
{
    // 랜덤 0 ~ 1
    int event = FMath::RandRange(0, 1);

    // 이벤트가 발생하면 총 이벤트가 1증가하고 1로 리턴한다
    if (event == 1) {
        ++evCnt;
        return 1;
    }
    // 발생하지 않았다면 0을 리턴한다
    return 0;
}


