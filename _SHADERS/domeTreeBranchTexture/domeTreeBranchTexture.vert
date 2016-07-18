#define highp                                                                                                      

attribute           vec4    position;
attribute           vec2    uv0;

uniform             mat4    projectionMatrix;
uniform             mat4    invertModelMatrix;
uniform             mat4    invertModelViewMatrix;
uniform             mat4    invertViewMatrix;

uniform             mat4    shadowMapMatrix;


uniform     highp   vec4    light0_POS;
uniform     highp   vec4    light1_POS;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;


            highp   vec2    uvAdjust;

uniform     highp   vec2    adjusted_UV_IN;

varying     highp   vec2    uv0_ORIGINAL;

varying     highp   vec2    uv0_ATLAS_BL;
varying     highp   vec2    uv0_ATLAS_BR;
varying     highp   vec2    uv0_ATLAS_TL;
varying     highp   vec2    uv0_ATLAS_TR;




varying     highp   vec4    shadowTexcoord;

            highp   vec4    tempPos;

uniform     highp   vec4    position_MODEL;
varying     highp   vec4    position_PASS;

            highp   vec4    positionVertex;
            highp   vec4    positionWorld;


void main()
{                                                                                                                  
    //----------
    
    uvAdjust.x              =   uv0.x * 0.5 + 0.5           ;
    uvAdjust.y              =   uv0.y * 0.5                 ;
    uv0_ATLAS_BR            =   uvAdjust;
    //----------
    uvAdjust.x              =   uv0.x * 0.5                 ;
    uvAdjust.y              =   uv0.y * 0.5                 ;
    uv0_ATLAS_BL            =   uvAdjust;
    //----------
    uvAdjust.x              =   uv0.x * 0.5                 ;
    uvAdjust.y              =   uv0.y * 0.5 + 0.5           ;
    uv0_ATLAS_TL            =   uvAdjust;
    //----------
    uvAdjust.x              =   uv0.x * 0.5 + 0.5           ;
    uvAdjust.y              =   uv0.y * 0.5 + 0.5           ;
    uv0_ATLAS_TR            =   uvAdjust;
    

    
    /*
    //====================================================================================  ADJUSTING THIS KEEPS THE ROTATION POINT
    tempPos                 =   position;
    tempPos                 =   tempPos - highp vec4( 0.644022, -7.027188, 5.126598, 0.0);
    gl_Position             =   projectionMatrix * tempPos;
    //====================================================================================  AT SCREEN CENTER WHEN SCREEN IS MOVED
    */
    
    shadowTexcoord          =  shadowMapMatrix * position;
    
    lightPos0_PASS          =  (invertModelMatrix       * light0_POS).xyz;
    lightPos1_PASS          =  (invertModelViewMatrix   * highp vec4(0.0, 0.0, -1.0, 1.0)).xyz;
    
    uv0_ORIGINAL            =   uv0;
    
    positionVertex          =   position;
    positionWorld           =   projectionMatrix * position;
    
  //position_PASS           =   normalize(positionVertex - (positionWorld * position_MODEL));
    
    position_PASS           =   normalize( positionWorld + position_MODEL)  * sin(positionWorld.x * .03   );

    
    
    gl_Position             =   projectionMatrix * position;


}















