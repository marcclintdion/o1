#define highp                                                                                                      

attribute           vec4    position;
attribute           vec3    normal;

attribute           vec2    uv0;

uniform             mat4    projectionMatrix;
uniform             mat4    invertViewMatrix;
uniform             mat4    modelMatrix;
uniform             mat4    modelViewMatrix;
uniform             mat4    invertModelViewMatrix;
uniform             mat4    shadowMapMatrix;
uniform             mat4    invertModelMatrix;


uniform             mat4    textureSpaceMatrix;
varying     highp   vec4    projectionTexcoord;


varying     highp   vec3    vertexNormals;

uniform     highp   vec4    light0_POS;
uniform     highp   vec4    light1_POS;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

varying     highp   vec2    uv0_PASS;

varying     highp   vec4    shadowTexcoord;

            highp   vec4    tempPos;

varying     highp   vec3    vViewVec;

//varying     highp   vec3    column0_MVM;
//varying     highp   vec3    column1_MVM;
//varying     highp   vec3    column2_MVM;
varying     highp   vec4    position_PASS;



void main()
{                                                                                                                  
//    column0_MVM             =   projectionMatrix[0].xyz;
//    column1_MVM             =   projectionMatrix[1].xyz;
//    column2_MVM             =   projectionMatrix[2].xyz;
    
    position_PASS           =   modelViewMatrix * (position - highp vec4(0.0, 0.0, -1.0, 1.0));

    
    projectionTexcoord      =   textureSpaceMatrix * projectionMatrix * position;

    shadowTexcoord          =   shadowMapMatrix * position;
    
    lightPos0_PASS          =   (invertModelMatrix * light0_POS).xyz;
    
    lightPos1_PASS          =   (invertModelViewMatrix * highp vec4(0.0, 0.0, -1.0, 1.0)).xyz;
    
    vertexNormals           =   normalize(modelMatrix * vec4(normal, 0.0)).xyz;
    
    vViewVec.xyz            =   highp vec3(  modelViewMatrix * position  );
    vViewVec.z              =  -vViewVec.z;

    
    uv0_PASS                =   uv0;

   
    /*
    //====================================================================================  ADJUSTING THIS KEEPS THE ROTATION POINT
    tempPos                 =   position;
    tempPos                 =   tempPos - highp vec4( 0.644022, -7.027188, 5.126598, 0.0);
    gl_Position             =   projectionMatrix * tempPos;
    //====================================================================================  AT SCREEN CENTER WHEN SCREEN IS MOVED
    */
    
    gl_Position             =  projectionMatrix * position;






}