#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GhostActor.generated.h"

class UPoseableMeshComponent;
class UMaterialInterface;

UCLASS(BlueprintType)
class AGhostActor : public AActor
{
	GENERATED_BODY()

public:

	AGhostActor(const FObjectInitializer& ObjectInitializer);

	void Init(USkeletalMeshComponent* InMesh, float LifeSpan, const TArray<UMaterialInterface*>& Materials);

public:

	static FName PoseableMeshComponentName;

	UPoseableMeshComponent* GetPoseableMeshComponent() const;

private:

	UPoseableMeshComponent* PoseableMeshComponent = nullptr;

};
