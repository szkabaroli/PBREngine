#include "../VertexInput.h"
#include <iostream>

#ifdef DIRECTX_11

VertexInput::VertexInput(VertexInputElement* e, unsigned count, IndexBuffer* indexBuffer)
{
	buffers.reserve(count);
	inputElements.reserve(count);

	for (int i = 0; i < count; i++) {

		D3D11_INPUT_ELEMENT_DESC input;

		if (e[i].binding < 4) {
			input.SemanticName = "POSITION";
			std::cout << "s" << std::endl;
		}
		else if (e[i].binding < 8)
			input.SemanticName = "COLOR";
		else if (e[i].binding < 12)
			input.SemanticName = "NORMAL";
		else if (e[i].binding < 16)
			input.SemanticName = "TANGENT";
		else if (e[i].binding < 20)
			input.SemanticName = "TEXCOORD";

		input.SemanticIndex = e[i].index;

		if(e[i].size == 1)
			input.Format = DXGI_FORMAT_R32_FLOAT;
		else if (e[i].size == 2)
			input.Format = DXGI_FORMAT_R32G32_FLOAT;
		else if (e[i].size == 3) 
			input.Format = DXGI_FORMAT_R32G32B32_FLOAT;
		

		input.InputSlot = 0;
		input.AlignedByteOffset = 0;
		input.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		input.InstanceDataStepRate = 0;

		inputElements.push_back(input);
	}

	gfx.device->CreateInputLayout(inputElements.data(), inputElements.size(), VSFile->Data, VSFile->Length, &layout);
}


void VertexInput::Bind()
{
	
}


void VertexInput::Unbind()
{
	
}


VertexInput::~VertexInput()
{
	if(layout)
		layout->Release();
}

#endif