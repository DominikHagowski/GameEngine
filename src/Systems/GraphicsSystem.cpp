#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../SystemManager.h"
#include "GraphicsSystem.h"

void GraphicsSystem::LoadMesh(void * Data)
{
	Mesh* SourceMesh = (Mesh*)Data;
	Renderable* Target = new Renderable;

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, SourceMesh->VertCount * 3 * sizeof(float), SourceMesh->Verts, GL_STATIC_DRAW);

	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	unsigned int VertexShader;
	VertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(VertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(VertexShader);

	const char* fragmentshaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"} \0";

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentshaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int ShaderProgram;
	ShaderProgram = glCreateProgram();
	
	glAttachShader(ShaderProgram, VertexShader);
	glAttachShader(ShaderProgram, fragmentShader);
	glLinkProgram(ShaderProgram);

	Target->Shader = ShaderProgram;

	glDeleteShader(VertexShader);
	glDeleteShader(fragmentShader);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	Target->VAO = VAO;
	Target->VertCount = SourceMesh->VertCount;

	Objects.push_back(Target);
}

void GraphicsSystem::ProcessCommands()
{
	while (!CommandQueue.empty())
	{
		Command Current = CommandQueue.front();

		switch (Current.CommandT)
		{
		case (Command_MeshLoad):
			LoadMesh(Current.Data);
		default:
			break;
		}

		CommandQueue.pop();
	}
}

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

	WindowHeight = 600;
	WindowWidth = 800;

	glfwMakeContextCurrent(MainWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		Killed = true;
		return;
	}

	glViewport(0, 0, 800, 600);

	glClearColor(255, 0, 255, 255);
}

void GraphicsSystem::Update()
{
	while (!Killed)
	{

		ProcessCommands();
		
		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = 0; i < Objects.size(); i++)
		{
			glUseProgram(Objects[i]->Shader);
			glBindVertexArray(Objects[i]->VAO);
			glDrawArrays(GL_TRIANGLES, 0, Objects[i]->VertCount / 3);
			
		}
		
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