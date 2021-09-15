#include "GhostActor.h"
#include "Components/PoseableMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

FName AGhostActor::PoseableMeshComponentName(TEXT("PoseableMeshComp"));

AGhostActor::AGhostActor(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PoseableMeshComponent = CreateDefaultSubobject<UPoseableMeshComponent>(PoseableMeshComponentName);
	SetRootComponent(PoseableMeshComponent);
	if (PoseableMeshComponent != nullptr)
	{
		PoseableMeshComponent->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	}
}

void AGhostActor::Init(USkeletalMeshComponent* InMesh, float LifeSpan, const TArray<UMaterialInterface*>& Materials)
{
	SetLifeSpan(LifeSpan);
	if (PoseableMeshComponent != nullptr)
	{
		if (InMesh != nullptr)
		{
			PoseableMeshComponent->SetSkeletalMesh(InMesh->SkeletalMesh);
			PoseableMeshComponent->CopyPoseFromSkeletalComponent(InMesh);
		}
		for (int i = 0; i < Materials.Num(); i++)
		{
			PoseableMeshComponent->SetMaterial(i, Materials[i]);
		}
	}
}

UPoseableMeshComponent* AGhostActor::GetPoseableMeshComponent() const
{
	return PoseableMeshComponent;
}