#include"Edit.h"
#include"..\ApplicationManager.h"

Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{
}

Edit::~Edit(void)
{
}

void Edit::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Select a component to Edit: ");
	Point Location;
	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);
	Component** Objects = pManager->getComps();
	for (int i = 0; i < pManager->getCompCount(); i++)
	{
		if (Objects[i] != NULL) {
			if (Cx < Objects[i]->getGfxInfo()->PointsList[1].x
				&& Cx > Objects[i]->getGfxInfo()->PointsList[0].x
				&& Cy < Objects[i]->getGfxInfo()->PointsList[1].y
				&& Cy > Objects[i]->getGfxInfo()->PointsList[0].y)
			{
				if (Objects[i]->GetLabel() == " ")
				{
					pUI->PrintMsg("Component does not have a label, use the label icon instead.");
					return;
				}
				pUI->ClearStatusBar();
				pUI->PrintMsg("Enter the new label.");
				Objects[i]->SetLabel(pUI->GetSrting());
				pUI->ClearStatusBar();
			}
		}
	}

	//Clear Status Bar
	pUI->ClearStatusBar();

}

void Edit::Undo()
{}

void Edit::Redo()
{}

void Edit::Load(int x, int y)
{
}

