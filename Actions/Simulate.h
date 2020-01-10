#ifndef SIMULATE_H
#define SIMULATE_H

#include "SELECT.h"

class Simulate : public SELECT
{
public:
	Simulate(ApplicationManager* pApp);
	virtual ~Simulate(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	void DistributeOutput(Component* Root);
	void RunCircuit();
};
#endif // !SIMULATE_H
