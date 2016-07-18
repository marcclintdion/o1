#include    "cactopi_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=

cactopi_SHADER = glCreateProgram();
//---------------------------------

//===============
#if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"cactopi" ofType:@"vert"];
vertexSource_cactopi   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"cactopi" ofType:@"frag"];
fragmentSource_cactopi = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 ||  WIN32 == 1
vertexSource_cactopi   = readShaderFile( "_SHADERS/cactopi/cactopi.vert" );
fragmentSource_cactopi = readShaderFile( "_SHADERS/cactopi/cactopi.frag" );
#endif
//===============


    //=======================================================================================================================
    cactopi_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( cactopi_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_cactopi, NULL );
    glCompileShader( cactopi_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    cactopi_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( cactopi_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_cactopi, NULL );
    glCompileShader(cactopi_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( cactopi_SHADER, cactopi_SHADER_VERTEX );
    glAttachShader( cactopi_SHADER, cactopi_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(cactopi_SHADER,   0, "position");
    glBindAttribLocation(cactopi_SHADER,   1, "normal");
    glBindAttribLocation(cactopi_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( cactopi_SHADER_VERTEX);
    glDeleteShader( cactopi_SHADER_FRAGMENT);
    glLinkProgram(  cactopi_SHADER);
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_cactopi                   = glGetUniformLocation(cactopi_SHADER, "projectionMatrix");
    UNIFORM_MODELVIEW_MATRIX_cactopi                    = glGetUniformLocation(cactopi_SHADER, "modelViewMatrix");
    UNIFORM_invertModelViewMatrix_cactopi               = glGetUniformLocation(cactopi_SHADER, "invertModelViewMatrix");
    UNIFORM_invertViewMatrix_cactopi                    = glGetUniformLocation(cactopi_SHADER, "invertViewMatrix_L0");
    UNIFORM_invertModelMatrix_cactopi                   = glGetUniformLocation(cactopi_SHADER, "invertModelMatrix_L1");

    UNIFORM_ShadowMapMatrix_cactopi                     = glGetUniformLocation(cactopi_SHADER, "shadowMapMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POS_cactopi                          = glGetUniformLocation(cactopi_SHADER, "light0_POS");
    UNIFORM_LIGHT1_POS_cactopi                          = glGetUniformLocation(cactopi_SHADER, "light1_POS");
    //==================================
    UNIFORM_shadowBias_UMBRA_cactopi                    = glGetUniformLocation(cactopi_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_cactopi                 = glGetUniformLocation(cactopi_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_f_0_cactopi                                 = glGetUniformLocation(cactopi_SHADER, "f_0");
    UNIFORM_f_1_cactopi                                 = glGetUniformLocation(cactopi_SHADER, "f_1");
    UNIFORM_f_2_cactopi                                 = glGetUniformLocation(cactopi_SHADER, "f_2");
    UNIFORM_f_3_cactopi                                 = glGetUniformLocation(cactopi_SHADER, "f_3");

    //--------------------------------
    UNIFORM_EMIT_cactopi                                = glGetUniformLocation(cactopi_SHADER, "ColorMAP");
    UNIFORM_DOT3_cactopi                                = glGetUniformLocation(cactopi_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_cactopi                    = glGetUniformLocation(cactopi_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_cactopi                             = glGetUniformLocation(cactopi_SHADER, "EnvMap");
    UNIFORM_MASK0_cactopi                               = glGetUniformLocation(cactopi_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_cactopi                 = glGetUniformLocation(cactopi_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_cactopi                   = glGetUniformLocation(cactopi_SHADER, "caustics_WATERMAP");
//######################################################









