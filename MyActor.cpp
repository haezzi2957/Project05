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
	move(); // -> ����� �̵�
	// �� �̺�Ʈ �߻� Ƚ�� ���
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
    //x, y �ʱ�ȭ
    int32 x = 0;
    int32 y = 0;

    UE_LOG(LogTemp, Error, TEXT("Step 0 : X = %d, Y = %d"), x, y);
    for (int32 i = 1; i <= 10; i++)
    {
        //���� x, y���� ����
        int32 prevX = x;
        int32 prevY = y;

        // 0 �Ǵ� 1 ��ŭ �̵�
        x += step();
        y += step();

        //float dis = FVector2D::Distance(FVector2D(prevX,prevY), FVector2D(x,y))
        float dis = distance(FVector2D(prevX, prevY), FVector2D(x, y)); //�̵� �Ÿ� ���
        totDist += dis; // �� �̵� �Ÿ��� �����ش�

        // ��� ���� 
        // -> LogTemp: Warning: Step  [i] : X = [prevX], Y = [prevY] -> X = [x], Y = [y] | distance : [dis]
        // %2d  -> ��°�� �ڸ����� 2�ڸ��� �����ϰ� ����� �������� ä���  ex) [ 1]
        // %02d -> ��°�� �ڸ����� 2�ڸ��� �����ϰ� ����� 0���� ä���     ex) [01]
        // %0.2f -> ��°�� �Ҽ��� 2�ڸ����� ������ �Ѵ�. ex) [0.00]
        UE_LOG(LogTemp, Warning,
            TEXT("Step %2d : X = %d, Y = %d -> X = %d, Y = %d | distance : %0.2f "), i, prevX, prevY, x, y, dis);

        // �̺�Ʈ�� �߻��ߴ��� ���ϰ����� Ȯ�� �� ���
        // ->LogTemp: Warning: Event!
        if (creatEvent() == 1) {
            UE_LOG(LogTemp, Warning, TEXT("Event!"));
        }
    }
    // �� �̵� �Ÿ� ���
    // LogTemp: Error: totDist : [totDist]
    UE_LOG(LogTemp, Error, TEXT("totDist : %0.2f"), totDist);
}

int32 AMyActor::step()
{
    // ���� 0 ~ 1 ����
    return FMath::RandRange(0, 1);
}

int32 AMyActor::creatEvent()
{
    // ���� 0 ~ 1
    int event = FMath::RandRange(0, 1);

    // �̺�Ʈ�� �߻��ϸ� �� �̺�Ʈ�� 1�����ϰ� 1�� �����Ѵ�
    if (event == 1) {
        ++evCnt;
        return 1;
    }
    // �߻����� �ʾҴٸ� 0�� �����Ѵ�
    return 0;
}


