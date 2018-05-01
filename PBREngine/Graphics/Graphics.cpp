#include "Graphics.h"
#include <iostream>

Graphics::Graphics() 
{
	if (SDL_Init(SDL_INIT_VIDEO))
		throw std::runtime_error("Failed to initilize SDL2!");

}


Graphics::~Graphics() 
{
	this->CloseWindow();
	SDL_Quit();
}
