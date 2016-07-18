//==================================
#ifdef __APPLE__
#include <TargetConditionals.h>
#endif
//==================================
//==================================
//==================================
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//================================================================================================================================
#define var GLfloat
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))//to_use-> COUNT_OF( floorTile_2m_INDICES)
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//================================================================================================================================
bool renderTurntable = false;

int  viewWidth  = 1920;
int  viewHeight = 1080;

int  Pass_MIDDLE_Mouse[]        =  { 0, 0 };     //AT_SHUTDOWN_THESE_VALUES_ARE_BEING_PRINTED_THE_FILE->loadMouseSettings.cpp
int  Pass_MIDDLE_CONTROL_Mouse;
int  Pass_MIDDLE_SHIFT_Mouse[]  =  { 0, 0 };     //AT_RUNTIME_THESE_ARE_BEING_LOADED_INTO->WGL_ARB_multiSample.h

int mousePosCurrent[]           =  { 0, 0 };
int mousePosPrevious[]          =  { 0, 0 };

bool LEFT_BUTTON_DOWN           =   false;
bool RIGHT_BUTTON_DOWN          =   false;
bool MIDDLE_BUTTON_DOWN         =   false;
bool MOUSE_MOVE                 =   false;
bool LEFT_BUTTON_UP             =   false;
bool RIGHT_BUTTON_UP            =   false;
bool MIDDLE_BUTTON_UP           =   false;

//================================
#include "KEYBOARD/OS_DEFINES.cpp"
//==============================================================
#include "cpp/timer_B.cpp"
//==============================================================
#include "cpp/configure_GL.cpp"
//==============================================================
#include "headerFiles/FreeImage.h"     // INSTALLED_TO /usr/local/lib
//==============================================================
#include "cpp/microsoft_WINDOW.cpp"
//==============================================================
#include "cpp/frameBuffer_GLOBALS.cpp" // _iOS_//_TEST_BEFORE_MOVING
//==============================================================

#include "MATRIX_MATH.cpp"

//===========================================================================================================================================================

#include            "GLOBALS.cpp"   ///////////////////////------------CONSIDER_ADDING_Textures_GLOBALS.cpp // for FBO's, CubeMaps, Fresnel, etc...
#include     "Models_GLOBALS.cpp" 
#include    "Shaders_GLOBALS.cpp"

//===========================================================================================================================================================

#include "cpp/FreeImage.cpp"

//===========================================================================================================================================================

unsigned char *readShaderFile( const char *fileName );
void initializeAssets(void)
{
    #include            "INIT.cpp"
    #include     "Models_INIT.cpp"  ///////////////////////----------CONSIDER_ADDING_Textures_INIT.cpp
    #include    "Shaders_INIT.cpp"
    
    cycleThroughShaders = (GLuint)shaderNumber;

}

//===========================================================================================================================================================

#include "cpp/transformStacks.cpp"

//===========================================================================================================================================================

#include "cpp/loadRuntimeShader.cpp"

//===========================================================================================================================================================

#include "selectShader_RENDER.cpp"

//===========================================================================================================================================================

void ViewShadow_TRANSFORM(void)
{
    // code is currently found in -> View_TRANSFORM();
}

//===========================================================================================================================================================

