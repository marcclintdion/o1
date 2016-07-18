#define highp                                                                                                      

attribute           vec4    position;
attribute           vec3    normal;
attribute           vec2    uv0;


uniform             mat4    projectionMatrix;
uniform             mat4    invertViewMatrix;
uniform             mat4    invertModelMatrix;

uniform     highp   vec4    light0_POS;
uniform     highp   vec4    light1_POS;

varying     highp   vec2    uv0_PASS;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

varying     highp   vec4    normal_PASS;
varying     highp   vec3    vViewVec;

            highp   vec4    tempPos;



void main()
{                                                                                                                  

    
    normal_PASS             =   normalize(projectionMatrix * vec4(normal, 0.0));
    vViewVec.xyz            =   highp vec3(  projectionMatrix * position );
    vViewVec.z              =  -vViewVec.z;

    
    

    lightPos0_PASS          =  (invertModelMatrix * light0_POS).xyz;
    lightPos1_PASS          =  (invertModelMatrix * light1_POS).xyz;



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