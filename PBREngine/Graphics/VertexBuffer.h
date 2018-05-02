#pragma once
#include "Graphics.h"

class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned size);
	~VertexBuffer();

	void Bind();
	void Unbind();

#ifdef OPEN_GL
	unsigned bufferId;
#elif DIRECTX_11
	ID3D11Buffer* vertexBuffer;
#endif
};