void View_TRANSFORM(void)
{
    
    
    LoadIdentity(viewMatrix);
 
    Translate(   viewMatrix,     view_START_POSITION[0],    view_START_POSITION[1],         view_START_POSITION[2]);
    
    Translate(   viewMatrix,     view_POSITION[0],          view_POSITION[1],               view_POSITION[2]);
   
    Rotate(      viewMatrix,     1.0,    0.0,    0.0,       view_START_ROTATION[3]);
    
    
    Rotate(      viewMatrix,     1.0,    0.0,    0.0,       rotateModelWithMiddleMouse[0]);
    Rotate(      viewMatrix,     0.0,    0.0,    1.0,      -rotateModelWithMiddleMouse[1]);
 
    Rotate(      viewMatrix,     0.0,    0.0,    1.0,       turnTable);
    //Rotate(      viewMatrix,     0.0,    0.0,    1.0,       turnTable += turnTableSpeed);
   
    
    //----------
    LoadIdentity(invertViewMatrix);
    InvertMatrix(invertViewMatrix, viewMatrix);
    //=========================================
    groupSceneLight_POSITION[0] =   0.0;
    groupSceneLight_POSITION[1] =   0.0;
    groupSceneLight_POSITION[2] =  60.0;
    shadow_ROTATION[0]          =   0.0;
    shadow_ROTATION[1]          =   0.0;
    
    
    
    
    //groupSceneLight_POSITION[1]     =   groupSceneLight_POSITION[1] * cos(groupSceneLight_RADIAN[0])    -   groupSceneLight_POSITION[2] * sin(groupSceneLight_RADIAN[0]);
    //groupSceneLight_POSITION[2]     =   groupSceneLight_POSITION[1] * sin(groupSceneLight_RADIAN[0])    +   groupSceneLight_POSITION[2] * cos(groupSceneLight_RADIAN[0]);
   
    //groupSceneLight_POSITION[0]     =   groupSceneLight_POSITION[0] * cos(groupSceneLight_RADIAN[1])    -   groupSceneLight_POSITION[1] * sin(groupSceneLight_RADIAN[1]);
    //groupSceneLight_POSITION[1]     =   groupSceneLight_POSITION[0] * sin(groupSceneLight_RADIAN[1])    +   groupSceneLight_POSITION[1] * cos(groupSceneLight_RADIAN[1]);
    
    //shadow_ROTATION[0]       =   -50.374519;
    //shadow_ROTATION[1]       =   -46.056702;
    
    //shadow_ROTATION[0]             -=   groupSceneLight_RADIAN[0] * 180.0 / 3.14159;
    //shadow_ROTATION[1]             -=   groupSceneLight_RADIAN[1] * 180.0 / 3.14159;

    LoadIdentity(viewShadowMatrix);
    

    //Translate(   viewShadowMatrix,     view_START_POSITION[0],    view_START_POSITION[1],         view_START_POSITION[2]);
    
    
    Translate(   viewShadowMatrix,     shadow_POSITION[0],          shadow_POSITION[1],               shadow_POSITION[2]);
    
    Rotate(      viewShadowMatrix,     1.0,    0.0,    0.0,     shadow_ROTATION[0] );
    Rotate(      viewShadowMatrix,     0.0,    0.0,    1.0,     shadow_ROTATION[1] );
    
    //----------
    LoadIdentity(invertViewShadowMatrix);
    InvertMatrix(invertViewShadowMatrix, invertViewMatrix);
    //=====================================================
    
    #ifdef __APPLE__
    if(CONSOLE_OUTPUT)
    {
        NSLog(@"view_POSITION[]   %f,  %f,  %f = ", view_POSITION[0],   view_POSITION[1],   view_POSITION[2]);
        NSLog(@"shadow_ROTATION[] %f,  %f = ", shadow_ROTATION[0], shadow_ROTATION[1]);
    }
    #endif
    
}

//===========================================================================================================================================================

#if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
//TOUCH_SCREEN_CONTROLS_GO_HERE
//====================================
#elif TARGET_OS_MAC == 1 || WIN32 == 1
void ProcessKeyboard(void)
{
    #include "KEYBOARD/ProcessKeyboard.cpp"
}//__END->ProcessKeyboard()
#endif

//===========================================================================================================================================================

void renderDepthShadow_UMBRA_PASS(void)
{
fieldOfView_SHADOW  =     0.0; //_SAME_FOV_AS_MAIN_COLOR_CAMERA
    glBindFramebuffer(GL_FRAMEBUFFER, colorDepthShadows_UMBRA_FBO);// <colorDepthShadows_UMBRA_FBO_COLOR_TEXTURE> <colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE>
    shadow_SIZE_MULTIPLIER  = shadow_SIZE_UMBRA_MULTIPLIER;
    shadow_SIZE_DIVISOR     = shadow_SIZE_UMBRA_DIVISOR;
    #include "drawDepth.cpp"
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

}//__END->renderDepthShadow_UMBRA_PASS()

//===========================================================================================================================================================

void renderDepthShadow_PENUMBRA_PASS(void)
{

fieldOfView_SHADOW  =     FOV_shadow_PENUMBRA;
    glBindFramebuffer(GL_FRAMEBUFFER, colorDepthShadows_PENUMBRA_FBO);// <colorDepthShadows_UMBRA_FBO_COLOR_TEXTURE> <colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE>
    shadow_SIZE_MULTIPLIER  = shadow_SIZE_PENUMBRA_MULTIPLIER;
    shadow_SIZE_DIVISOR     = shadow_SIZE_PENUMBRA_DIVISOR;
    #include "drawDepth.cpp"
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

}//__END->renderDepthShadow_PENUMBRA_PASS()

