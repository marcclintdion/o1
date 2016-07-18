//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_basic;                                                                                  
unsigned char *fragmentSource_basic;   
//=========================================================
var         basic_LIGHT0_POS[]          = {  -17.612043, 12.247660, 55.905807 ,  0.0};

var         basic_LIGHT1_POS[]          = {    3.167998, -15.363427, 20.949535,  0.0};

int         basic_LIGHT1_DIRECTION[]    = { 1, 1, 1};

//=========================================================================
var         f_0_basic                   = 0.918402;
var         f_1_basic                   = 1.0;


//=================================================
GLuint      basic_SHADER_VERTEX;                                                                                 
GLuint      basic_SHADER_FRAGMENT;                                                                               
GLuint      basic_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POS_basic;
GLuint      UNIFORM_movingGlossyLight_POS_basic;
//-----
GLuint      UNIFORM_f_0_basic;
GLuint      UNIFORM_f_1_basic;
//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_basic;
GLuint      UNIFORM_invertViewMatrix_basic;
GLuint      UNIFORM_invertModelMatrix_basic;
//-------------------------------------------------
GLuint      UNIFORM_TEX_COLOR_basic;
GLuint      UNIFORM_TEX_DOT3_basic;
//shadow
GLuint      UNIFORM_TEX_MASK0_basic;
