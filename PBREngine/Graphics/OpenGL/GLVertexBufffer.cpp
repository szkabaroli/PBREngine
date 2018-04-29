#include "../VertexBufffer.h"
#include "GL\glew.h"


VertexBufffer::VertexBufffer(const void* data, unsigned size)
{
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, size, data,GL_STATIC_DRAW);
}


VertexBufffer::~VertexBufffer()
{
	glDeleteBuffers(1, &bufferId);
}


void VertexBufffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
}


void VertexBufffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
