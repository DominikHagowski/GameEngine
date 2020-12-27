#include <iostream>
#include <thread>
#include <chrono>

#include "SystemManager.h"

#include "Systems/TestSystem.h"
#include "Systems/GraphicsSystem.h"

using namespace std::chrono_literals;

int main()
{
	std::cout << "Hello World" << std::endl;

	SystemManager Manager = SystemManager();

	System* TestSys1 = new TestSystem();
	System* TestSys2 = new TestSystem2();

	System* GraphicsSys = new GraphicsSystem();

	Manager.AddSystem(TestSys1);
	Manager.AddSystem(TestSys2);
	Manager.AddSystem(GraphicsSys);

	std::this_thread::sleep_for(15s);

	Manager.RemoveSystem(TestSys1);
	Manager.RemoveSystem(TestSys2);
	Manager.RemoveSystem(GraphicsSys);

	return 0;
}