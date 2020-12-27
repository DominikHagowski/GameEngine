#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GraphicsSystem : public System
{
private:
	GLFWwindow* MainWindow;
public:
	virtual void Start();
	virtual void End();
	virtual void Update();
};