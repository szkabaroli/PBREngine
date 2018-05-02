#include "../Graphics.h"
#include <iostream>

#ifdef DIRECTX_11

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

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);

	SDL_SysWMinfo systemInfo = { 0 };
	SDL_VERSION(&systemInfo.version);

	SDL_GetWindowWMInfo(window, &systemInfo);

	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = systemInfo.info.win.window;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.Windowed = true;

	// Create the swap chain, device and device context
	HRESULT result = D3D11CreateDeviceAndSwapChain(
		nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
		nullptr, 0, D3D11_SDK_VERSION,
		&swapChainDesc, &swapChain,
		&device, nullptr, &deviceContext);

	ID3D11Texture2D* backBuffer;

	swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
	device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);

	backBuffer->GetDesc(&backBufferDesc);
	backBuffer->Release();
}


void Graphics::CloseWindow()
{
	if (device)
	{
		device->Release();
		device = nullptr;

	}

	if (deviceContext)
	{
		deviceContext->Release();
		deviceContext = nullptr;
	}

	if (swapChain)
	{
		swapChain->Release();
		swapChain = nullptr;
	}

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

	float clearColor[] = { (float)color.r / 255u, (float)color.g / 255u, (float)color.b / 255u, (float)color.a / 255u };

	deviceContext->ClearRenderTargetView(renderTargetView, clearColor);
}


void Graphics::BeginFrame()
{
	
}


void Graphics::EndFrame()
{
	swapChain->Present(vsync ? 1 : 0, 0);
}

#endif