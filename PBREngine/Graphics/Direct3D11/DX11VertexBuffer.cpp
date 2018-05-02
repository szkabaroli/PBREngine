#include "../VertexBuffer.h"
#include "../../common.h"
#include <iostream>

#ifdef DIRECTX_11

VertexBuffer::VertexBuffer(const void* data, unsigned size)
{
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = size;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = data;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	
	HRESULT r = gfx.device->CreateBuffer(&bufferDesc, &InitData, &vertexBuffer);
}


VertexBuffer::~VertexBuffer()
{
	if(vertexBuffer)
		vertexBuffer->Release();
}


void VertexBuffer::Bind()
{
	///TODO
}


void VertexBuffer::Unbind()
{
	///TODO
}

#endif