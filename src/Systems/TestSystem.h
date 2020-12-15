#include <iostream>

class TestSystem : public System
{
public:
	 virtual void Start();
	 virtual void End();
	 virtual void Update();
};

class TestSystem2 : public System
{
public:
	virtual void Start();
	virtual void End();
	virtual void Update();
};
