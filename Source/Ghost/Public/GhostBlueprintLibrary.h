#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GhostBlueprintLibrary.generated.h"

class AGhostActor;
class USkeletalMeshComponent;
class UMaterialInterface;

UCLASS(MinimalAPI, meta = (ScriptName = "GhostLibrary"))
class UGhostBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Ghost")
	static AGhostActor* SpawnGhostActor(USkeletalMeshComponent* InMesh, float LifeSpan, const TArray<UMaterialInterface*>& Materials);
};