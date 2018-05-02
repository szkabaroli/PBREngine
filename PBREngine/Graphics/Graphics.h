#pragma once

#include "Definitions.h"
#include <SDL\SDL.h>
#include "SDL\SDL_syswm.h"
#include <stdint.h>
/*#include "VertexBuffer.h"
#include "IndexBuffer.h"*/

#ifdef OPEN_GL

#pragma comment (lib, "opengl32.lib")
#define GLEW_STATIC
#include <gl\glew.h>

#endif

#ifdef DIRECTX_11

#pragma comment (lib, "d3d11.lib")

#include <d3d11.h>

#endif


struct RGBA{ 
	uint8_t r, g, b, a;
	RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {};
};

class Graphics  {

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
	void Draw(int size);

	SDL_Window* window = nullptr;

	bool vsync;
	bool resizable;
	bool fullscreen;

#ifdef DIRECTX_11
	IDXGISwapChain* swapChain = nullptr;
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* deviceContext = nullptr;
	ID3D11RenderTargetView* renderTargetView = nullptr;
	D3D11_TEXTURE2D_DESC backBufferDesc;
#endif // DIRECTX_11


};