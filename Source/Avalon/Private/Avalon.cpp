#include "Avalon.h"
#include "LevelEditor.h"
#include "AvalonPythonBridge.h"


static const FName AvalonTabName("Avalon");

#define LOCTEXT_NAMESPACE "FAvalonModule"

// This function is triggered when the plugin is staring up
void FAvalonModule::StartupModule()
{
	
	// Create the Extender that will add content to the menu
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
	MenuExtender->AddMenuExtension(
		"LevelEditor",
		EExtensionHook::After,
		NULL,
		FMenuExtensionDelegate::CreateRaw(this, &FAvalonModule::AddMenuEntry)
	);
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	
}

void FAvalonModule::ShutdownModule()
{

}


void FAvalonModule::AddMenuEntry(FMenuBuilder& MenuBuilder)
{
	// Create Section
	MenuBuilder.BeginSection("Avalon", TAttribute<FText>(FText::FromString("Avalon")));
	{
		// Create a Submenu inside of the Section
		MenuBuilder.AddMenuEntry(
			FText::FromString("Create ..."),
			FText::FromString("Avalon Creators"),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateRaw(this, &FAvalonModule::MenuCreate))
		);

		MenuBuilder.AddMenuEntry(
			FText::FromString("Load ..."),
			FText::FromString("Avalon Loaders"),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateRaw(this, &FAvalonModule::MenuLoad))
		);

		MenuBuilder.AddMenuEntry(
			FText::FromString("Publish ..."),
			FText::FromString("Pyblish"),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateRaw(this, &FAvalonModule::MenuPublish))
		);

		MenuBuilder.AddMenuEntry(
			FText::FromString("Manage ..."),
			FText::FromString("Manage scene"),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateRaw(this, &FAvalonModule::MenuManage))
		);

		MenuBuilder.AddMenuEntry(
			FText::FromString("Workfiles ..."),
			FText::FromString("Workfiles"),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateRaw(this, &FAvalonModule::MenuWorkfiles))
		);

		MenuBuilder.AddSubMenu(FText::FromString("System"),
			FText::FromString("System tools"),
			FNewMenuDelegate::CreateRaw(this, &FAvalonModule::FillSystemSubmenu));

	}
	MenuBuilder.EndSection();
}

void FAvalonModule::FillSystemSubmenu(FMenuBuilder& MenuBuilder)
{
	// Create the Submenu Entries
	MenuBuilder.AddMenuEntry(
		FText::FromString("Project Manager ..."),
		FText::FromString("Project Manager"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FAvalonModule::MenuProjectManager))
	);
}


void FAvalonModule::MenuCreate() {
	UAvalonPythonBridge* bridge = UAvalonPythonBridge::Get();
	bridge->RunInPython_Create();
}

void FAvalonModule::MenuLoad() {
	UAvalonPythonBridge* bridge = UAvalonPythonBridge::Get();
	bridge->RunInPython_Load();
}

void FAvalonModule::MenuPublish() {
	UAvalonPythonBridge* bridge = UAvalonPythonBridge::Get();
	bridge->RunInPython_Publish();
}

void FAvalonModule::MenuManage() {
	UAvalonPythonBridge* bridge = UAvalonPythonBridge::Get();
	bridge->RunInPython_Manage();
}

void FAvalonModule::MenuWorkfiles() {
	UAvalonPythonBridge* bridge = UAvalonPythonBridge::Get();
	bridge->RunInPython_Workfiles();
}

void FAvalonModule::MenuProjectManager() {
	UAvalonPythonBridge* bridge = UAvalonPythonBridge::Get();
	bridge->RunInPython_ProjectManager();
}

IMPLEMENT_MODULE(FAvalonModule, Avalon)