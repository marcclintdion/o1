
#include    "marbleReflection_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
marbleReflection_SHADER = glCreateProgram();


//===============
#if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"marbleReflection" ofType:@"vert"];
vertexSource_marbleReflection   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"marbleReflection" ofType:@"frag"];
fragmentSource_marbleReflection = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 || WIN32 == 1
vertexSource_marbleReflection   = readShaderFile( "_SHADERS/marbleReflection/marbleReflection.vert" );
fragmentSource_marbleReflection = readShaderFile( "_SHADERS/marbleReflection/marbleReflection.frag" );
#endif
//===============


    //=======================================================================================================================
    marbleReflection_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( marbleReflection_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_marbleReflection, NULL );
    glCompileShader( marbleReflection_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    marbleReflection_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( marbleReflection_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_marbleReflection, NULL );
    glCompileShader(marbleReflection_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( marbleReflection_SHADER, marbleReflection_SHADER_VERTEX );
    glAttachShader( marbleReflection_SHADER, marbleReflection_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(marbleReflection_SHADER,   0, "position");
    glBindAttribLocation(marbleReflection_SHADER,   1, "normal");
    glBindAttribLocation(marbleReflection_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( marbleReflection_SHADER_VERTEX);
    glDeleteShader( marbleReflection_SHADER_FRAGMENT);
    glLinkProgram(marbleReflection_SHADER);                                                                                      
    //--------------------------------------------------------------------------------------------------
    UNIFORM_TEXTURE_SPACE_MATRIX_marbleReflection               = glGetUniformLocation(marbleReflection_SHADER, "textureSpaceMatrix");
    UNIFORM_PROJECTION_MATRIX_marbleReflection                  = glGetUniformLocation(marbleReflection_SHADER, "projectionMatrix");
    UNIFORM_invertModelMatrix_marbleReflection                  = glGetUniformLocation(marbleReflection_SHADER, "invertModelMatrix");
    UNIFORM_invertModelViewMatrix_marbleReflection              = glGetUniformLocation(marbleReflection_SHADER, "invertModelViewMatrix");
    UNIFORM_invertViewMatrix_marbleReflection                   = glGetUniformLocation(marbleReflection_SHADER, "invertViewMatrix");
    UNIFORM_modelViewMatrix_marbleReflection                    = glGetUniformLocation(marbleReflection_SHADER, "modelViewMatrix");

    UNIFORM_ShadowMapMatrix_marbleReflection                    = glGetUniformLocation(marbleReflection_SHADER, "shadowMapMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POSITION_marbleReflection                    = glGetUniformLocation(marbleReflection_SHADER, "light0_POS");
    UNIFORM_movingGlossyLight_POSITION_marbleReflection         = glGetUniformLocation(marbleReflection_SHADER, "light1_POS");
    //==================================
    UNIFORM_shadowBias_UMBRA_marbleReflection                   = glGetUniformLocation(marbleReflection_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_marbleReflection                = glGetUniformLocation(marbleReflection_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_f_0_marbleReflection                                = glGetUniformLocation(marbleReflection_SHADER, "f_0");
    UNIFORM_f_1_marbleReflection                                = glGetUniformLocation(marbleReflection_SHADER, "f_1");
    UNIFORM_f_2_marbleReflection                                = glGetUniformLocation(marbleReflection_SHADER, "f_2");
    UNIFORM_f_3_marbleReflection                                = glGetUniformLocation(marbleReflection_SHADER, "f_3");
    UNIFORM_f_4_marbleReflection                                = glGetUniformLocation(marbleReflection_SHADER, "f_4");


    //--------------------------------
    UNIFORM_EMIT_marbleReflection                               = glGetUniformLocation(marbleReflection_SHADER, "ColorMAP");
    UNIFORM_DOT3_marbleReflection                               = glGetUniformLocation(marbleReflection_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_marbleReflection                   = glGetUniformLocation(marbleReflection_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_REFLECTION_marbleReflection                         = glGetUniformLocation(marbleReflection_SHADER, "ReflectionMAP");
    UNIFORM_MASK0_marbleReflection                              = glGetUniformLocation(marbleReflection_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_marbleReflection                = glGetUniformLocation(marbleReflection_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_marbleReflection                  = glGetUniformLocation(marbleReflection_SHADER, "caustics_WATERMAP");










