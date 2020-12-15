#include <list>

class System
{
public:
	unsigned int ID;

	virtual void Start() = 0;

	virtual void Update() = 0; //To be removed later

	virtual void End() = 0;
};

class SystemManager
{
private:
	std::list<System*> Systems;

public:
	void Update();
	void RemoveSystem(System* Target);
	void AddSystem(System* Target);
};