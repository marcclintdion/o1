//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_effects_A;                                                                                  
unsigned char *fragmentSource_effects_A;   
//=========================================================
var         effects_A_LIGHT0_POSITION[]          = { 0, 0, 12.0 , 1.0};

var         effects_A_LIGHT1_POSITION[]          = {    0.0, 0.0, 0.0,  0.0};




int         effects_A_LIGHT1_DIRECTION[]    = { 1, 1, 1};

//=========================================================================
GLuint      UNIFORM_screenRatio_effects_A;
GLuint      UNIFORM_timeIncrement_effects_A;
GLuint      UNIFORM_phaseShiftIncrement_effects_A;


bool        f_1_effects_A_DIRECTION         =   1;
GLfloat     f_1_effects_A_VELOCITY          =   0.00001;  //__RENAME_TO_AVOID_CONFUSION_WITH_GENERIC_UNIFORMS
bool        f_2_effects_A_DIRECTION         =   1;
GLfloat     f_2_effects_A_VELOCITY          =   0.00002;  //__RENAME_TO_AVOID_CONFUSION_WITH_GENERIC_UNIFORMS


var         f_0_effects_A                   =   0.143712;//0.269332
var         f_1_effects_A                   =   0.018;
var         f_2_effects_A                   =   0.00;
var         f_3_effects_A                   =   2.820082;
var         f_4_effects_A                   =  -0.050428;
var         f_5_effects_A                   =   5.563949;


GLuint      UNIFORM_f_0_effects_A;
GLuint      UNIFORM_f_1_effects_A;
GLuint      UNIFORM_f_2_effects_A;
GLuint      UNIFORM_f_3_effects_A;
GLuint      UNIFORM_f_4_effects_A;
GLuint      UNIFORM_f_5_effects_A;


GLfloat     waves_A_POSITION[]          = {-10000.0,  -1390.0,       0.0, 1.0};
GLfloat     waves_B_POSITION[]          = {  5229.1,   6480.9,       0.0, 1.0};  //997.2,   1857.0
GLfloat     waves_C_POSITION[]          = {  -753.0,  -1682.9,       0.0, 1.0};
GLfloat     waves_D_POSITION[]          = {     0.0,      0.0,       0.0, 1.0};

GLfloat     waves_A_SCALE               =  3173.0;
GLfloat     waves_B_SCALE               =  1000.0;
GLfloat     waves_C_SCALE               =  987.0;
GLfloat     waves_D_SCALE               =  0.0;

GLuint      UNIFORM_waves_A_POSITION;
GLuint      UNIFORM_waves_B_POSITION;
GLuint      UNIFORM_waves_C_POSITION;
GLuint      UNIFORM_waves_D_POSITION;

GLuint      UNIFORM_waves_A_SCALE;
GLuint      UNIFORM_waves_B_SCALE;
GLuint      UNIFORM_waves_C_SCALE;
GLuint      UNIFORM_waves_D_SCALE;

//=================================================
GLuint      effects_A_SHADER_VERTEX;                                                                                 
GLuint      effects_A_SHADER_FRAGMENT;                                                                               
GLuint      effects_A_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POSITION_effects_A;
GLuint      UNIFORM_LIGHT1_POSITION_effects_A;
//-----
GLuint      UNIFORM_shadowBias_UMBRA_effects_A;
GLuint      UNIFORM_shadowBias_PENUMBRA_effects_A;


//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_effects_A;
GLuint      UNIFORM_MODELVIEW_MATRIX_effects_A;
GLuint      UNIFORM_VIEW_MATRIX_effects_A;
GLuint      UNIFORM_MODEL_MATRIX_effects_A;

GLuint      UNIFORM_invertModelViewMatrix_effects_A;
GLuint      UNIFORM_invertViewMatrix_effects_A;
GLuint      UNIFORM_invertModelMatrix_effects_A;

GLuint      UNIFORM_ShadowMapMatrix_effects_A;

//-------------------------------------------------
GLuint      UNIFORM_EMIT_effects_A;
GLuint      UNIFORM_DOT3_effects_A;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_effects_A;
GLuint      UNIFORM_CUBEMAP_effects_A;
GLuint      UNIFORM_MASK0_effects_A;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_effects_A;
