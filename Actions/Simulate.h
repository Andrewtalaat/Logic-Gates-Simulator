#ifndef SIMULATE_H
#define SIMULATE_H

#include "..\Components\Component.h"
#include"Action.h"

class Simulate : public Action
{
public:
	Simulate(ApplicationManager* pApp);
	virtual ~Simulate(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	void DistributeOutput(Component* Root);
	bool CircuitConnected();
};
#endif // !SIMULATE_H
