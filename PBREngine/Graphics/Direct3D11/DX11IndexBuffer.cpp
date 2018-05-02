#include "../IndexBuffer.h"
#include "../../common.h"
#ifdef DIRECTX_11

IndexBuffer::IndexBuffer(const unsigned* data, unsigned count)
{

	D3D11_BUFFER_DESC bufferDesc;

	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(unsigned int) * count;
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData;

	initData.pSysMem = data;
	initData.SysMemPitch = 0;
	initData.SysMemSlicePitch = 0;

	HRESULT r = gfx.device->CreateBuffer(&bufferDesc, &initData, &buffer);
}


IndexBuffer::~IndexBuffer()
{
	if (buffer)
		buffer->Release();
}


void IndexBuffer::Bind()
{
	gfx.deviceContext->IASetIndexBuffer(buffer, DXGI_FORMAT_R32_UINT, 0);
}


void IndexBuffer::Unbind()
{

}

#endif