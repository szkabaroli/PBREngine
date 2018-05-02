#include "../IndexBuffer.h"
#include <assert.h>

#ifdef OPEN_GL

IndexBuffer::IndexBuffer(const unsigned* data, unsigned size)
{
	//Check the size of an unsigned int is equal to GLUint
	assert(sizeof(unsigned int) == sizeof(GLuint));

	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}


IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &bufferId);
}


void IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
}


void IndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

#endif