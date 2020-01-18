#pragma once
#include "Engine.h"
#include "AvalonPythonBridge.generated.h"

UCLASS(Blueprintable)
class UAvalonPythonBridge : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Python)
		static UAvalonPythonBridge* Get();

	UFUNCTION(BlueprintImplementableEvent, Category = Python)
		void RunInPython_Create() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Python)
		void RunInPython_Load() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Python)
		void RunInPython_Publish() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Python)
		void RunInPython_Manage() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Python)
		void RunInPython_Workfiles() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Python)
		void RunInPython_ProjectManager() const;
};