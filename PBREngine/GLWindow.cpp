#include "GLWindow.h"

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLWindow::GLWindow(Game* game)
{
	this->game = game;
	
}


void GLWindow::Start()
{
	this->Initilize();
	this->FrameLoop();

	glfwDestroyWindow(window);
	glfwTerminate();
}


void GLWindow::Initilize()
{
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		throw std::runtime_error("GLFW failed to init");

	//Set default window settings
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	//16x MSAA Antialiasing
	glfwWindowHint(GLFW_SAMPLES, 8);

	//Create the actual window
	window = glfwCreateWindow(width, height, "PBR Rendering", NULL, NULL);
	if (window == NULL)
		throw std::runtime_error("Failed to create the GLFW window");

#ifdef DEBUG
	glfwSetKeyCallback(window, key_callback);
#endif //set esc key to escape

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwMakeContextCurrent(window);

	//VSYNC
	glfwSwapInterval(0);
	glfwShowWindow(window);
}


void GLWindow::FrameLoop()
{
	game->OnPrep();
	while (!glfwWindowShouldClose(window)) {
		game->OnRender();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	game->OnExit();
}


