#define highp
attribute           vec4    position;
attribute           vec2    texture;

uniform             mat4    modelMatrix;

            highp   vec4    Pos;

varying     highp   vec2    vTexCoord;



void main()
{

    Pos                     =  sign(position);

    gl_Position             =  vec4(Pos.x, Pos.y * 1.0, 0.0, 1.0);

    vTexCoord               =  texture;                                                                                         

}