#include "Simulate.h"
#include "..\ApplicationManager.h"

Simulate::Simulate(ApplicationManager* pApp) : SELECT(pApp)
{}

Simulate::~Simulate(void)
{

}

void Simulate::Execute()
{

}

void Simulate::RunCircuit()
{
	int comp = pManager->getCompCount();
	Component** Objects = pManager->getComps();
	for (int i = 0; i < comp; i++)
	{
		if (Objects[i]->GetName() == "SWITCH")
		{
			DistributeOutput(Objects[i]);
		}
	}
}

void Simulate::DistributeOutput(Component* Root)
{
	if (Root->GetName() != "SWITCH")
	{
		InputPin* Inputs = Root->GetInputpins();
		for (int i = 0; i < Root->getInpincount(); i++)
		{
			Inputs[i].getWire()->Operate();
		}
	}
	if (!Root->GetOutputpin()->getConnCount())
	{
		Root->Operate();
		return;
	}
	else
	{
		Root->Operate();
		Connection** Branch = Root->GetOutputpin()->getConnList();
		for (int i = 0; i < Root->GetOutputpin()->getConnCount(); i++)
		{
			Branch[i]->Operate();
			DistributeOutput(Branch[i]->getDstCmpnt());
		}
	}
}


void Simulate::Undo()
{}

void Simulate::Redo()
{}

