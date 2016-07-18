#define highp                                                                                                      

attribute           vec4    position;
attribute           vec3    normal;
attribute           vec2    uv0;

uniform             mat4    projectionMatrix;
uniform             mat4    invertViewMatrix_L0;

uniform             mat4    shadowMapMatrix;


uniform     highp   vec4    light0_POS;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    normal_PASS;
varying     highp   vec2    uv0_PASS;


varying     highp   vec4    shadowTexcoord;

            highp   vec4    tempPos;


void main()
{                                                                                                                  

    shadowTexcoord          =  shadowMapMatrix * position;
    
    lightPos0_PASS          =  (invertViewMatrix_L0 * light0_POS).xyz;

    uv0_PASS                =  uv0;

    normal_PASS             = (highp vec4(normal, 0.0)).xyz;
    
    /*
     //====================================================================================  ADJUSTING THIS KEEPS THE ROTATION POINT
     tempPos                 =   position;
     tempPos                 =   tempPos - highp vec4( 0.644022, -7.027188, 5.126598, 0.0);
     gl_Position             =   projectionMatrix * tempPos;
     //====================================================================================  AT SCREEN CENTER WHEN SCREEN IS MOVED
     */
    
    gl_Position             =  projectionMatrix * position;






}