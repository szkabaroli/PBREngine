#shader vertex
struct Output 
{
	float2 position : SV_POSITION;
};

Output main( float2 pos : POSITION )
{
	return pos;
}

#shader pixel
struct Input 
{
	float2 position : SV_POSITION;
	float3 color : COLOR;
};

float4 main(Input input) : SV_TARGET 
{
	return float4(1.0f * input.position.x, 1.0f * input.position.y, 1, 1);
}