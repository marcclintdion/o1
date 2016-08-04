//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    //=======================================================================================================================
    //glClearColor( 247.0/255.0f, 247.0/255.0f, 247.0/255.0f, 1.0 );
    glClearColor( .0f, .0f, .0f, 1.0 );
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // GL_STENCIL_BUFFER_BIT
//------------------------------------------------------------------------------
    


    glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
    LoadIdentity(projectionMatrix);
    PerspectiveMatrix(projectionMatrix, fieldOfView, (GLfloat)viewWidth / (GLfloat)viewHeight, nearFarPlane_CAMERA[0],  nearFarPlane_CAMERA[1]);
    #if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
    //Rotate(projectionMatrix, 0.0, 0.0, 1.0, -90.0);
    #endif
    //----

//==============
View_TRANSFORM();
//==============





shaderNumber = 25;



shaderNumber = 19;//mixedGlazedVelvet
glEnable(GL_BLEND);
glCullFace(GL_NONE);
glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE_ARB);
glEnable(GL_ALPHA_TEST);
glAlphaFunc(GL_GEQUAL, 0.25f);
#include "_MODEL_FOLDERS_/o1/o1_RENDER.cpp"


shaderNumber = 21;//copperCorrode_B

shaderNumber = 18;//copperCorrode


//=========================================================================
shaderNumber = 20;


shaderNumber = 19;//mixedGlazedVelvet
    //#include "_MODEL_FOLDERS_/leaves_j14_1/leaves_j14_1_RENDER.cpp"  //REPLACE_WITH_CLOUDS


shaderNumber = 23;//bigLeaf_A_VINES


//================================================================================================================


//================================================================================================================


//================================================================================================================
shaderNumber = 20;

//================================================================================================================

shaderNumber = 19;
//glDisable(GL_CULL_FACE);


//glEnable(GL_CULL_FACE);




shaderNumber = 19;
glEnable(GL_BLEND);
glDisable(GL_CULL_FACE);


shaderNumber = 29;

glDisable(GL_BLEND);
glEnable(GL_CULL_FACE);

      