//===========================================================================================================================================================
#include <string.h>

char *savedTextureName;
int  turnTableCounter = 0;

void renderMainColor_PASS(void)
{
    //glBindFramebuffer(GL_FRAMEBUFFER, effects_A_FBO);// <effects_A_FBO_COLOR_TEXTURE> <effects_A_FBO_DEPTH_TEXTURE>
    //    shaderNumber = 27;//CAUSTICS
    //    #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"//CAUSTICS
    //glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
    //glBindFramebuffer(GL_FRAMEBUFFER, snowLightingPass_FBO);
    //shaderNumber = 28;
    //#include "drawSnowLighting.cpp"
    //glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
    
    /*
    glBindFramebuffer(GL_FRAMEBUFFER, reflectionProjection_FBO);// <reflectionProjection_FBO_COLOR_TEXTURE> <reflectionProjection_FBO_DEPTH_TEXTURE>
    reflection   = -1.0;
    #include "drawReflectionPass.cpp"
    reflection   = 1.0;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    */
    
    
    o1_POSITION[0] = +120.0;
    o1_POSITION[1] = -40.0;
    o1_POSITION[2] = -40.0;
    
    //--------------------------
    #include "drawMainColor.cpp"
    //--------------------------

     

    
    
    
    
    
    
}//__END->renderMainColor_PASS()


//===========================================================================================================================================================

void finalComposite(void)
{
    glActiveTexture (GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D,  colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE );
    glActiveTexture (GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,  colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE );//reflectionProjection_FBO_COLOR_TEXTURE   shadow_POSITION
    //-----------
    shaderNumber = 10;
    //#include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_RENDER.cpp"//finalComposite

}//__END->finalComposite()

//===========================================================================================================================================================

void shutDownGL( void )
{

    #include "END.cpp"
    #include "END_MODELS.cpp"
    #include "END_SHADERS.cpp"

}//__END->shutDownGL()

//===========================================================================================================================================================



//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------



void InitGL( void )//__BEGIN_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
{
        start = getMilliCount();
    

      
        //=====================================
        #ifdef WIN32
            #include "cpp/setPixelFormat.cpp"
            #include "include/glext_Init_B.cpp"
            //alutInit(NULL, 0);
            //------------------
            SetVSyncState(true);
    
        #endif
    
  
    
//=======================================================
#if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
//=======================================================
    glGenTextures(1, &m_uiShadowMapTexture);
    //------------
    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,(GLsizei)viewHeight , (GLsizei)viewWidth, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //------------------------------------------------------------------
    glGenFramebuffers(1, &m_uiFrameBufferObject);
    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
    //---------------------
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//====================================
#elif TARGET_OS_MAC == 1 || WIN32 == 1
//====================================
     glGenTextures(1, &m_uiShadowMapTexture);
    //------------
    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,(GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //------------------------------------------------------------------
    glGenFramebuffers(1, &m_uiFrameBufferObject);
    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
    //---------------------
#ifdef WIN32
    glDrawBuffer(GL_NONE);//_ON_SOME_MACHINES_THIS_IS_REQUIRED / ON_SOME_IT_FAILS
    glReadBuffer(GL_NONE);//_SAME_AS_ABOVE
#endif
    //---------------------
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);   

//=====
#endif
//=====    



#ifdef __APPLE__    
    //NSLog(@"viewWidth  = %i pixels", (int)viewWidth);
    //NSLog(@"viewHeight = %i pixels", (int)viewHeight);
#endif    
    
    
    //---------------------------
    initializeAssets();
    //---------------------------
    screenRatio =   (GLfloat)viewWidth / (GLfloat)viewHeight;


    //=======================
    #ifdef WIN32
        //atexit(KillALData);//(WHY_NOT_TRY_SDL_INSTEAD. SDL_CAN_WRITE_TO_THE_SOUND_BUFFER_AND_ALSO_APPEARS_TO_BE_JUST_AS_CROSS_PLATFORM_CAPABLE).
    #endif
    
    
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    //glDepthFunc(GL_EQUAL);
    glDepthFunc(GL_LESS);
    //glDepthMask(1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
    glDisable(GL_BLEND);
//====================================================================================================================================

}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

int runonce = 1;

