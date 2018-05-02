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
	
	VertexBuffer vbuffer(positions, sizeof(positions));
	IndexBuffer ibuffer(elements, sizeof(elements));

	VertexInputElement el[1] = { { VI_POSITION, 0, 2, &vbuffer} };

	VertexInput input(el, 1, &ibuffer);

	ShaderSource vsrc("vshader");
	ShaderSource psrc("pshader");

	Shader shader(vsrc, psrc);

	char quit = 0;
	SDL_Event event;

	while (quit != 1)
	{
		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				quit = 1;
			}
			else {
				input.Bind();
				//shader.Bind();

				gfx.BeginFrame();

				gfx.Clear(COLOR_CLEAR | DEPTH_CLEAR, RGBA(255, 0, 0, 0));

				//gfx.Draw(sizeof(positions) / sizeof(float));

				gfx.EndFrame();

				//shader.Unbind();
				input.Unbind();
			}
		}
	}

	gfx.CloseWindow();

	return 0;
}
