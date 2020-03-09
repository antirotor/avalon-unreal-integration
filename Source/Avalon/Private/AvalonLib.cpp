#include "AvalonLib.h"
#include "Misc/Paths.h"
#include "Misc/ConfigCacheIni.h"
#include "UnrealType.h"


void UAvalonLib::CSetFolderColor(FString FolderPath, FLinearColor FolderColor, bool bForceAdd) {
	auto SaveColorInternal = [](FString InPath, FLinearColor InFolderColor)
	{
		// Saves the color of the folder to the config
		if (FPaths::FileExists(GEditorPerProjectIni))
		{
			GConfig->SetString(TEXT("PathColor"), *InPath, *InFolderColor.ToString(), GEditorPerProjectIni);
		}

	};

	SaveColorInternal(FolderPath, FolderColor);
	
}

TArray<FString> UAvalonLib::GetAllProperties(UClass* cls) {
	TArray<FString> Ret;
	if (cls != nullptr) {
		for (TFieldIterator<UProperty> It(cls); It; ++It) {
			UProperty* Property = *It;
			if (Property->HasAnyPropertyFlags(EPropertyFlags::CPF_Edit)) {
				Ret.Add(Property->GetName());
			}
		}
	}
	return Ret;
}
