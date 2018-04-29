#pragma once


class IndexBuffer
{
public:
	IndexBuffer(const unsigned* data, unsigned count);
	~IndexBuffer();

	void Bind();
	void Unbind();

	inline unsigned GetCount() const { return count; };

	unsigned bufferId;
	unsigned count;
};

