#include "Simulate.h"
#include "..\ApplicationManager.h"
#include <dos.h>
#include <iostream>

Simulate::Simulate(ApplicationManager* pApp) : Action(pApp)
{}

Simulate::~Simulate(void)
{

}

void Simulate::Execute()
{
	UI* pUI = pManager->GetUI();
	//create a new array identical to Components array
	int comp= pManager->getCompCount();
	Component** Objects = pManager->getComps();
	if (!CircuitConnected())
	{
		pUI->PrintMsg("Cannot start simulation unless all circuits are validly connected.");
		Sleep(2000);
		pUI->ClearStatusBar();
		return;
	}
	/*Component** ObjCopy = new Component * [comp];
	for (int i = 0; i < comp; i++)
		ObjCopy[i] = Objects[i];*/
	//create a new array identical to Connections array
	/*int conn = pManager->getConnCount();
	Connection** Connections = pManager->getConns();
	Connection** ConnCopy = new Connection * [conn];
	for (int i = 0; i < conn; i++)
		ConnCopy[i] = Connections[i];*/

	for (int i = 0; i < comp; i++)
	{
		if (Objects[i]->GetName() == "SWITCH")
		{
			DistributeOutput(Objects[i]);
		}
	}

	/*delete[] ConnCopy;
	delete[] ObjCopy;
	ObjCopy = NULL;
	ConnCopy = NULL;*/
}

void Simulate::Undo()
{}

void Simulate::Redo()
{}

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

bool Simulate::CircuitConnected()
{
	int comp = pManager->getCompCount();
	Component** Objects = pManager->getComps();
	for (int i = 0; i < comp; i++)
	{
		if (!Objects[i]->ComponentConnected())
			return false;
	}
	return true;
}