#include "../Shader.h"
#include "../Graphics.h"

#include <iostream>

#ifdef DIRECTX_11

Shader::Shader(ShaderSource &vsource, ShaderSource &psource)
{
	const char* vsrc = vsource.sourceCode.c_str();
	gfx.device->CreateVertexShader(vsrc, sizeof(vsrc) , nullptr, &vertexShader);
	
	const char* psrc = psource.sourceCode.c_str();
	gfx.device->CreatePixelShader(psrc, sizeof(psrc), nullptr, &pixelShader);

	gfx.vsData = vsrc;
}


Shader::~Shader()
{
	if (vertexShader)
		vertexShader->Release();
	if (pixelShader)
		pixelShader->Release();
}


void Shader::Bind()
{
	
}


void Shader::Unbind()
{
	
}

#endif 