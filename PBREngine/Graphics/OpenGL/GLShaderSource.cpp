#include "../Shader.h"
#include <fstream>
#include <string>
#include <sstream>

#ifdef OPEN_GL

ShaderSource::ShaderSource(std::string fileName)
{
	std::ifstream file;
	file.open(fileName + ".glsl");

	if (!file) {
		return;
	}

	std::stringstream stream;

	stream << file.rdbuf();

	file.close();

	sourceCode = stream.str();
}

#endif 
