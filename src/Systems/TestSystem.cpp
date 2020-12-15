#include <iostream>

#include "../SystemManager.h"
#include "TestSystem.h"

void TestSystem::Start()
{
	std::cout << "1: System Created" << std::endl;
}

void TestSystem::Update() //To be removed later
{
	std::cout << "1: System Updated" << std::endl;
}

void TestSystem::End()
{
	std::cout << "1: System Destroyed" << std::endl;
}

void TestSystem2::Start()
{
	std::cout << "2: System Created" << std::endl;
}

void TestSystem2::Update() //To be removed later
{
	std::cout << "2: System Updated" << std::endl;
}

void TestSystem2::End()
{
	std::cout << "2: System Destroyed" << std::endl;
}