#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class VertexInput
{
public:
	VertexInput();

	void AddBuffer(unsigned location,int size, VertexBuffer buffer);
	void AddBuffer(IndexBuffer buffer);

	~VertexInput();

	void Bind();
	void Unbind();

	unsigned vaoId;
};

