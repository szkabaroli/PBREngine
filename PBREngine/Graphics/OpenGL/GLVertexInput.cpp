#include "../VertexInput.h"
#include <iostream>

#ifdef OPEN_GL

VertexInput::VertexInput(VertexInputElement e[], unsigned count, IndexBuffer* indexBuffer)
{
	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	for (int i = 0; i < count; i++) {

		e[i].buffer->Bind();
		glVertexAttribPointer((e[i].binding + e[i].index), e[i].size, GL_FLOAT, GL_FALSE, sizeof(float) *  e[i].size, 0);
		e[i].buffer->Unbind();

		glEnableVertexAttribArray((e[i].binding + e[i].index));

	}
	
	indexBuffer->Bind();
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