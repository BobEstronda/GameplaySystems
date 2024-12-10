// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EItemState.h"
#include "Inventory/FGSItem.h"
#include "GSItemManagerComponent.generated.h"

class UGSActorItemDefinition;
class AGSItemActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPLAYSYSTEMS_API UGSItemManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGSItemManagerComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server,Reliable,BlueprintCallable,Category = "ItemManager")
	virtual void SpawnItemInWorld(const FGSItem& InItem,UGSActorItemDefinition* ActorItemDefinition,const EItemState InItemState);

	UFUNCTION(Client,Reliable,BlueprintCallable,Category = "ItemManager")
	virtual void FailedToSpawnItemInWorld(const FGSItem& InItem,UGSActorItemDefinition* ActorItemDefinition,const EItemState InItemState);

protected:

private:
	UPROPERTY(EditDefaultsOnly,Replicated,Category = "GameplayFramework|Items")
	TArray<AGSItemActor*> ItemsSpawnedInWorld;

	UPROPERTY(EditDefaultsOnly,Category = "GameplayFramework|Items")
	uint8 MaxItemsSpawnedInWorld = 4;
	
};