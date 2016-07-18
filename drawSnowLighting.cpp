//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    //=======================================================================================================================
    glClearColor( 0.7f, 0.9f, 1.0f, 1.0 );
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

shaderNumber = 28;

