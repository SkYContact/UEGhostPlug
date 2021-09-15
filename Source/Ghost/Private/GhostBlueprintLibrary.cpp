#include "GhostBlueprintLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "GhostActor.h"

AGhostActor* UGhostBlueprintLibrary::SpawnGhostActor(USkeletalMeshComponent* InMesh, float LifeSpan, const TArray<UMaterialInterface*>& Materials)
{
	if (InMesh == nullptr)
	{
		return nullptr;
	}
	UWorld* World = InMesh->GetWorld();
	if (World == nullptr)
	{
		return nullptr;
	}
	FTransform const& MeshTransform = InMesh->GetComponentTransform();
	AGhostActor* GhostActor = World->SpawnActorDeferred<AGhostActor>(AGhostActor::StaticClass(), MeshTransform);
	if (GhostActor == nullptr)
	{
		return nullptr;
	}
	GhostActor->Init(InMesh,LifeSpan, Materials);
	GhostActor->FinishSpawning(MeshTransform);
	return GhostActor;
}
