#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Graphics.h"
#include "../common.h"
#include <vector>


struct VertexInputElement {
	unsigned binding;
	unsigned index;
	unsigned size;
	VertexBuffer* buffer;
};

class VertexInput
{
public:
	VertexInput(VertexInputElement elements[], unsigned count, IndexBuffer* indexBuffer);
	~VertexInput();

	void Bind();
	void Unbind();

#ifdef OPEN_GL
	unsigned vaoId;
#elif DIRECTX_11
	std::vector<D3D11_INPUT_ELEMENT_DESC> inputElements;
	std::vector<VertexBuffer> buffers;
	ID3D11InputLayout* layout;
#endif // OPEN_GL

	
};

