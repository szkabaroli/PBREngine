#pragma once
#include <GLFW\glfw3.h>
#include <iostream>
#include "Game.h"

class GLWindow
{
public:

	void Start();
	GLWindow(Game* game);
private:

	//Fields
	GLFWwindow* window;
	Game* game;

	int width = 1024;
	int height = 768;

	//Methods
	void Initilize();
	void FrameLoop();
	
};
