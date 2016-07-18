//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_mixGlazedVelvet;                                                                                  
unsigned char *fragmentSource_mixGlazedVelvet;   
//=========================================================
var         mixGlazedVelvet_LIGHT0_POS[]            = {  -17.612043, 12.247660, 55.905807 ,  0.0};

var         mixGlazedVelvet_LIGHT1_POS[]            = {    3.167998, -15.363427, 20.949535,  0.0};

int         mixGlazedVelvet_LIGHT1_DIRECTION[]      = {   1, 1, 1};

//=========================================================================
var         f_0_mixGlazedVelvet                     = 0.918402;
var         f_1_mixGlazedVelvet                     = 1.0;

var         noiseScale_mixGlazedVelvet              = .2;

//=================================================
GLuint      mixGlazedVelvet_SHADER_VERTEX;                                                                                 
GLuint      mixGlazedVelvet_SHADER_FRAGMENT;                                                                               
GLuint      mixGlazedVelvet_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POS_mixGlazedVelvet;
GLuint      UNIFORM_movingGlossyLight_POS_mixGlazedVelvet;
//-----
GLuint      UNIFORM_f_0_mixGlazedVelvet;
GLuint      UNIFORM_f_1_mixGlazedVelvet;

GLuint      UNIFORM_noiseScale_mixGlazedVelvet;

//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_mixGlazedVelvet;
GLuint      UNIFORM_invertViewMatrix_mixGlazedVelvet;
GLuint      UNIFORM_invertModelMatrix_mixGlazedVelvet;
//-------------------------------------------------
GLuint      UNIFORM_TEX_COLOR_mixGlazedVelvet;
GLuint      UNIFORM_TEX_DOT3_mixGlazedVelvet;
//shadow
GLuint      UNIFORM_TEX_MASK0_mixGlazedVelvet;
