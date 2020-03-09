// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetContainer.h"
#include "AssetRegistryModule.h"
#include "Misc/PackageName.h"
#include "Engine.h"

UAssetContainer::UAssetContainer(const FObjectInitializer& ObjectInitializer)
: UDataAsset(ObjectInitializer)
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	FString path = UAssetContainer::GetPathName();
	UE_LOG(LogTemp, Warning, TEXT("UAssetContainer %s"), *path);
	FARFilter Filter;
	Filter.PackagePaths.Add(FName(*path));
	
	AssetRegistryModule.Get().OnAssetAdded().AddUObject(this, &UAssetContainer::OnAssetAdded);
	AssetRegistryModule.Get().OnAssetRemoved().AddUObject(this, &UAssetContainer::OnAssetRemoved);
	AssetRegistryModule.Get().OnAssetRenamed().AddUObject(this, &UAssetContainer::OnAssetRenamed);
}

/*
UAssetContainer::~UAssetContainer()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>("AssetRegistry");
	
	AssetRegistryModule.Get().OnAssetAdded().RemoveAll(this);
	AssetRegistryModule.Get().OnAssetRemoved().RemoveAll(this);
	AssetRegistryModule.Get().OnAssetRenamed().RemoveAll(this);
}
*/

void UAssetContainer::OnAssetAdded(const FAssetData& AssetData) {
	FString path = UAssetContainer::GetPathName();
	FString lpp = FPackageName::GetLongPackagePath(*path);
	UE_LOG(LogTemp, Warning, TEXT("%s: asset added"), *lpp);
	assetsData.Add(AssetData);
	UE_LOG(LogTemp, Log, TEXT("array now contains: %d"), assetsData.Num());
}

void UAssetContainer::OnAssetRemoved(const FAssetData& AssetData) {
	FString path = UAssetContainer::GetPathName();
	FString lpp = FPackageName::GetLongPackagePath(*path);
	UE_LOG(LogTemp, Warning, TEXT("%s: asset removed"), *lpp);
	assetsData.Remove(AssetData);
	UE_LOG(LogTemp, Log, TEXT("array now contains: %d"), assetsData.Num());
}

void UAssetContainer::OnAssetRenamed(const FAssetData& AssetData, const FString& str) {
	FString path = UAssetContainer::GetPathName();
	FString lpp = FPackageName::GetLongPackagePath(*path);
	UE_LOG(LogTemp, Warning, TEXT("%s: asset renamed %s"), *lpp, *str);
}