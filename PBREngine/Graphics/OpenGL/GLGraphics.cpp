#include "../Graphics.h"
#include <iostream>

#ifdef OPEN_GL

static const unsigned depthFunctions[] ={
	GL_ALWAYS,
	GL_EQUAL,
	GL_NOTEQUAL,
	GL_LESS,
	GL_LEQUAL,
	GL_GREATER,
	GL_GEQUAL
};


void Graphics::OpenWindow(const char* title, unsigned w, unsigned h, bool vsync, bool resizable, bool fullscreen)
{
	this->vsync = vsync;
	this->resizable = resizable;
	this->fullscreen = fullscreen;

	unsigned flags = 0;

	if (resizable)
		flags |= SDL_WINDOW_RESIZABLE;
	
	if (fullscreen)
		flags |= SDL_WINDOW_FULLSCREEN;

	flags |= SDL_WINDOW_OPENGL;

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);

	if (!window)
		throw std::runtime_error("Failed to create window!");

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetSwapInterval(vsync ? 1 : 0);

	auto glcontext = SDL_GL_CreateContext(window);

	glewExperimental = true;
	if (GLEW_OK != glewInit())
		printf("Error with glew");

	printf((const char*)glGetString(GL_VERSION));
}




void Graphics::CloseWindow() 
{
	if (window)
	{
		SDL_ShowCursor(SDL_TRUE);
		SDL_DestroyWindow(window);
		window = nullptr;
	}
}


void Graphics::Clear(unsigned char inFlags, RGBA color) 
{
	unsigned flags = 0;

	if (inFlags & COLOR_CLEAR)
	{
		flags |= GL_COLOR_BUFFER_BIT;
		glClearColor((float)color.r / 255u, (float)color.g / 255u, (float)color.b / 255u, (float)color.a / 255u);
	}

	if (inFlags & DEPTH_CLEAR)
	{
		flags |= GL_DEPTH_BUFFER_BIT;
		glClearDepth(1.0f);
	}

	if (inFlags & STENCIL_CLEAR)
	{
		flags |= GL_STENCIL_BUFFER_BIT;
		glClearStencil(0);
	}

	glClear(flags);
}


void Graphics::BeginFrame()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(depthFunctions[0]);
}


void Graphics::EndFrame()
{
	SDL_GL_SwapWindow(window);
}


void Graphics::Draw(unsigned vertexStart, unsigned vertexCount)
{
	glDrawArrays(GL_TRIANGLES, vertexStart, vertexCount);
}


void Graphics::Draw(int verticesCount)
{
	glDrawElements(GL_TRIANGLES, verticesCount, GL_UNSIGNED_INT, nullptr);
}

#endif