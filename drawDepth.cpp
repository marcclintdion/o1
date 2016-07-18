//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//=======================================================================================================================
glClearColor( 0.6f, 1.0f, 1.0f, 1.0 );
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//----------------------------------------------------------------------------


//--
glViewport(1, 1, (((GLsizei)viewWidth * shadow_SIZE_MULTIPLIER)/shadow_SIZE_DIVISOR)-2,
                 (((GLsizei)viewWidth * shadow_SIZE_MULTIPLIER)/shadow_SIZE_DIVISOR)-2);
LoadIdentity(projectionMatrix);
PerspectiveMatrix(projectionMatrix, fieldOfView + fieldOfView_SHADOW, (GLfloat)viewWidth / (GLfloat)viewHeight, nearFarPlane_CAMERA[0],  nearFarPlane_CAMERA[1]);
#if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
//Rotate(projectionMatrix, 0.0, 0.0, 1.0, -90.0);
#endif
//----

//==============
View_TRANSFORM();
//==============


//=========================================================================

shaderNumber = 11;
//----------

    #include "_MODEL_FOLDERS_/o1/o1_RENDER.cpp"  

