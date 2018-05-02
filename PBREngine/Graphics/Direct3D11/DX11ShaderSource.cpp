#include "../Shader.h"
#include <fstream>
#include <string>
#include <sstream>

#ifdef DIRECTX_11

ShaderSource::ShaderSource(std::string fileName)
{

	std::ifstream file;
	file.open(fileName + ".cso", std::ios::binary);

	if (!file) {
		return;
	}

	std::stringstream stream;

	stream << file.rdbuf();

	file.close();

	sourceCode = stream.str();
}

#endif 

