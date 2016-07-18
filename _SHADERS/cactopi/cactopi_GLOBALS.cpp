//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_cactopi;                                                                                  
unsigned char *fragmentSource_cactopi;   
//==========================================
var         cactopi_LIGHT0_POS[]          = {    0, 0,  0,  0.0};

var         cactopi_LIGHT1_POS[]          = {    3.167998, -15.363427, 20.949535,  0.0};

int         cactopi_LIGHT1_DIRECTION[]    = { 1, 1, 1};

//==========================================

var         f_0_cactopi                     = 1.0;
var         f_1_cactopi                     = 1.0;//2.379999
var         f_2_cactopi                     = 1.709999;
var         f_3_cactopi                     = -0.0;


//=================================================
GLuint      cactopi_SHADER_VERTEX;                                                                                 
GLuint      cactopi_SHADER_FRAGMENT;                                                                               
GLuint      cactopi_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POS_cactopi;
GLuint      UNIFORM_LIGHT1_POS_cactopi;
//-----
GLuint      UNIFORM_shadowBias_UMBRA_cactopi;
GLuint      UNIFORM_shadowBias_PENUMBRA_cactopi;

GLuint      UNIFORM_f_0_cactopi;
GLuint      UNIFORM_f_1_cactopi;
GLuint      UNIFORM_f_2_cactopi;
GLuint      UNIFORM_f_3_cactopi;


//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_cactopi;
GLuint      UNIFORM_MODELVIEW_MATRIX_cactopi;
GLuint      UNIFORM_invertModelViewMatrix_cactopi;
GLuint      UNIFORM_invertViewMatrix_cactopi;
GLuint      UNIFORM_invertModelMatrix_cactopi;

GLuint      UNIFORM_ShadowMapMatrix_cactopi;

//-------------------------------------------------
GLuint      UNIFORM_EMIT_cactopi;
GLuint      UNIFORM_DOT3_cactopi;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_cactopi;
GLuint      UNIFORM_CUBEMAP_cactopi;
GLuint      UNIFORM_MASK0_cactopi;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_cactopi;
GLuint      UNIFORM_caustics_WATERMAP_cactopi;
