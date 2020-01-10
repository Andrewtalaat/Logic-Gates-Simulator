#ifndef COPY_H
#define COPY_H

#include"Action.h"

class Copy : public Action
{
private:
	int Cx, Cy;

public:
	Copy(ApplicationManager* pApp);
	virtual ~Copy(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif