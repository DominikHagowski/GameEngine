#include <list>
#include <algorithm>

#include "SystemManager.h"


void SystemManager::AddSystem(System* Target)
{
	Systems.insert(Systems.end(), Target);
	Target->Start();
}
	
void SystemManager::RemoveSystem(System* Target)
{
	Systems.remove(Target);
}

void SystemManager::Update() //To be removed later
{
	for each (System* sys in Systems)
	{
		sys->Update();
	}
}
