//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_pearlPaint_A;                                                                                  
unsigned char *fragmentSource_pearlPaint_A;   
//=========================================================
var         pearlPaint_A_LIGHT0_POSITION[]          = {  -0.408043, -58.592354, 56.917809, 1.0};

var         pearlPaint_A_LIGHT1_POSITION[]          = {    0.0, 0.0, 0.0,  0.0};




int         pearlPaint_A_LIGHT1_DIRECTION[]    = { 1, 1, 1};

//=========================================================================
GLfloat     timeIncrement_BULDGE_pearlPaint_A = 0.0;

GLuint      UNIFORM_timeIncrement_BULDGE_pearlPaint_A;
GLuint      UNIFORM_timeIncrement_pearlPaint_A;

var         f_0_pearlPaint_A                   =   0.164706;//0.102186
var         f_1_pearlPaint_A                   =   0.934032;
var         f_2_pearlPaint_A                   =   1.399409;
var         f_3_pearlPaint_A                   =   0.548843;
var         f_4_pearlPaint_A                   =   26.339121;
var         f_5_pearlPaint_A                   =  -0.005376;


GLuint      UNIFORM_f_0_pearlPaint_A;
GLuint      UNIFORM_f_1_pearlPaint_A;
GLuint      UNIFORM_f_2_pearlPaint_A;
GLuint      UNIFORM_f_3_pearlPaint_A;
GLuint      UNIFORM_f_4_pearlPaint_A;
GLuint      UNIFORM_f_5_pearlPaint_A;



//=================================================
GLuint      pearlPaint_A_SHADER_VERTEX;                                                                                 
GLuint      pearlPaint_A_SHADER_FRAGMENT;                                                                               
GLuint      pearlPaint_A_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POSITION_pearlPaint_A;
GLuint      UNIFORM_LIGHT1_POSITION_pearlPaint_A;
//-----
GLuint      UNIFORM_shadowBias_UMBRA_pearlPaint_A;
GLuint      UNIFORM_shadowBias_PENUMBRA_pearlPaint_A;



//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_pearlPaint_A;
GLuint      UNIFORM_MODELVIEW_MATRIX_pearlPaint_A;
GLuint      UNIFORM_VIEW_MATRIX_pearlPaint_A;
GLuint      UNIFORM_MODEL_MATRIX_pearlPaint_A;

GLuint      UNIFORM_invertModelViewMatrix_pearlPaint_A;
GLuint      UNIFORM_invertViewMatrix_pearlPaint_A;
GLuint      UNIFORM_invertModelMatrix_pearlPaint_A;

GLuint      UNIFORM_ShadowMapMatrix_pearlPaint_A;

//-------------------------------------------------
GLuint      UNIFORM_EMIT_pearlPaint_A;
GLuint      UNIFORM_DOT3_pearlPaint_A;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_pearlPaint_A;
GLuint      UNIFORM_CUBEMAP_pearlPaint_A;
GLuint      UNIFORM_MASK0_pearlPaint_A;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_pearlPaint_A;
GLuint      UNIFORM_caustics_WATERMAP_pearlPaint_A;

