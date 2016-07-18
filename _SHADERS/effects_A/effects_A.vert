#define highp
attribute           vec4    position;
attribute           vec2    uv0;

uniform             mat4    projectionMatrix;
uniform             mat4    modelMatrix;

varying     highp   vec2    uv0_PASS;

            highp   vec4    adjustposition;


varying     highp   vec4    vertexPosition;

void main()
{
    uv0_PASS            =   uv0;
    
    
    vertexPosition      =   position;
    gl_Position         =   vertexPosition;
    
    
    
    
    
    
}