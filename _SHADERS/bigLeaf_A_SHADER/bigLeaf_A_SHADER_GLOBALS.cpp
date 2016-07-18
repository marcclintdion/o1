//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_bigLeaf_A_SHADER;                                                                                  
unsigned char *fragmentSource_bigLeaf_A_SHADER;   
//=========================================================
var         bigLeaf_A_SHADER_LIGHT0_POS[]          = {  0, 0, 0,  0.0};

var         bigLeaf_A_SHADER_LIGHT1_POS[]          = {    3.167998, -15.363427, 20.949535,  0.0};




int         bigLeaf_A_SHADER_LIGHT1_DIRECTION[]    = { 1, 1, 1};

//=========================================================================


//=================================================
GLuint      bigLeaf_A_SHADER_VERTEX;
GLuint      bigLeaf_A_SHADER_FRAGMENT;
GLuint      bigLeaf_A_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POS_bigLeaf_A_SHADER;
GLuint      UNIFORM_LIGHT1_POS_bigLeaf_A_SHADER;
//-----
GLuint      UNIFORM_shadowBias_UMBRA_bigLeaf_A_SHADER;
GLuint      UNIFORM_shadowBias_PENUMBRA_bigLeaf_A_SHADER;

//===================================================
var         f_0_bigLeaf_A_SHADER                   =  18.312981;
var         f_1_bigLeaf_A_SHADER                   =  63.443005;
var         f_2_bigLeaf_A_SHADER                   = 199.264786;
var         f_3_bigLeaf_A_SHADER                   =   0.403601;

GLuint      UNIFORM_f_0_bigLeaf_A_SHADER;
GLuint      UNIFORM_f_1_bigLeaf_A_SHADER;
GLuint      UNIFORM_f_2_bigLeaf_A_SHADER;
GLuint      UNIFORM_f_3_bigLeaf_A_SHADER;

//===================================================
//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_bigLeaf_A_SHADER;
GLuint      UNIFORM_invertViewMatrix_bigLeaf_A_SHADER;
GLuint      UNIFORM_invertModelMatrix_bigLeaf_A_SHADER;

GLuint      UNIFORM_ShadowMapMatrix_bigLeaf_A_SHADER;

//-------------------------------------------------
GLuint      UNIFORM_EMIT_bigLeaf_A_SHADER;
GLuint      UNIFORM_DOT3_bigLeaf_A_SHADER;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_bigLeaf_A_SHADER;
GLuint      UNIFORM_CUBEMAP_bigLeaf_A_SHADER;
GLuint      UNIFORM_MASK0_bigLeaf_A_SHADER;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_bigLeaf_A_SHADER;
GLuint      UNIFORM_caustics_WATERMAP_bigLeaf_A_SHADER;
