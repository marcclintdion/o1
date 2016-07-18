//===========================
#ifdef __APPLE__
NSString* filePathName = nil;
#endif
//===========================
GLfloat turnTable      = 0.0;
GLfloat turnTableSpeed = 0.1;

GLuint      shaderNumber            = 0;

GLuint      cycleThroughShaders;

GLfloat     screenRatio             = 1080 / 1920;

GLfloat           timeIncrement_CAUSTICS_WATER      = 0;
GLfloat     phaseShiftIncrement_CAUSTICS_WATER      = 0;

GLfloat     eye_POSITION[]                  =  {  0.0,   0.0,   0.0,  1.0 };
GLfloat     eye_ROTATE[]                    =  {  1.0,   0.0,   0.0,  0.0};
GLfloat     light_1_Position[]              =  {  0.0,  -0.4, -25.0,  0.0};


GLint getOpenGL_ExtentionValues;

//-----
bool        writeSmallTexturesForMobile = 0;

int         countFrames     =  0;

time_t      gameTimerInit;
time_t      gameTimerEnd;

//-----

int         boxCount        =  1;
int         selectedModel   =  0;

GLfloat     collisionBoxArray[500][32];

bool        CONSOLE_OUTPUT                  =   false;

GLint       modelNumber                     =   0;

//-----
GLfloat     clipAdjust                      =   -0.1;

GLfloat     fieldOfView                     =   30.0;

GLfloat     reflection                      =   1.0;

GLfloat     fieldOfView_SHADOW              =   0.0;

GLfloat     FOV_shadow_UMBRA                =   0.0;
GLfloat     shadowBias_UMBRA                =   0.000050;  //0.000050

GLfloat     FOV_shadow_PENUMBRA             =  -0.750000;
GLfloat     shadowBias_PENUMBRA             =   0.000225;  //0.000225


GLsizei     resize_SHADOW_FBO = 1;
GLsizei     resize_LIGHTS_FBO = 1;

GLfloat     view_START_POSITION[]           =   {  0,  0,  -40, 1.0  };
GLfloat     view_START_ROTATION[]           =   {  1.0, 0.0, 0.0, 0.0  };

GLfloat     view_POSITION[]                 =   {  0.0, 0.0, 0.0, 1.0  };
GLfloat     view_ROTATION[]                 =   {  1.0, 0.0, 0.0, 0.0  };

bool        moveViewIntoPosition            =   true;

GLfloat     nearFarPlane_CAMERA[]           =   {  1, 1500.0 };


GLfloat     groupSceneLight_POSITION[]      =   {  0.0,        0.0,      60.0,         1.0  }; //THESE_VALUES_ARE_HARD-CODED_IN_THE_SHADOW_AND_LIGHT_TRANSFORM
//GLfloat     groupSceneLight_ROTATION[]     =   {  0.0,                   0.0               };//_THESE_ARE_BOTH_DEGREES_OF_ROTATION. FOR_X_AND_Z
GLfloat     groupSceneLight_RADIAN[]        =   {  -50.374519,  -46.056702               };//_THESE_ARE_THE_X_AND_Z_ROTATIONS_CONVERTED_TO_RADIANS.
GLfloat     groupSceneLight_VELOCITY[]      =   {  0.002,               0.002               };//_THESE_ARE_THE_X_AND_Z_ROTATIONS_CONVERTED_TO_RADIANS.


GLfloat     rotateModelWithMiddleMouse[]    =   {  0.0, 0.0  };
GLfloat     zoomModelWithMiddleMouse        =         0.0;
GLfloat     moveModelWithMiddleMouse[]      =   {  0.0, 0.0  };
//---------------------------------------------------------------------------------------

GLfloat     movingGlossyLight_POS[]         =   {  3.167998, -15.363427, 20.949535,  0.0  };
GLfloat     movingGlossyLight_DIRECTION[]   =   {  1.0, 1.0, 1.0, 1.0  };

//=================================================================================================================
//-----------------------------------------------------------------------------------------------------------------                      
//=================================================================================================================  


    #include    "_SHADERS/cubeMaps/cubeMap_GLOBALS.cpp"

    #include    "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_GLOBALS.cpp"

    #include    "_FBOs/colorDepthShadow_FBO/colorDepthShadow_FBO_GLOBALS.cpp"

    #include    "_FBOs/reflectionProjection_FBO/reflectionProjection_FBO_GLOBALS.cpp"

    #include    "_FBOs/effects_A_FBO/effects_A_FBO_GLOBALS.cpp"//_<effects_A> _NAME_CHANGE-><caustics_WATER_FBO>

    #include    "_FBOs/snowLightingPass/snowLightingPass_FBO_GLOBALS.cpp"//_<effects_A> _NAME_CHANGE-><caustics_WATER_FBO>
