#pragma comment (lib, "opengl32.lib")

#include "../Graphics.h"

#define GLEW_STATIC
#include <gl\glew.h>

static const unsigned depthFunctions[] =
{
	GL_ALWAYS,
	GL_EQUAL,
	GL_NOTEQUAL,
	GL_LESS,
	GL_LEQUAL,
	GL_GREATER,
	GL_GEQUAL
};

#pragma region Window
bool Graphics::OpenWindow(unsigned int w, unsigned int h, bool sync, bool resizable, bool fullscreen)
{
	unsigned flags = 0;

	if (resizable)
		flags |= SDL_WINDOW_RESIZABLE;
	
	if (fullscreen)
		flags |= SDL_WINDOW_FULLSCREEN;

	flags |= SDL_WINDOW_OPENGL;

	window = SDL_CreateWindow("gfs", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);

	if (!window)
		throw std::runtime_error("Failed to create window!");

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Create an OpenGL context associated with the window.
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	return 0;
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
#pragma endregion

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
