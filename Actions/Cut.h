#ifndef CUT_H
#define CUT_H

#include"Action.h"

class Cut : public Action
{
private:
	int Cx, Cy;

public:
	Cut(ApplicationManager* pApp);
	virtual ~Cut(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif