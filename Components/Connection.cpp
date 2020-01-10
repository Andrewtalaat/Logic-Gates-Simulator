#include "Connection.h"

Connection::Connection(Component* SrcCmpnt, Component* DstCmpnt, int dir)
{
	this->SrcCmpnt = SrcCmpnt;
	this->DstCmpnt = DstCmpnt;
	this->dir = dir; //1 for the down,-1 for up, 0 for middle or [0,1] == [up,down]
	if (dir == 1)
		pin_index = 1;
	this->setSourcePin();
	this->setDestPin();
}

void Connection::DrawC(UI* pUI)
{
	if (DstCmpnt != NULL && SrcCmpnt != NULL) {
		int Dy_down = DstCmpnt->getGfxInfo()->PointsList[1].y;
		int Dy_up = DstCmpnt->getGfxInfo()->PointsList[0].y;

		int Sy_down = SrcCmpnt->getGfxInfo()->PointsList[1].y;
		int Sy_up = SrcCmpnt->getGfxInfo()->PointsList[0].y;

		Src.x = SrcCmpnt->getGfxInfo()->PointsList[1].x;
		Src.y = (Sy_down + Sy_up) / 2;
		Dest.x = DstCmpnt->getGfxInfo()->PointsList[0].x;
		Dest.y = (Dy_down + Dy_up) / 2; //add cases for the y in case of gates with 2 inputs
		Dest.y = Dest.y + dir * (pUI->getGateHeight()) / 4; //align the location of the pin 

		pUI->DrawConnection(Src, Dest, pUI->getGateWidth(), pUI->getGateWidth(), selected);
	}
}

void Connection::setSourcePin()
{
	SrcPin = SrcCmpnt->GetOutputpin();
	SrcPin->ConnectTo(this);
}

void Connection::setDestPin()
{
	InputPin* hello = DstCmpnt->GetInputpins();
	DstPin = &hello[pin_index];
	DstPin->setConnected(this);
}


OutputPin* Connection::getSourcePin()
{
	return SrcPin;	
}



InputPin* Connection::getDestPin()
{	
	return DstPin;
}

Component* Connection::getDstCmpnt()
{
	return DstCmpnt;
}

void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

STATUS Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return SrcPin->getStatus();
}

STATUS Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
