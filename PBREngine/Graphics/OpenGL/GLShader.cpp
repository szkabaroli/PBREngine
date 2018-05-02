#include "../Shader.h"
#include "../Graphics.h"

#ifdef OPEN_GL

Shader::Shader(ShaderSource &source)
{
	programId = glCreateProgram();
	
	unsigned vs = CompileShader(VertexShader , source.GetSource(VertexShader));
	unsigned fs = CompileShader(PixelShader, source.GetSource(PixelShader));
	
	glAttachShader(programId, vs);
	glAttachShader(programId, fs);
	
	glLinkProgram(programId);
	glValidateProgram(programId);

	glDeleteShader(vs);
	glDeleteShader(fs);
}


Shader::~Shader()
{
	glDeleteProgram(programId);
}


void Shader::Bind()
{
	glUseProgram(programId);
}


void Shader::Unbind()
{
	glUseProgram(0);
}


unsigned Shader::CompileShader(EShaderType type, std::string src) 
{
	unsigned id;

	switch (type)
	{
	case VertexShader:
		id = glCreateShader(GL_VERTEX_SHADER);
		break;
	case PixelShader:
		id = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	case GeometryShader:
		id = glCreateShader(GL_GEOMETRY_SHADER);
		break;
	case HullShader:
		id = glCreateShader(GL_TESS_CONTROL_SHADER);
		break;
	case DomainShader:
		id = glCreateShader(GL_TESS_EVALUATION_SHADER);
		break;
	}

	const char* input = src.c_str();
	glShaderSource(id, 1, &input, nullptr);
	glCompileShader(id);


	///Just some error checking
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		printf("Failed to compile shader!");
		printf(message);
		glDeleteShader(id);
		return 0;
	}

	return id;
}

#endif 