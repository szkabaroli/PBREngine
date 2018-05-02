#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Graphics.h"

enum EVertexInputBinding {
	POSITION0 = 0,
	COLOR
	NORMAL
	TANGENT
	TEXCOORD
};

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

