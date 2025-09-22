#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECT5_2_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();

	// 무브랜덤 함수선언 추가

	void MoveRandomly();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyProperties")
	float MyFloatValue;  // 에디터에서 수정 가능하고 블루프린트에서 읽기.쓰기 가능한 float 변수

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
