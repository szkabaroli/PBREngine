#pragma once

#include "Graphics\Graphics.h"
#include "Graphics\VertexInput.h"
#include "Graphics\VertexBuffer.h"
#include "Graphics\IndexBuffer.h"
#include "Graphics\Shader.h"
#include "common.h"
#include <string>
#include <iostream>

#define main SDL_main

Graphics gfx;

int main(int argc, char* argv[])
{
	
	gfx = Graphics();

	gfx.OpenWindow("PBR Engine", 1280, 720, true, false, false);

	
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

	//VertexInput input = VertexInput();

	VertexBuffer vbuffer(positions, sizeof(positions));
	//IndexBuffer ibuffer(elements, sizeof(elements));
	
	//input.AddBuffer(0, 2, vbuffer);
	//input.AddBuffer(ibuffer);

	//ShaderSource src("shader.glsl");
	//Shader shader(src);
	
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
		
		//input.Bind();
		//shader.Bind();
		
		gfx.BeginFrame();
		
		gfx.Clear(COLOR_CLEAR | DEPTH_CLEAR, RGBA(255, 0, 0, 0));
		
		//gfx.Draw(ibuffer.GetCount());
		
		gfx.EndFrame();
		
		//shader.Unbind();
		//input.Unbind();
	}


	gfx.CloseWindow();

	return 0;
}
