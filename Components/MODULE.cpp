#include "MODULE.h"

MODULE::MODULE(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 5, r_FanOut) 
{

}


void MODULE::Operate()
{
	//to compute the first output:
	CandE.setInputPinStatus(1, GetInputPinStatus(3));
	CandE.setInputPinStatus(2, GetInputPinStatus(5));
	CandE.Operate();
	STATUS CE = CandE.GetOutPinStatus();
	EorD.setInputPinStatus(1, GetInputPinStatus(5));
	EorD.setInputPinStatus(2, GetInputPinStatus(4));
	EorD.Operate();
	STATUS ED = EorD.GetOutPinStatus();
	AandB.setInputPinStatus(1, GetInputPinStatus(1));
	AandB.setInputPinStatus(2, GetInputPinStatus(2));
	AandB.Operate();
	STATUS AB = AandB.GetOutPinStatus();
	BandA.setInputPinStatus(1, GetInputPinStatus(2));
	BandA.setInputPinStatus(2, GetInputPinStatus(1));
	BandA.Operate();
	STATUS BA = BandA.GetOutPinStatus();
	CEandED.setInputPinStatus(1, CE);
	CEandED.setInputPinStatus(2, ED);
	CEandED.Operate();
	STATUS p1 = CEandED.GetOutPinStatus();
	ABnorBA.setInputPinStatus(1, AB);
	ABnorBA.setInputPinStatus(2, BA);
	ABnorBA.Operate();
	STATUS p2 = ABnorBA.GetOutPinStatus();
	p1NANDp2.setInputPinStatus(1, p1);
	p1NANDp2.setInputPinStatus(2, p2);
	p1NANDp2.Operate();
	STATUS out1 = p1NANDp2.GetOutPinStatus();
	MODULE::m_OutputPin.setStatus(out1);


	//to compute the second output:
	ExorD.setInputPinStatus(1, GetInputPinStatus(5));
	ExorD.setInputPinStatus(2, GetInputPinStatus(4));
	ExorD.Operate();
	STATUS ED2 = ExorD.GetOutPinStatus();
	AnorB.setInputPinStatus(1, GetInputPinStatus(1));
	AnorB.setInputPinStatus(2, GetInputPinStatus(2));
	AnorB.Operate();
	STATUS AB2 = AnorB.GetOutPinStatus();
	CandB.setInputPinStatus(1, GetInputPinStatus(3));
	CandB.setInputPinStatus(2, GetInputPinStatus(2));
	CandB.Operate();
	STATUS CB = CandB.GetOutPinStatus();
	AxnorB.setInputPinStatus(1, GetInputPinStatus(1));
	AxnorB.setInputPinStatus(2, GetInputPinStatus(2));
	AxnorB.Operate();
	STATUS AB3 = AxnorB.GetOutPinStatus();
	EDnandAB.setInputPinStatus(1, ED2);
	EDnandAB.setInputPinStatus(2, AB2);
	EDnandAB.Operate();
	STATUS p3 = EDnandAB.GetOutPinStatus();
	CBnorAB.setInputPinStatus(1, CB);
	CBnorAB.setInputPinStatus(2, AB3);
	CBnorAB.Operate();
	STATUS p4 = CBnorAB.GetOutPinStatus();
	p3NANDp4.setInputPinStatus(1, p3);
	p3NANDp4.setInputPinStatus(2, p4);
	p3NANDp4.Operate();
	STATUS out2 = p3NANDp4.GetOutPinStatus();
	MODULE::m_OutputPin2.setStatus(out2);

}


// Function Draw
// Draws THE MODULE ITEM
void MODULE::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawMODULE(*m_pGfxInfo, getSelectStatus());
}

//returns status of outputpin
STATUS  MODULE::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

STATUS MODULE::GetOutPin2Status()
{
	return m_OutputPin2.getStatus();
}


//returns status of Inputpin #n
STATUS MODULE::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void MODULE::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
string MODULE::GetName()
{
	return "MODULE";
}

OutputPin* MODULE::GetOutputPin2()
{
	OutputPin* ptr = &m_OutputPin;
	return ptr;
}

bool MODULE::Output2isFull()
{
	return m_OutputPin2.Max_reached();
}

void MODULE::DeleteConnections()
{
	for (int i = 0; i < Inpinscount; i++)
		m_InputPins[i].RemoveWire();
	m_OutputPin.RemoveConnections();
	m_OutputPin2.RemoveConnections();
}

void MODULE::Save() {
	ofstream myfile;
	myfile.open("ABD.txt", ios_base::app);
	myfile << GetName() << "	" << GetLabel() << "		" << m_pGfxInfo->PointsList[0].x << "	" << m_pGfxInfo->PointsList[0].y << endl;
}