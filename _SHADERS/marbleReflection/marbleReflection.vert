#define highp                                                                                                      

attribute           vec4    position;
attribute           vec3    normal;

attribute           vec2    uv0;


uniform             mat4    projectionMatrix;
uniform             mat4    invertModelMatrix;
uniform             mat4    invertModelViewMatrix;
uniform             mat4    invertViewMatrix;
uniform             mat4    modelViewMatrix;

uniform             mat4    shadowMapMatrix;
varying     highp   vec4    shadowTexcoord;

uniform             mat4    textureSpaceMatrix;
varying     highp   vec4    projectionTexcoord;

varying     highp   vec3    normal_PASS;

uniform     highp   vec4    light0_POS;
uniform     highp   vec4    light1_POS;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

varying     highp   vec2    uv0_PASS;


            highp   vec4    tempPos;

varying     highp   vec3    vViewVec;


void main()
{                                                                                                                  

    projectionTexcoord      =  textureSpaceMatrix * projectionMatrix * position;
    
    
    shadowTexcoord          =  shadowMapMatrix * position;
    
    lightPos0_PASS          =  (invertModelMatrix * light0_POS).xyz;
    lightPos1_PASS          =  (invertModelViewMatrix * highp vec4(0.0, 0.0, -1.0, 1.0)).xyz;
    
    
    normal_PASS             =   normalize(modelViewMatrix * vec4(normal, 0.0)).xyz;
    
    vViewVec.xyz            =   highp vec3(  modelViewMatrix * position );
    vViewVec.z              =  -vViewVec.z;

    
    uv0_PASS                =  uv0;

   
    /*
    //====================================================================================  ADJUSTING THIS KEEPS THE ROTATION POINT
    tempPos                 =   position;
    tempPos                 =   tempPos - highp vec4( 0.644022, -7.027188, 5.126598, 0.0);
    gl_Position             =   projectionMatrix * tempPos;
    //====================================================================================  AT SCREEN CENTER WHEN SCREEN IS MOVED
    */
    
    gl_Position             =  projectionMatrix * position;






}