// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "UObject/UObjectGlobals.h"
#include "AssetContainer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AVALON_API UAssetContainer : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UAssetContainer(const FObjectInitializer& ObjectInitalizer);
	// ~UAssetContainer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> assets;
		
	
private:
	TArray<FAssetData> assetsData;
	void OnAssetAdded(const FAssetData& AssetData);
	void OnAssetRemoved(const FAssetData& AssetData);
	void OnAssetRenamed(const FAssetData& AssetData, const FString& str);
};


