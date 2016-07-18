//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_marbleReflection;                                                                                  
unsigned char *fragmentSource_marbleReflection;   
//=========================================================
var         marbleReflection_LIGHT0_POSITION[]       = {  0, 0, 0,  0.0};

var         marbleReflection_LIGHT1_POSITION[]       = {    3.167998, -15.363427, 20.949535,  0.0};

int         marbleReflection_LIGHT1_DIRECTION[]      = { 1, 1, 1};

//=========================================================================

var         f_0_marbleReflection                   = 0.417801;
var         f_1_marbleReflection                   = 0.510259;
var         f_2_marbleReflection                   = 2.813083;
var         f_3_marbleReflection                   = 0.712152;
var         f_4_marbleReflection                   = 1.0;

GLuint      UNIFORM_f_0_marbleReflection;
GLuint      UNIFORM_f_1_marbleReflection;
GLuint      UNIFORM_f_2_marbleReflection;
GLuint      UNIFORM_f_3_marbleReflection;
GLuint      UNIFORM_f_4_marbleReflection;
//=================================================
GLuint      marbleReflection_SHADER_VERTEX;                                                                                 
GLuint      marbleReflection_SHADER_FRAGMENT;                                                                               
GLuint      marbleReflection_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POSITION_marbleReflection;
GLuint      UNIFORM_movingGlossyLight_POSITION_marbleReflection;;
//-----
GLuint      UNIFORM_shadowBias_UMBRA_marbleReflection;
GLuint      UNIFORM_shadowBias_PENUMBRA_marbleReflection;

//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_marbleReflection;
GLuint      UNIFORM_invertModelMatrix_marbleReflection;
GLuint      UNIFORM_invertModelViewMatrix_marbleReflection;
GLuint      UNIFORM_invertViewMatrix_marbleReflection;
GLuint      UNIFORM_modelViewMatrix_marbleReflection;
GLuint      UNIFORM_ShadowMapMatrix_marbleReflection;
GLuint      UNIFORM_TEXTURE_SPACE_MATRIX_marbleReflection;

//-------------------------------------------------
GLuint      UNIFORM_EMIT_marbleReflection;
GLuint      UNIFORM_DOT3_marbleReflection;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_marbleReflection;
GLuint      UNIFORM_REFLECTION_marbleReflection;
GLuint      UNIFORM_MASK0_marbleReflection;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_marbleReflection;
GLuint      UNIFORM_caustics_WATERMAP_marbleReflection;
