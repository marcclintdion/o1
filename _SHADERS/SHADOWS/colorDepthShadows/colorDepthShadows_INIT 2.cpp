

colorDepthShadows_SHADER = glCreateProgram();

vertexSource_colorDepthShadows        = readShaderFile("_SHADERS/SHADOWS/colorDepthShadows/colorDepthShadows.vert");
fragmentSource_colorDepthShadows      = readShaderFile("_SHADERS/SHADOWS/colorDepthShadows/colorDepthShadows.frag");


//=======================================================================================================================
colorDepthShadows_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
glShaderSource( colorDepthShadows_SHADER_VERTEX, 1,   (const GLchar **)&vertexSource_colorDepthShadows, NULL );
glCompileShader( colorDepthShadows_SHADER_VERTEX);                                              //glShaderBinary
//----------------------------------------------------
colorDepthShadows_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
glShaderSource( colorDepthShadows_SHADER_FRAGMENT, 1, (const GLchar **)&fragmentSource_colorDepthShadows, NULL );
glCompileShader(colorDepthShadows_SHADER_FRAGMENT);                                              //glShaderBinary
//--------------------------------------------------------------------------------------------------
glAttachShader( colorDepthShadows_SHADER, colorDepthShadows_SHADER_VERTEX );
glAttachShader( colorDepthShadows_SHADER, colorDepthShadows_SHADER_FRAGMENT );
//--------------------------------------------------------------------------------------------------
glBindAttribLocation(colorDepthShadows_SHADER,   0, "position");
glBindAttribLocation(colorDepthShadows_SHADER,   1, "normal");
glBindAttribLocation(colorDepthShadows_SHADER,   2, "uv0");
//--------------------------------------------------------------------------------------------------
glDeleteShader( colorDepthShadows_SHADER_VERTEX);
glDeleteShader( colorDepthShadows_SHADER_FRAGMENT);
glLinkProgram(colorDepthShadows_SHADER);
//--------------------------------------------------------------------------------------------------

UNIFORM_PROJECTION_MATRIX_colorDepthShadows                           = glGetUniformLocation(colorDepthShadows_SHADER, "projectionMatrix");
UNIFORM_invertViewMatrix_colorDepthShadows                            = glGetUniformLocation(colorDepthShadows_SHADER, "invertViewMatrix");
UNIFORM_invertModelMatrix_colorDepthShadows                           = glGetUniformLocation(colorDepthShadows_SHADER, "invertModelMatrix");
//-------------------------------
UNIFORM_LIGHT0_POS_colorDepthShadows                                  = glGetUniformLocation(colorDepthShadows_SHADER, "light0_POS");
UNIFORM_movingGlossyLight_POS_colorDepthShadows                       = glGetUniformLocation(colorDepthShadows_SHADER, "light1_POS");
//==================================
UNIFORM_f_0_colorDepthShadows                                         = glGetUniformLocation(colorDepthShadows_SHADER, "f_0");
UNIFORM_f_1_colorDepthShadows                                         = glGetUniformLocation(colorDepthShadows_SHADER, "f_1");

UNIFORM_noiseScale_colorDepthShadows                                  = glGetUniformLocation(colorDepthShadows_SHADER, "noiseScale");

//--------------------------------
UNIFORM_TEX_COLOR_colorDepthShadows                                   = glGetUniformLocation(colorDepthShadows_SHADER, "ColorMAP");
UNIFORM_TEX_DOT3_colorDepthShadows                                    = glGetUniformLocation(colorDepthShadows_SHADER, "NormalMAP");
//shadow
UNIFORM_TEX_MASK0_colorDepthShadows                                   = glGetUniformLocation(colorDepthShadows_SHADER, "Mask0MAP");

//######################################################


//#include "settings.cpp"  This should be parsed as a text file so it won't override current settings with startup settings that are pre-compiled and in loaded here











