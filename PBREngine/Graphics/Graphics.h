#pragma once

#include "Definitions.h"
#include <SDL\SDL.h>
#include <stdint.h>
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#ifdef OPENGL

#pragma comment (lib, "opengl32.lib")
#define GLEW_STATIC
#include <gl\glew.h>

#endif 


struct RGBA{ 
	uint8_t r, g, b, a;
	RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {};
};

struct RGB {
	uint8_t r, g, b;
	RGB(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {};
};

class Graphics {

public:
	Graphics();
	~Graphics();

	void OpenWindow(const char* title, unsigned w, unsigned h, bool sync, bool resizable, bool fullscreen);
	void CloseWindow();

	//gfx functions
	void Clear(unsigned char flags, RGBA color);
	void BeginFrame();
	void EndFrame();

	void Draw(unsigned vertexStart, unsigned vertexCount);

	SDL_Window* window;
};