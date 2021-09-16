#include "GhostAnimNotify.h"
#include "GhostBlueprintLibrary.h"

void UGhostAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UGhostBlueprintLibrary::SpawnGhostActor(MeshComp, LifeSpan, Materials);
};
