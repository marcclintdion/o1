//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_mixGlazedVelvet;                                                                                  
unsigned char *fragmentSource_mixGlazedVelvet;   
//=========================================================
var         mixGlazedVelvet_LIGHT0_POSITION[]       = {  -10, -11, 22,  0.0};

var         mixGlazedVelvet_LIGHT1_POSITION[]       = {   -22.131996, -169.727203, 22.000000,  0.0};

var         mixGlazedVelvet_adjustReflection_POSITION[]       = {    0, 0, 0,  0.0};

int         mixGlazedVelvet_LIGHT1_DIRECTION[]      = { 1, 1, 1};

//=========================================================================

var         f_0_mixGlazedVelvet                   =  6.925628;
var         f_1_mixGlazedVelvet                   =  6.294805;
var         f_2_mixGlazedVelvet                   =  1.0;
var         f_3_mixGlazedVelvet                   =  1.0;
var         f_4_mixGlazedVelvet                   =  1.0;
var         f_5_mixGlazedVelvet                   =  1.0;

GLuint      UNIFORM_f_0_mixGlazedVelvet;
GLuint      UNIFORM_f_1_mixGlazedVelvet;
GLuint      UNIFORM_f_2_mixGlazedVelvet;
GLuint      UNIFORM_f_3_mixGlazedVelvet;
GLuint      UNIFORM_f_4_mixGlazedVelvet;
GLuint      UNIFORM_f_5_mixGlazedVelvet;

//=================================================
GLuint      mixGlazedVelvet_SHADER_VERTEX;                                                                                 
GLuint      mixGlazedVelvet_SHADER_FRAGMENT;                                                                               
GLuint      mixGlazedVelvet_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POSITION_mixGlazedVelvet;
GLuint      UNIFORM_movingGlossyLight_POSITION_mixGlazedVelvet;;
//-----
GLuint      UNIFORM_shadowBias_UMBRA_mixGlazedVelvet;
GLuint      UNIFORM_shadowBias_PENUMBRA_mixGlazedVelvet;

//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_mixGlazedVelvet;
GLuint      UNIFORM_invertViewMatrix_mixGlazedVelvet;
GLuint      UNIFORM_modelMatrix_mixGlazedVelvet;
GLuint      UNIFORM_invertModelMatrix_mixGlazedVelvet;
GLuint      UNIFORM_modelViewMatrix_mixGlazedVelvet;
GLuint      UNIFORM_invertModelViewMatrix_mixGlazedVelvet;
GLuint      UNIFORM_ShadowMapMatrix_mixGlazedVelvet;
GLuint      UNIFORM_TEXTURE_SPACE_MATRIX_mixGlazedVelvet;
//-------------------------------------------------
GLuint      UNIFORM_EMIT_mixGlazedVelvet;
GLuint      UNIFORM_DOT3_mixGlazedVelvet;
GLuint      UNIFORM_SKY_mixGlazedVelvet;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_mixGlazedVelvet;
GLuint      UNIFORM_CUBEMAP_mixGlazedVelvet;
GLuint      UNIFORM_MASK0_mixGlazedVelvet;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_mixGlazedVelvet;
GLuint      UNIFORM_caustics_WATERMAP_mixGlazedVelvet;
