#shader vertex
#version 330 core
#define POSITION0 0

layout(location = POSITION0) in vec4 position;

out VertexData
{
  vec2 pos;
} Output;

void main(void) {
	Output.pos = position.xy;
	gl_Position = position;

}

#shader pixel
#version 330 core

in VertexData
{
  vec2 pos;
} Input;

layout(location = 0) out vec4 color;

void main(void) {
	color = vec4(1.0f * Input.pos.x, 1.0f * Input.pos.y, 1.0f, 1.0f);
}