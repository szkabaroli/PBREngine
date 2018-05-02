#include "Shader.h"
#include <fstream>
#include <iostream>
#include <string>


ShaderSource::ShaderSource(std::string path)
{
	std::ifstream file(path);

	std::string line;

	EShaderType type = EShaderType::None;

	while (getline(file,line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = EShaderType::VertexShader;
			else if (line.find("pixel") != std::string::npos)
				type = EShaderType::PixelShader;
		}
		else
			shaderStreams[(int)type] << line << '\n';
	}
}
