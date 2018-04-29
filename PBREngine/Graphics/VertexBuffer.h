#pragma once


class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned size);
	~VertexBuffer();

	void Bind();
	void Unbind();

	unsigned int bufferId;
};

