#include "NAND.h"

NAND::NAND(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut)
{
}
NAND::NAND() :Gate(2){
	
}

void NAND::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH) {
		m_OutputPin.setStatus(LOW);
	}
	else m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 2-input NAND gate
void NAND::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	if (isDrawn) {
		pUI->DrawNAND(*m_pGfxInfo, getSelectStatus());
	}
}

//returns status of outputpin
STATUS NAND::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
STATUS NAND::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

string NAND::GetName()
{
	return "NAND";
}
void NAND::Save() {
	ofstream myfile;
	myfile.open("ABD.txt", ios_base::app);
	myfile << GetName() << "	" << GetLabel() << "		" << m_pGfxInfo->PointsList[0].x << "	" << m_pGfxInfo->PointsList[0].y << endl;
}