#pragma once

#include "Graphics\Graphics.h"
#include "Graphics\VertexInput.h"
#include "Graphics\VertexBuffer.h"
#include "Graphics\IndexBuffer.h"
#include "Graphics\Shader.h"
#include <string>
#include <iostream>

#define main SDL_main

int main(int argc, char* argv[])
{
	Graphics g = Graphics();

	g.OpenWindow("PBR Engine", 1280, 720, true, false, true);

	
	float positions[] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.5f, 0.5f,
		-0.5f, 0.5f
	};

	unsigned elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	/*VertexInput input = VertexInput();

	VertexBuffer vbuffer(positions, sizeof(positions));
	IndexBuffer ibuffer(elements, sizeof(elements));
	
	input.AddBuffer(0, 2, vbuffer);
	input.AddBuffer(ibuffer);

	ShaderSource src("shader.glsl");
	Shader shader(src);
	*/
	char quit = 0;
	SDL_Event event;

	while (quit != 1)
	{
		/*GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR) {
			std::cout << "OpenGL error: " << glewGetErrorString( err) << std::endl;
		}*/
		while (SDL_PollEvent(&event))
		{
			/* If a quit event has been sent */
			if (event.type == SDL_QUIT)
			{
				/* Quit the application */
				quit = 1;
			}
		}
		/*
		input.Bind();
		shader.Bind();
		
		g.BeginFrame();
		*/
		g.Clear(COLOR_CLEAR | DEPTH_CLEAR, RGBA(255, 0, 0, 0));
		/*
		g.Draw(ibuffer.GetCount());
		*/
		g.EndFrame();
		/*
		shader.Unbind();
		input.Unbind();*/
	}


	g.CloseWindow();

	return 0;
}
