#ifndef _ADD_NOT_GATE_H
#define _ADD_NOT_GATE_H

#include "action.h"
#include "..\Components\NOT.h"

class AddNOTgate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddNOTgate(ApplicationManager* pApp);
	virtual ~AddNOTgate(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	virtual void Load(int x, int y);

};

#endif