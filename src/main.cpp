#include <iostream>

#include "SystemManager.h"
#include "Systems/TestSystem.h"


int main()
{
	std::cout << "Hello World" << std::endl;

	SystemManager Manager = SystemManager();

	System* TestSys1 = new TestSystem();
	System* TestSys2 = new TestSystem2();

	Manager.AddSystem(TestSys1);
	Manager.AddSystem(TestSys2);

	while (1)
	{
		Manager.Update();
	}

	return 0;
}