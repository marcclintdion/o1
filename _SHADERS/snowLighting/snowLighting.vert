#define highp                                                                                                      



//varying     highp   vec3    column0_MVM;
//varying     highp   vec3    column1_MVM;
//varying     highp   vec3    column2_MVM;

uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;
uniform     highp   float   f_4;
uniform     highp   float   f_5;


attribute           vec4    position;
attribute           vec3    normal;


uniform             mat4    projectionMatrix;
uniform             mat4    invertViewMatrix;
uniform             mat4    modelMatrix;
uniform             mat4    modelViewMatrix;
uniform             mat4    invertModelViewMatrix;
uniform             mat4    shadowMapMatrix;
uniform             mat4    invertModelMatrix;


uniform             mat4    textureSpaceMatrix;
varying     highp   vec4    projectionTexcoord;


varying     highp   vec3    vertexNormals_0;
varying     highp   vec3    vertexNormals_1;

uniform     highp   vec4    light0_POS;
uniform     highp   vec4    light1_POS;

varying     highp   vec3    VlightPos0_PASS;
varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;


varying     highp   vec4    shadowTexcoord;

            highp   vec4    tempPos;

varying     highp   vec3    vViewVec;

varying     highp   vec4    position_PASS;


attribute           vec2    uv0;
uniform     highp   float   UVmap_SWITCH_1;
varying     highp   vec2    uv0_PASS_MIX;
varying     highp   vec2    uv0_PASS_ORIGINAL;

            highp   vec2    uvAdjust;
varying     highp   vec2    uv0_ATLAS_BL;
varying     highp   vec2    uv0_ATLAS_BR;
varying     highp   vec2    uv0_ATLAS_TL;
varying     highp   vec2    uv0_ATLAS_TR;
            highp   vec2    combine_UV_ATLAS;
varying     highp   float   wave_1_UV_ATLAS;
varying     highp   float   wave_2_UV_ATLAS;

            highp   float   preMath_1;

void main()
{                                                                                                                  
//    column0_MVM             =   projectionMatrix[0].xyz;
//    column1_MVM             =   projectionMatrix[1].xyz;
//    column2_MVM             =   projectionMatrix[2].xyz;

    
    //----------
    uvAdjust.x              =   (uv0.x * 0.5) + 0.5;
    uvAdjust.y              =    uv0.y * 0.5;
    uv0_ATLAS_BR            =    uvAdjust;
    //----------
    uvAdjust.x              =    uv0.x * 0.5;
    uvAdjust.y              =    uv0.y * 0.5;
    uv0_ATLAS_BL            =    uvAdjust;
    //----------
    uvAdjust.x              =    uv0.x * 0.5;
    uvAdjust.y              =   (uv0.y * 0.5) + 0.5;
    uv0_ATLAS_TL            =    uvAdjust;
    //----------
    uvAdjust.x              =   (uv0.x * 0.5) + 0.5;
    uvAdjust.y              =   (uv0.y * 0.5) + 0.5;
    uv0_ATLAS_TR            =    uvAdjust;
    
   
    uv0_PASS_MIX            =   mix(uv0, uv0_ATLAS_BR, UVmap_SWITCH_1);
    uv0_PASS_ORIGINAL       =   uv0;
    
    
    wave_1_UV_ATLAS         =   max(  cos(                 position.x * 6.625620 + 285.080383             ), 0.0) ;
    
    wave_2_UV_ATLAS         =   max(  cos(          (modelViewMatrix * position).x * (modelViewMatrix * position).y * f_0 + f_1 + f_2             ), 0.0) ;
    
    position_PASS           =   modelViewMatrix * (position - highp vec4(0.0, 0.0, -1.0, 1.0));

    
    projectionTexcoord      =   textureSpaceMatrix * projectionMatrix * position;

    shadowTexcoord          =   shadowMapMatrix * position;
    
    vertexNormals_0         =   normalize(modelMatrix     * vec4(normal, 0.0)).xyz;
    vertexNormals_1         =   normalize(modelViewMatrix * vec4(normal, 0.0)).xyz;
    
    
    lightPos0_PASS          =   (invertModelMatrix * light0_POS).xyz;
    lightPos1_PASS          =   (invertModelViewMatrix * highp vec4(0.0, 0.0,  1.0, 1.0)).xyz;
    
    
    
    
    vViewVec.xyz            =   highp vec3(  modelViewMatrix * position  );
    vViewVec.z              =  -vViewVec.z;

    

   
    /*
    //====================================================================================  ADJUSTING THIS KEEPS THE ROTATION POINT
    tempPos                 =   position;
    tempPos                 =   tempPos - highp vec4( 0.644022, -7.027188, 5.126598, 0.0);
    gl_Position             =   projectionMatrix * tempPos;
    //====================================================================================  AT SCREEN CENTER WHEN SCREEN IS MOVED
    */
    
    gl_Position             =  projectionMatrix * position;






}