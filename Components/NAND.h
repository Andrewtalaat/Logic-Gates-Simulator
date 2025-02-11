#ifndef _NAND_H
#define _NAND_H

/*
  Class NAND
  -----------
  represent the 2-input NAND gate
*/

#include "Gate.h"

class NAND :public Gate
{
public:
	NAND(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	NAND();
	virtual void Operate();	//Calculates the output of the NAND gate
	virtual void Draw(UI*);	//Draws 2-input gate

	virtual STATUS GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual STATUS GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string GetName();
	virtual void Save();
};

#endif