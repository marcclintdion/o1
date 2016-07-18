#define highp                                                                                                      

attribute           vec4    position;
attribute           vec2    uv0;

uniform             mat4    projectionMatrix;
uniform             mat4    modelViewMatrix;
uniform             mat4    invertModelViewMatrix;
uniform             mat4    invertViewMatrix_L0;
uniform             mat4    invertModelMatrix_L1;
uniform             mat4    shadowMapMatrix;


uniform     highp   vec4    light0_POS;
            highp   vec4    light1_POS = highp vec4(0.0, 0.05, 1.0, 1.0);

varying     highp   vec3    lightPos0_PASS;

varying     highp   vec2    uv0_PASS;

varying     highp   vec4    shadowTexcoord;

            highp   vec4    tempPos;

varying     highp   vec4    Vertex;
varying     highp   vec4    inverseEye;
varying     highp   vec3    invertView;

varying     highp   vec4    VertexCubeMap;
varying     highp   vec3    wsI;


void main()
{
    //========================================================================================================================================
    VertexCubeMap           = invertModelViewMatrix * position;//___________________________________________<CUBE_MAP>
    wsI                     = VertexCubeMap.xyz * -1.0;
    //---------------------------------------------------------//THESE_TWO_FUNCTIONS_APPEAR_HAVE_THE_SAME_RESULTS_WHEN_USED_FOR_CUBEMAPPING
    Vertex                  =  modelViewMatrix * position;
    inverseEye              =  normalize(invertModelViewMatrix * vec4(0.0, 0.0, -1.0, 0.0));//_______________<FRESNEL>
    invertView              =  normalize(Vertex.xyz * inverseEye.w + inverseEye.xyz * Vertex.w);
    //========================================================================================================================================

    
    
    
    shadowTexcoord          =  shadowMapMatrix * position;
    
    lightPos0_PASS          =  (invertModelViewMatrix * light0_POS).xyz;
    
    //lightPos1_PASS          =  (invertViewMatrix_L0 * light0_POS).xyz;

    uv0_PASS                =  uv0;

   
//   /*
     //====================================================================================  ADJUSTING THIS KEEPS THE ROTATION POINT
     tempPos                 =   position;
     tempPos                 =   tempPos - highp vec4( 0.644022, -7.027188, 5.126598, 0.0);
     gl_Position             =   projectionMatrix * tempPos;
     //====================================================================================  AT SCREEN CENTER WHEN SCREEN IS MOVED
//   */
    
    gl_Position             =  projectionMatrix * position;






}