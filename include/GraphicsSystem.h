#include <iostream>
#include <vector>
#include <queue>
#include <GLFW/glfw3.h>

struct Mesh
{
	int VertCount; 
	float* Verts;
};

struct Renderable
{
	int VAO;
	int VertCount;
	int Shader;
};

enum CommandType
{
	Command_MeshLoad
};

struct Command
{
	CommandType CommandT;
	void* Data;
};

class GraphicsSystem : public System
{
private:
	std::vector<Renderable*> Objects;
	int WindowWidth;
	int WindowHeight;
	GLFWwindow* MainWindow;
	void ProcessCommands();
	void LoadMesh(void * Data);

public:

	std::queue<Command> CommandQueue;

	virtual void Start();
	virtual void End();
	virtual void Update();
};