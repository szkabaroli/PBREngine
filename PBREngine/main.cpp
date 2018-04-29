#pragma once

#include "Graphics/Graphics.h"
#include "Graphics\VertexBuffer.h"
#include "Graphics\IndexBuffer.h"
#include <string>
#include <iostream>

#define main SDL_main

static unsigned CompileShader(unsigned type, const std::string &source)
{
	unsigned id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

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

static unsigned CreateShader(const std::string &vertex, const std::string fragment)
{
	unsigned program = glCreateProgram();
	unsigned vs = CompileShader(GL_VERTEX_SHADER, vertex);
	unsigned fs = CompileShader(GL_FRAGMENT_SHADER, fragment);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	return program;
}


int main(int argc, char* argv[])
{
	Graphics g = Graphics();

	g.OpenWindow(1280, 720, true, false, false);

	
	float positions[6] = {
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	unsigned vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	VertexBuffer vbuffer(positions, 6 * sizeof(float));

	glEnableVertexAttribArray(0);
	
	
	std::string vs =
		"#version 400 core\n"
		"layout(location = 0) in vec4 position;\n"
		"void main(void) {\n"
		"gl_Position = position;}\n";

	std::string fs =
		"#version 400 core\n"
		"layout(location = 0) out vec4 color;\n"
		"void main(void) {\n"
		"color = vec4(1.0f, 0.0f, 0.0f, 1.0f);}\n";
						
	unsigned shader = CreateShader(vs, fs);
	glUseProgram(shader);

	char quit = 0;
	SDL_Event event;

	while (quit != 1)
	{
		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR) {
			std::cout << "OpenGL error: " << glewGetErrorString( err) << std::endl;
		}
		while (SDL_PollEvent(&event))
		{
			/* If a quit event has been sent */
			if (event.type == SDL_QUIT)
			{
				/* Quit the application */
				quit = 1;
			}
		}
		vbuffer.Bind();
		
		g.Clear(COLOR_CLEAR | DEPTH_CLEAR, RGBA(255, 0, 255, 0));

		g.BeginFrame();
		
		g.Draw(0, 3);
		
		g.EndFrame();

		vbuffer.Unbind();
	}


	g.CloseWindow();

	return 0;
}
