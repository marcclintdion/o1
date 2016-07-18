#include    "pearlPaint_A_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
pearlPaint_A_SHADER = glCreateProgram();
//--------------------------------------

//===============
#if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"pearlPaint_A" ofType:@"vert"];
vertexSource_pearlPaint_A   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"pearlPaint_A" ofType:@"frag"];
fragmentSource_pearlPaint_A = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 || WIN32 == 1
vertexSource_pearlPaint_A   = readShaderFile( "_SHADERS/pearlPaint_A/pearlPaint_A.vert" );
fragmentSource_pearlPaint_A = readShaderFile( "_SHADERS/pearlPaint_A/pearlPaint_A.frag" );
#endif
//===============


    //=======================================================================================================================
    pearlPaint_A_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( pearlPaint_A_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_pearlPaint_A, NULL );
    glCompileShader( pearlPaint_A_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    pearlPaint_A_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( pearlPaint_A_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_pearlPaint_A, NULL );
    glCompileShader(pearlPaint_A_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( pearlPaint_A_SHADER, pearlPaint_A_SHADER_VERTEX );
    glAttachShader( pearlPaint_A_SHADER, pearlPaint_A_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(pearlPaint_A_SHADER,   0, "position");
    glBindAttribLocation(pearlPaint_A_SHADER,   1, "normal");
    glBindAttribLocation(pearlPaint_A_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( pearlPaint_A_SHADER_VERTEX);
    glDeleteShader( pearlPaint_A_SHADER_FRAGMENT);
    glLinkProgram(  pearlPaint_A_SHADER);
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_pearlPaint_A                     = glGetUniformLocation(pearlPaint_A_SHADER, "projectionMatrix");
    UNIFORM_MODELVIEW_MATRIX_pearlPaint_A                      = glGetUniformLocation(pearlPaint_A_SHADER, "modelViewMatrix");
    UNIFORM_VIEW_MATRIX_pearlPaint_A                           = glGetUniformLocation(pearlPaint_A_SHADER, "viewMatrix");

    UNIFORM_MODEL_MATRIX_pearlPaint_A                          = glGetUniformLocation(pearlPaint_A_SHADER, "modelMatrix");


    UNIFORM_invertModelViewMatrix_pearlPaint_A                 = glGetUniformLocation(pearlPaint_A_SHADER, "invertModelViewMatrix");
    UNIFORM_invertViewMatrix_pearlPaint_A                      = glGetUniformLocation(pearlPaint_A_SHADER, "invertViewMatrix_L0");
    UNIFORM_invertModelMatrix_pearlPaint_A                     = glGetUniformLocation(pearlPaint_A_SHADER, "invertModelMatrix_L1");

    UNIFORM_ShadowMapMatrix_pearlPaint_A                       = glGetUniformLocation(pearlPaint_A_SHADER, "shadowMapMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POSITION_pearlPaint_A                       = glGetUniformLocation(pearlPaint_A_SHADER, "light0_POSITION");
    UNIFORM_LIGHT1_POSITION_pearlPaint_A                       = glGetUniformLocation(pearlPaint_A_SHADER, "light1_POSITION");
    //==================================
    UNIFORM_shadowBias_UMBRA_pearlPaint_A                      = glGetUniformLocation(pearlPaint_A_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_pearlPaint_A                   = glGetUniformLocation(pearlPaint_A_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_f_0_pearlPaint_A                                   = glGetUniformLocation(pearlPaint_A_SHADER, "f_0");
    UNIFORM_f_1_pearlPaint_A                                   = glGetUniformLocation(pearlPaint_A_SHADER, "f_1");
    UNIFORM_f_2_pearlPaint_A                                   = glGetUniformLocation(pearlPaint_A_SHADER, "f_2");
    UNIFORM_f_3_pearlPaint_A                                   = glGetUniformLocation(pearlPaint_A_SHADER, "f_3");
    UNIFORM_f_4_pearlPaint_A                                   = glGetUniformLocation(pearlPaint_A_SHADER, "f_4");
    UNIFORM_f_5_pearlPaint_A                                   = glGetUniformLocation(pearlPaint_A_SHADER, "f_5");

    UNIFORM_timeIncrement_pearlPaint_A                         = glGetUniformLocation(pearlPaint_A_SHADER, "timeIncrement");

    //--------------------------------
    UNIFORM_EMIT_pearlPaint_A                                  = glGetUniformLocation(pearlPaint_A_SHADER, "ColorMAP");
    UNIFORM_DOT3_pearlPaint_A                                  = glGetUniformLocation(pearlPaint_A_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_pearlPaint_A                      = glGetUniformLocation(pearlPaint_A_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_pearlPaint_A                               = glGetUniformLocation(pearlPaint_A_SHADER, "EnvMap");
    UNIFORM_MASK0_pearlPaint_A                                 = glGetUniformLocation(pearlPaint_A_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_pearlPaint_A                   = glGetUniformLocation(pearlPaint_A_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_pearlPaint_A                     = glGetUniformLocation(pearlPaint_A_SHADER, "caustics_WATERMAP");
//######################################################


glActiveTexture (GL_TEXTURE5);
glBindTexture(GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);










