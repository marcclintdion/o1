//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_colorDepthShadows;
unsigned char *fragmentSource_colorDepthShadows;
//=========================================================
var         colorDepthShadows_LIGHT0_POS[]            = {  -17.612043, 12.247660, 55.905807 ,  0.0};

var         colorDepthShadows_LIGHT1_POS[]            = {    3.167998, -15.363427, 20.949535,  0.0};

int         colorDepthShadows_LIGHT1_DIRECTION[]      = {   1, 1, 1};

//=========================================================================
var         f_0_colorDepthShadows                     = 0.918402;
var         f_1_colorDepthShadows                     = 1.0;

var         noiseScale_colorDepthShadows              = .2;

//=================================================
GLuint      colorDepthShadows_SHADER_VERTEX;
GLuint      colorDepthShadows_SHADER_FRAGMENT;
GLuint      colorDepthShadows_SHADER;
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POS_colorDepthShadows;
GLuint      UNIFORM_movingGlossyLight_POS_colorDepthShadows;
//-----
GLuint      UNIFORM_f_0_colorDepthShadows;
GLuint      UNIFORM_f_1_colorDepthShadows;

GLuint      UNIFORM_noiseScale_colorDepthShadows;

//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_colorDepthShadows;
GLuint      UNIFORM_invertViewMatrix_colorDepthShadows;
GLuint      UNIFORM_invertModelMatrix_colorDepthShadows;
//-------------------------------------------------
GLuint      UNIFORM_TEX_COLOR_colorDepthShadows;
GLuint      UNIFORM_TEX_DOT3_colorDepthShadows;
//shadow
GLuint      UNIFORM_TEX_MASK0_colorDepthShadows;