float counter = 0.0;



void RenderGL(void)
{
    //=====================================================================================
    //=====================================================================================
    //=====================================================================================
    //=====================================================================================
    glActiveTexture (GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D,        colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE);
    //--------------
    glActiveTexture (GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_CUBE_MAP,  cubemapTexture[0]);
    //--------------
    glActiveTexture (GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D,        colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);
    //--------------
    glActiveTexture (GL_TEXTURE6);
    glBindTexture(GL_TEXTURE_2D,        effects_A_FBO_COLOR_TEXTURE);//_<effects_A> _NAME_CHANGE-><caustics_WATER_FBO>
    
    //=====================================================================================
    //=====================================================================================
    //=====================================================================================
    //=====================================================================================
    

frameStart = getMilliSpan(start);



  

    
//=======================================================================================================================

      
                        //=================================================================
                        #if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
                        //--------------         
                                //eye_POSITION[0] -= PassTouchMovement[0];
                                //eye_POSITION[1] -= PassTouchMovement[1];
                                //eye_POSITION[2] -= PassTouchMovement[2];                   
                        
                                //PassTouchMovement[0] = 0.0;
                                //PassTouchMovement[1] = 0.0;
                                //PassTouchMovement[2] = 0.0;
                        
                        //--------------                        
                        #endif 
                        //=================================================================
                                      
    
                                rotateModelWithMiddleMouse[0]   = (float)Pass_MIDDLE_Mouse[0]*.5;
                                rotateModelWithMiddleMouse[1]   = (float)Pass_MIDDLE_Mouse[1]*.5;
                                //-------------------------------------------------------
                                view_POSITION[2] = (float)Pass_MIDDLE_CONTROL_Mouse*.7;
                                //-------------------------------------------------------
                                view_POSITION[0] = (float)Pass_MIDDLE_SHIFT_Mouse[0]*.1;
                                view_POSITION[1] = (float)Pass_MIDDLE_SHIFT_Mouse[1]*.1;
    
    



    //==============================================================
  
    


    
    

renderDepthShadow_UMBRA_PASS();
    
 
    

renderDepthShadow_PENUMBRA_PASS();
    

    
    
    
//---------------------------------------------------------
#if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
    if(iOS_MSAA_IS_ON)
    {
        glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);//-------------------- MSAA SWITCH --- iOS      ON
    }
    else
    {
        glBindFramebuffer(GL_FRAMEBUFFER, viewRenderbuffer);//------------------- MSAA SWITCH --- iOS      OFF
    }
#endif 
//---------------------------------------------------------
#if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
    //PROCESS_TOUCH
    
    //-------------------------
#elif TARGET_OS_MAC == 1 || WIN32 == 1
    glEnable(GL_MULTISAMPLE_ARB);//---------------------------------------------- MSAA SWITCH --- WIN-OSX -ON

#endif
//----------------------
    
    glEnable(GL_MULTISAMPLE_ARB);//---------------------------------------------- MSAA SWITCH --- WIN-OSX -ON
   
    
    
    //=====================//#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_
renderMainColor_PASS();
    //=====================//#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_

    
    
    
//----------------------
#if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
    //PROCESS_TOUCH
    
    //-------------------------
#elif TARGET_OS_MAC == 1 || WIN32 == 1
    glDisable(GL_MULTISAMPLE_ARB);//--------------------------------------------- MSAA SWITCH --- WIN-OSX -OFF
#endif
//--------------------------------------------------------
    
    
    
    finalComposite();
    //---------------


 
   

    //groupSceneLight_RADIAN[0] += groupSceneLight_VELOCITY[0];
    //groupSceneLight_RADIAN[1] += groupSceneLight_VELOCITY[1];
    if(groupSceneLight_RADIAN[0] >= 0.944 || groupSceneLight_RADIAN[0] <= -0.944)
    {
        groupSceneLight_VELOCITY[0] *= -1.0;
    }

    
    f_1_snowLighting += 0.101142;
    
    
//==================================
frameEnd  = getMilliSpan(start);
frameTime = frameEnd - frameStart;

if(CONSOLE_OUTPUT)
{
    #ifdef __APPLE__
    //NSLog(@"==============");
    //NSLog(@"frameTime = %i milliseconds", (int)frameTime);
    //NSLog(@"==============");
    #endif
}    

    
}//_END_RenderGL()//#####################################################################################################


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================













//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================


