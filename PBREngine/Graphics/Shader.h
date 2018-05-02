#pragma once
#include <string>
#include "../common.h"

enum EShaderType {
	None = -1,
	VertexShader = 0,
	HullShader = 1,
	DomainShader = 2,
	GeometryShader = 3,
	PixelShader = 4
};

class ShaderSource 
{
public:
	ShaderSource(std::string fileName);

	std::string sourceCode;
};

class Shader
{
public:
	Shader(ShaderSource &vsource, ShaderSource &fsource);
	~Shader();

	void Bind();
	void Unbind();

#ifdef OPEN_GL
	unsigned programId;
	unsigned CompileShader(EShaderType type, std::string src);
#elif DIRECTX_11
	ID3D11VertexShader* vertexShader;
	ID3D11PixelShader* pixelShader;
#endif 


};
