#version 330 core

in VertexData
{
  vec2 pos;
} Input;

layout(location = 0) out vec4 color;

void main(void) {
	color = vec4(1.0f * Input.pos.x, 1.0f * Input.pos.y, 1.0f, 1.0f);
}