#include <iostream>
#include <thread>
#include <chrono>

#include "SystemManager.h"
#include "Systems/TestSystem.h"

using namespace std::chrono_literals;

int main()
{
	std::cout << "Hello World" << std::endl;

	SystemManager Manager = SystemManager();

	System* TestSys1 = new TestSystem();
	System* TestSys2 = new TestSystem2();

	Manager.AddSystem(TestSys1);
	Manager.AddSystem(TestSys2);

	std::this_thread::sleep_for(2s);

	Manager.RemoveSystem(TestSys1);
	Manager.RemoveSystem(TestSys2);

	return 0;
}