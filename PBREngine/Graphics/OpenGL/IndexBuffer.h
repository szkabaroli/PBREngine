#pragma once


class VertexBufffer
{
public:
	VertexBufffer(const void* data, unsigned size);
	~VertexBufffer();

	void Bind();
	void Unbind();

	unsigned int bufferId;
};

