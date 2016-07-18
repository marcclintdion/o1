//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//=======================================================================================================================
glClearColor( 0.1f, 0.1f, 0.1f, 1.0 );
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






#include "_MODEL_FOLDERS_/effectsPlane_B/effectsPlane_B_RENDER.cpp"
#include "_MODEL_FOLDERS_/effectsPlane_A/effectsPlane_A_RENDER.cpp"

