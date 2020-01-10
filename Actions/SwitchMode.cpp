#include "SwitchMode.h"
#include"..\ApplicationManager.h"
#include"..\CMUgraphicsLib/CMUgraphics.h"
SwitchMode::SwitchMode(ApplicationManager* pApp) :Action(pApp)
{
}

SwitchMode::~SwitchMode(void)
{
}

void SwitchMode::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	if (pUI->GetAppMode() == DESIGN) {
		pUI->CreateSimulationToolBar();
		pUI->CreateStatusBar();
		pUI->SetAppMode(SIMULATION);
	}
	else {
		pUI->SetAppMode(DESIGN);
		pUI->CreateDesignToolBar();
		pUI->CreateStatusBar();
	}
}

void SwitchMode::Undo()
{}

void SwitchMode::Redo()
{}

