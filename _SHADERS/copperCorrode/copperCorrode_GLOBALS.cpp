//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_copperCorrode;                                                                                  
unsigned char *fragmentSource_copperCorrode;   
//=========================================================
var         copperCorrode_LIGHT0_POS[]          = {  0, 0, 0,  0.0};

var         copperCorrode_LIGHT1_POS[]          = {    3.167998, -15.363427, 20.949535,  0.0};




int         copperCorrode_LIGHT1_DIRECTION[]    = { 1, 1, 1};

//=========================================================================

var         f_0_copperCorrode                   =  1.673991;
var         f_1_copperCorrode                   =  0.183308;
var         f_2_copperCorrode                   =   3.686874;
var         f_3_copperCorrode                   =   1.405081;
var         f_4_copperCorrode                   =   2.844343;
var         f_5_copperCorrode                   =   0.676979;
/*
var         f_0_copperCorrode                   = 70.480957;
var         f_1_copperCorrode                   =  -0.446942;
var         f_2_copperCorrode                   =   2.856047;
var         f_3_copperCorrode                   =   0.208079;
var         f_4_copperCorrode                   =   1.302179;
var         f_5_copperCorrode                   =   0.864540;
*/
GLuint      UNIFORM_f_0_copperCorrode;
GLuint      UNIFORM_f_1_copperCorrode;
GLuint      UNIFORM_f_2_copperCorrode;
GLuint      UNIFORM_f_3_copperCorrode;
GLuint      UNIFORM_f_4_copperCorrode;
GLuint      UNIFORM_f_5_copperCorrode;

//=================================================
GLuint      copperCorrode_SHADER_VERTEX;                                                                                 
GLuint      copperCorrode_SHADER_FRAGMENT;                                                                               
GLuint      copperCorrode_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POS_copperCorrode;
GLuint      UNIFORM_LIGHT1_POS_copperCorrode;
//-----
GLuint      UNIFORM_shadowBias_UMBRA_copperCorrode;
GLuint      UNIFORM_shadowBias_PENUMBRA_copperCorrode;



//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_copperCorrode;
GLuint      UNIFORM_MODELVIEW_MATRIX_copperCorrode;
GLuint      UNIFORM_invertModelViewMatrix_copperCorrode;
GLuint      UNIFORM_invertViewMatrix_copperCorrode;
GLuint      UNIFORM_invertModelMatrix_copperCorrode;

GLuint      UNIFORM_ShadowMapMatrix_copperCorrode;

//-------------------------------------------------
GLuint      UNIFORM_EMIT_copperCorrode;
GLuint      UNIFORM_DOT3_copperCorrode;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_copperCorrode;
GLuint      UNIFORM_CUBEMAP_copperCorrode;
GLuint      UNIFORM_MASK0_copperCorrode;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_copperCorrode;
GLuint      UNIFORM_caustics_WATERMAP_copperCorrode;


