#include "../VertexBuffer.h"
#include "../Graphics.h"


VertexBuffer::VertexBuffer(const void* data, unsigned size)
{
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	//glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &bufferId);
}


void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
}


void VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
