//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_domeTreeBranchTexture_SHADER;
unsigned char *fragmentSource_domeTreeBranchTexture_SHADER;   
//=========================================================
var         domeTreeBranchTexture_SHADER_LIGHT0_POS[]          = {  0.0, 0.0, 0.0, 0.0};

var         domeTreeBranchTexture_SHADER_LIGHT1_POS[]          = {  3.167998, -15.363427, 20.949535,  0.0};




int         domeTreeBranchTexture_SHADER_LIGHT1_DIRECTION[]    = {  1, 1, 1 };

//=========================================================================
GLuint      UNIFORM_f_0_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_f_1_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_f_2_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_f_3_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_f_4_domeTreeBranchTexture_SHADER;


var         f_0_domeTreeBranchTexture_SHADER                   =  0.0;
var         f_1_domeTreeBranchTexture_SHADER                   = -0.008405;
var         f_2_domeTreeBranchTexture_SHADER                   = -0.771402;
var         f_3_domeTreeBranchTexture_SHADER                   =  0.338099;
var         f_4_domeTreeBranchTexture_SHADER                   =  0.447767;

/*
var         f_0_domeTreeBranchTexture_SHADER =   -0.234403;
var         f_1_domeTreeBranchTexture_SHADER =   -0.748226;
var         f_2_domeTreeBranchTexture_SHADER =   -0.771402;
var         f_3_domeTreeBranchTexture_SHADER =    0.257869;
var         f_4_domeTreeBranchTexture_SHADER =  -10.254418;
*/



bool        f_0_DIRECTION_domeTreeBranchTexture_SHADER      =   true;

bool        f_2_DIRECTION_domeTreeBranchTexture_SHADER      =   true;
//=================================================
GLuint      domeTreeBranchTexture_SHADER_VERTEX;
GLuint      domeTreeBranchTexture_SHADER_FRAGMENT;
GLuint      domeTreeBranchTexture_SHADER;
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POS_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_LIGHT1_POS_domeTreeBranchTexture_SHADER;
//-----
GLuint      UNIFORM_position_MODEL_domeTreeBranchTexture_SHADER;

//-----
GLuint      UNIFORM_shadowBias_UMBRA_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_shadowBias_PENUMBRA_domeTreeBranchTexture_SHADER;

GLuint      UNIFORM_adjusted_UV_IN_domeTreeBranchTexture_SHADER;



//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_invertViewMatrix_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_invertModelMatrix_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_invertModelViewMatrix_domeTreeBranchTexture_SHADER;

GLuint      UNIFORM_ShadowMapMatrix_domeTreeBranchTexture_SHADER;

//-------------------------------------------------
GLuint      UNIFORM_EMIT_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_DOT3_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_CUBEMAP_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_MASK0_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_domeTreeBranchTexture_SHADER;
GLuint      UNIFORM_caustics_WATERMAP_domeTreeBranchTexture_SHADER;


