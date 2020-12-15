#include <list>
#include <thread>

class System
{
public:
	unsigned int ID;

	bool Killed = false;

	std::thread* RunningThread;

	virtual void Start() = 0;

	virtual void Update() = 0; //To be removed later

	virtual void End() = 0;
};

class SystemManager
{
private:
	std::list<System*> Systems;

public:
	void RemoveSystem(System* Target);
	void AddSystem(System* Target);
};