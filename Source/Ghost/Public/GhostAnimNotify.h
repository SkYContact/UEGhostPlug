#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GhostAnimNotify.generated.h"

class UMaterialInterface;

UCLASS()
class GHOST_API UGhostAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LifeSpan;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInterface*> Materials;
};
