#include "AvalonLib.h"
#include "Misc/Paths.h"
#include "Misc/ConfigCacheIni.h"
#include "UnrealType.h"

/**
 * Sets color on folder icon on given path
 * @param InPath - path to folder
 * @param InFolderColor - color of the folder
 * @warning This color will appear only after Editor restart. Is there a better way?
 */

void UAvalonLib::CSetFolderColor(FString FolderPath, FLinearColor FolderColor, bool bForceAdd)
{
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
/**
 * Returns all poperties on  given object
 * @param cls - class
 * @return TArray of properties
 */
TArray<FString> UAvalonLib::GetAllProperties(UClass* cls)
{
	TArray<FString> Ret;
	if (cls != nullptr)
	{
		for (TFieldIterator<UProperty> It(cls); It; ++It)
		{
			UProperty* Property = *It;
			if (Property->HasAnyPropertyFlags(EPropertyFlags::CPF_Edit))
			{
				Ret.Add(Property->GetName());
			}
		}
	}
	return Ret;
}
