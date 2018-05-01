#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
out VertexData
{
  vec4 pos;
};

void main(void) {
	pos = position;
	gl_Position = position;

}

#shader fragment
#version 330 core

in VertexData
{
  vec4 pos;
};

layout(location = 0) out vec4 color;
void main(void) {
	color = vec4(1.0f * pos.x, 1.0f * pos.y, 1.0f, 1.0f);
}



// Geometry Shader
