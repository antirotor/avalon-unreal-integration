// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"


class FAvalonModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
private:

	void AddMenuEntry(FMenuBuilder& MenuBuilder);
	void FillSystemSubmenu(FMenuBuilder& MenuBuilder);
	void MenuCreate();
	void MenuLoad();
	void MenuPublish();
	void MenuManage();
	void MenuWorkfiles();
	void MenuProjectManager();

};
