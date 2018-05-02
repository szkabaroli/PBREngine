#pragma once
#include "Graphics.h"

class IndexBuffer
{
public:
	IndexBuffer(const unsigned* data, unsigned size);
	~IndexBuffer();

	void Bind();
	void Unbind();

#ifdef OPEN_GL
	unsigned bufferId;
#elif DIRECTX_11
	ID3D11Buffer* buffer;
#endif
};

