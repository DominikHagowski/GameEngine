#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../SystemManager.h"
#include "GraphicsSystem.h"

void GraphicsSystem::Start()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	MainWindow = glfwCreateWindow(800, 600, "Test Window", NULL, NULL);

	if (MainWindow == NULL)
	{
		std::cout << "Window Creation Failed" << std::endl;
		glfwTerminate();
		Killed = true;
		return;
	}

	glfwMakeContextCurrent(MainWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		Killed = true;
		return;
	}

	glViewport(0, 0, 800, 600);
}

void GraphicsSystem::Update()
{
	while (!Killed)
	{
		Killed = glfwWindowShouldClose(MainWindow);
		glfwSwapBuffers(MainWindow);
		glfwPollEvents();
	}
}

void GraphicsSystem::End()
{
	glfwTerminate();
	std::cout << "3: System Destroyed" << std::endl;
}