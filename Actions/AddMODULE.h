#ifndef _ADD_MODULE_H
#define _ADD_MODULE_H

#include "action.h"
#include "..\Components\MODULE.h"

class AddMODULE: public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddMODULE(ApplicationManager* pApp);
	virtual ~AddMODULE(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	virtual void Load(int x, int y);

};

#endif