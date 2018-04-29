#pragma once

#include "Definitions.h"
#include <SDL\SDL.h>
#include <stdint.h>
#include <iostream>

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

	bool OpenWindow(unsigned int w, unsigned int h, bool sync, bool resizable, bool fullscreen);
	void CloseWindow();

	//gfx functions
	void Clear(unsigned char flags, RGBA color);
	void BeginFrame();
	void EndFrame();

	SDL_Window* window;
};