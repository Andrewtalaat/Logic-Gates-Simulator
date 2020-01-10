#ifndef Paste_H
#define Paste_H

#include"Action.h"

class Paste : public Action
{
private:
	int Cx, Cy;

public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif