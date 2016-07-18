#define highp                                                                                                      

attribute           vec4    position;
attribute           vec3    normal;
attribute           vec2    uv0;


uniform             mat4    projectionMatrix;
uniform             mat4    modelViewMatrix;
uniform             mat4    viewMatrix;

uniform             mat4    modelMatrix;

uniform             mat4    invertModelViewMatrix;
uniform             mat4    invertViewMatrix_L0;
uniform             mat4    invertModelMatrix_L1;
uniform             mat4    shadowMapMatrix;


uniform     highp   vec4    light0_POSITION;

varying     highp   vec3    lightPos0_PASS;

uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;

uniform     highp   float   timeIncrement;


varying     highp   vec2    uv0_PASS;

varying     highp   vec4    shadowTexcoord;

            highp   vec4    tempPos;


varying     highp   vec4    vertexNormals;

varying     highp   vec3    column0_MVM;
varying     highp   vec3    column1_MVM;
varying     highp   vec3    column2_MVM;

varying     highp   vec4    position_PASS;

            highp   float   angle_rad;


void main()
{
   
    
    //__CUBEMAP__=================================================================================
    
    
    position_PASS           =  modelViewMatrix * (position - highp vec4(0.0, 0.0,  -1.0, 0.0));
    
    angle_rad               =  55.0 * 3.14159 / 180.0;
    position_PASS.y         =  position_PASS.y * cos(angle_rad) + position_PASS.z * sin(angle_rad);
    position_PASS.z         = -position_PASS.y * sin(angle_rad) + position_PASS.z * cos(angle_rad);
    
    column0_MVM             =   vec3(modelViewMatrix[0].xyz);
    column1_MVM             =   vec3(modelViewMatrix[1].xyz);
    column2_MVM             =   vec3(modelViewMatrix[2].xyz);
   
    //__CUBEMAP__=================================================================================
    
    
    
    vertexNormals           =   modelViewMatrix * highp vec4(normal, 0.0);

    shadowTexcoord          =   shadowMapMatrix * position;


    uv0_PASS                =  uv0;

   
//   /*
     //====================================================================================  ADJUSTING THIS KEEPS THE ROTATION POINT
     //tempPos                 =   position;
     //tempPos                 =   tempPos - highp vec4( 0.644022, -7.027188, 5.126598, 0.0);
     //gl_Position             =   projectionMatrix * tempPos;
     //====================================================================================  AT SCREEN CENTER WHEN SCREEN IS MOVED
//   */
    
    //__WARP___===================================================================================
    highp float displacement    = 0.5 * 0.5 * sin(position.y * 3.185365 + timeIncrement)+1.0;
    highp vec4  displaceVector  = highp vec4(normal.xyz, 0.0) *.5;
    highp vec4  warpedPosition  = position + displaceVector * displacement;
    highp vec4  warpedLight     = light0_POSITION;

    warpedLight.y   =  cos(displacement) * warpedLight.y + sin(displacement) * warpedLight.z;
    warpedLight.z   = -sin(displacement) * warpedLight.y + cos(displacement) * warpedLight.z;
    //__WARP___===================================================================================
    lightPos0_PASS          =   (invertModelMatrix_L1 * warpedLight).xyz;
    
    gl_Position             =  projectionMatrix * warpedPosition;
   //gl_Position             =  projectionMatrix * position;






}