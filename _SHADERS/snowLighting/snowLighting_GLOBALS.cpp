//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_snowLighting;                                                                                  
unsigned char *fragmentSource_snowLighting;   
//=========================================================
GLfloat     snowLighting_LIGHT0_POSITION[]       = {  0, 0, 0,  0.0};

GLfloat     snowLighting_LIGHT1_POSITION[]       = {    3.167998, -15.363427, 20.949535,  0.0};

GLfloat     snowLighting_adjustReflection_POSITION[]       = {    0, 0, 0,  0.0};

int         snowLighting_LIGHT1_DIRECTION[]      = { 1, 1, 1};

//=========================================================================
GLfloat     UVmap_SWITCH_1  = 0.0;
GLuint      UNIFORM_UVmap_SWITCH_1_snowLighting;


//f_0_snowLighting =  8.353723
//f_1_snowLighting =  1.610865
//f_2_snowLighting =  7.909798

GLfloat     f_0_snowLighting    =  0.022841;
GLfloat     f_1_snowLighting    =  32.008934;
GLfloat     f_2_snowLighting    =  276.077637;
GLfloat     f_3_snowLighting    =  1.0;
GLfloat     f_4_snowLighting    =  1.0;
GLfloat     f_5_snowLighting    =  1.0;
GLuint      UNIFORM_f_0_snowLighting;
GLuint      UNIFORM_f_1_snowLighting;
GLuint      UNIFORM_f_2_snowLighting;
GLuint      UNIFORM_f_3_snowLighting;
GLuint      UNIFORM_f_4_snowLighting;
GLuint      UNIFORM_f_5_snowLighting;

GLfloat     mixVertexAndBakedNormals_snowLighting           =  0.14;
GLuint      UNIFORM_mixVertexAndBakedNormals_snowLighting;


//=================================================
GLuint      snowLighting_SHADER_VERTEX;                                                                                 
GLuint      snowLighting_SHADER_FRAGMENT;                                                                               
GLuint      snowLighting_SHADER;     
//-------------------------------------------------
GLuint      UNIFORM_LIGHT0_POSITION_snowLighting;
GLuint      UNIFORM_movingGlossyLight_POSITION_snowLighting;;
//-----
GLuint      UNIFORM_shadowBias_UMBRA_snowLighting;
GLuint      UNIFORM_shadowBias_PENUMBRA_snowLighting;

//-------------------------------------------------
GLuint      UNIFORM_PROJECTION_MATRIX_snowLighting;
GLuint      UNIFORM_invertViewMatrix_snowLighting;
GLuint      UNIFORM_modelMatrix_snowLighting;
GLuint      UNIFORM_invertModelMatrix_snowLighting;
GLuint      UNIFORM_modelViewMatrix_snowLighting;
GLuint      UNIFORM_invertModelViewMatrix_snowLighting;
GLuint      UNIFORM_ShadowMapMatrix_snowLighting;
GLuint      UNIFORM_TEXTURE_SPACE_MATRIX_snowLighting;
//-------------------------------------------------
GLuint      UNIFORM_EMIT_snowLighting;
GLuint      UNIFORM_DOT3_snowLighting;
GLuint      UNIFORM_SHADOW_MAP_UMBRA_snowLighting;
GLuint      UNIFORM_CUBEMAP_snowLighting;
GLuint      UNIFORM_MASK0_snowLighting;
GLuint      UNIFORM_SHADOW_MAP_PENUMBRA_snowLighting;
GLuint      UNIFORM_caustics_WATERMAP_snowLighting;
