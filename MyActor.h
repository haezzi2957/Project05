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

	// ���귣�� �Լ����� �߰�

	void MoveRandomly();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyProperties")
	float MyFloatValue;  // �����Ϳ��� ���� �����ϰ� �������Ʈ���� �б�.���� ������ float ����

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
