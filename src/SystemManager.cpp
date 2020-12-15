#include <list>
#include <algorithm>
#include <thread>

#include "SystemManager.h"

void StartSystem(System* Target)
{
	Target->Start();
	Target->Update();
	Target->End();
}

void SystemManager::AddSystem(System* Target)
{
	Target->RunningThread = new std::thread(StartSystem, Target);
	Systems.insert(Systems.end(), Target);
}
	
void SystemManager::RemoveSystem(System* Target)
{
	Target->Killed = true;
	Target->RunningThread->join();
	Systems.remove(Target); 
}