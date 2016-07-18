//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_copperCorrode_B;                                                                                  
unsigned char *fragmentSource_copperCorrode_B;   
//=========================================================
var         copperCorrode_B_LIGHT0_POS[]                = {    0, 0,  0,  1.0};

var         copperCorrode_B_LIGHT1_POS[]                = {    3.167998, -15.363427, 20.949535,  1.0};

var         copperCorrode_B_adjustReflection_POSITION[] = {    394.662628, -453.635132, 326.617462,  1.0};//394.662628, -453.635132, 326.617462,  0.0



int         copperCorrode_B_LIGHT1_DIRECTION[]    = { 1, 1, 1};

//=========================================================================
GLfloat     animateAniso_AO_mask_DIRECTION          = 1.0;
GLfloat     animateAniso_AO_mask_VELOCITY           = 0.001;

var         animateAniso_AO_mask_copperCorrode_B  	=   0.0;
GLuint      UNIFORM_animateAniso_AO_mask_copperCorrode_B;


var         f_0_copperCorrode_B                     = 500.674316;
var         f_1_copperCorrode_B                     = -0.022399;
var         f_2_copperCorrode_B                     = 1.709999;
var         f_3_copperCorrode_B                     = 0.353194;
var         f_4_copperCorrode_B                     = 1.709999;
var         f_5_copperCorrode_B                     = 1.0;


GLuint      UNIFORM_f_0_copperCorrode_B;
GLuint      UNIFORM_f_1_copperCorrode_B;
GLuint      UNIFORM_f_2_copperCorrode_B;
GLuint      UNIFORM_f_3_copperCorrode_B;
GLuint      UNIFORM_f_4_copperCorrode_B;
GLuint      UNIFORM_f_5_copperCorrode_B;



//=================================================
GLuint      copperCorrode_B_SHADER_VERTEX;                                                                                 
GLuint      copperCorrode_B_SHADER_FRAGMENT;                                                                               
GLuint      copperCorrode_B_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POS_copperCorrode_B;
GLuint      UNIFORM_LIGHT1_POS_copperCorrode_B;
//-----
GLuint      UNIFORM_shadowBias_UMBRA_copperCorrode_B;
GLuint      UNIFORM_shadowBias_PENUMBRA_copperCorrode_B;




//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_copperCorrode_B;
GLuint      UNIFORM_MODELVIEW_MATRIX_copperCorrode_B;
GLuint      UNIFORM_invertModelViewMatrix_copperCorrode_B;
GLuint      UNIFORM_invertViewMatrix_copperCorrode_B;
GLuint      UNIFORM_invertModelMatrix_copperCorrode_B;

GLuint      UNIFORM_ShadowMapMatrix_copperCorrode_B;
//-------------------------------------------------
GLuint      UNIFORM_EMIT_copperCorrode_B;
GLuint      UNIFORM_DOT3_copperCorrode_B;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_copperCorrode_B;
GLuint      UNIFORM_CUBEMAP_copperCorrode_B;
GLuint      UNIFORM_MASK0_copperCorrode_B;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_copperCorrode_B;
GLuint      UNIFORM_caustics_WATERMAP_copperCorrode_B;




