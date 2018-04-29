#pragma once

#include "Graphics/Graphics.h"
#include <iostream>

#define main  SDL_main

int main(int argc, char* argv[])
{
	Graphics g = Graphics();

	g.OpenWindow(1280, 720, true, false, false);

	g.Clear(COLOR_CLEAR | DEPTH_CLEAR, RGBA(255, 0, 255, 0));





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
	}

	g.CloseWindow();

	return 0;
}
