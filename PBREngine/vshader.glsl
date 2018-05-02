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