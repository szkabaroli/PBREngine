#pragma once

#include "Graphics/Graphics.h"
#include "Graphics\VertexBuffer.h"
#include "Graphics\IndexBuffer.h"

#include <iostream>

#define main SDL_main

int main(int argc, char* argv[])
{
	Graphics g = Graphics();

	g.OpenWindow(1280, 720, true, false, false);

	
	float positions[6] = {
		-0.5f, -0.5f,
		0.5f, 0.5f,
		0.5f, -0.5f
	};


	std::cout << (sizeof(positions) / sizeof(*positions)) << std::endl;

	VertexBuffer vbuffer(positions, (sizeof(positions) / sizeof(*positions)) * sizeof(float));



	char quit = 0;
	SDL_Event event;

	while (quit != 1)
	{
		while (SDL_PollEvent(&event))
		{
			/* If a quit event has been sent */
			if (event.type == SDL_QUIT)
			{
				/* Quit the application */
				quit = 1;
			}
		}
		
		g.Clear(COLOR_CLEAR | DEPTH_CLEAR, RGBA(255, 0, 255, 0));

		g.BeginFrame();
		
		

		g.EndFrame();


	}


	g.CloseWindow();

	return 0;
}
