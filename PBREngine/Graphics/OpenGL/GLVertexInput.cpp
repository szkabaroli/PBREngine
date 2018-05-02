#include "../VertexInput.h"

#ifdef OPEN_GL

VertexInput::VertexInput()
{
	glGenVertexArrays(1, &vaoId);
}


void VertexInput::AddBuffer(unsigned location, int size, VertexBuffer buffer) 
{
	glBindVertexArray(vaoId);

	glBindBuffer(GL_ARRAY_BUFFER, buffer.bufferId);
	glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, sizeof(float) * size, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(location);

	glBindVertexArray(0);
}


void VertexInput::AddBuffer(IndexBuffer buffer)
{
	glBindVertexArray(vaoId);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.bufferId);

	glBindVertexArray(0);
}


void VertexInput::Bind()
{
	glBindVertexArray(vaoId);
}


void VertexInput::Unbind() 
{
	glBindVertexArray(0);
}


VertexInput::~VertexInput()
{
	glDeleteVertexArrays(1, &vaoId);
}

#endif