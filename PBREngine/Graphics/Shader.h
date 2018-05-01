#pragma once
#include <string>
#include <sstream>

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
	std::stringstream shaderStreams[5];
	ShaderSource(std::string src);

	std::string GetSource(EShaderType type)
	{
		return shaderStreams[(int)type].str();
	}
};

class Shader
{
public:
	Shader(ShaderSource &source);
	~Shader();

	void Link();

	void Bind();
	void Unbind();

private:
	unsigned programId;
	unsigned CompileShader(EShaderType type, std::string src);

};
