
#include    "bigLeaf_A_VINES_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
bigLeaf_A_VINES_SHADER = glCreateProgram();


//===============
#if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"bigLeaf_A_VINES" ofType:@"vert"];
vertexSource_bigLeaf_A_VINES   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"bigLeaf_A_VINES" ofType:@"frag"];
fragmentSource_bigLeaf_A_VINES = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 || WIN32 == 1
vertexSource_bigLeaf_A_VINES   = readShaderFile( "_SHADERS/bigLeaf_A_VINES/bigLeaf_A_VINES.vert" );
fragmentSource_bigLeaf_A_VINES = readShaderFile( "_SHADERS/bigLeaf_A_VINES/bigLeaf_A_VINES.frag" );
#endif
//===============


    //=======================================================================================================================
    bigLeaf_A_VINES_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( bigLeaf_A_VINES_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_bigLeaf_A_VINES, NULL );
    glCompileShader( bigLeaf_A_VINES_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    bigLeaf_A_VINES_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( bigLeaf_A_VINES_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_bigLeaf_A_VINES, NULL );
    glCompileShader(bigLeaf_A_VINES_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( bigLeaf_A_VINES_SHADER, bigLeaf_A_VINES_SHADER_VERTEX );
    glAttachShader( bigLeaf_A_VINES_SHADER, bigLeaf_A_VINES_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(bigLeaf_A_VINES_SHADER,   0, "position");
    glBindAttribLocation(bigLeaf_A_VINES_SHADER,   1, "normal");
    glBindAttribLocation(bigLeaf_A_VINES_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( bigLeaf_A_VINES_SHADER_VERTEX);
    glDeleteShader( bigLeaf_A_VINES_SHADER_FRAGMENT);
    glLinkProgram(bigLeaf_A_VINES_SHADER);                                                                                      
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_bigLeaf_A_VINES               = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "projectionMatrix");
    UNIFORM_invertViewMatrix_bigLeaf_A_VINES                = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "invertViewMatrix_L0");
    UNIFORM_invertModelMatrix_bigLeaf_A_VINES               = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "invertModelMatrix_L1");

    UNIFORM_ShadowMapMatrix_bigLeaf_A_VINES                 = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "shadowMapMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POS_bigLeaf_A_VINES                      = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "light0_POS");
    UNIFORM_LIGHT1_POS_bigLeaf_A_VINES                      = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "light1_POS");
    //==================================
    UNIFORM_shadowBias_UMBRA_bigLeaf_A_VINES                = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_bigLeaf_A_VINES             = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_f_0_bigLeaf_A_VINES                             = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "f_0");
    UNIFORM_f_1_bigLeaf_A_VINES                             = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "f_1");
    //--------------------------------
    UNIFORM_EMIT_bigLeaf_A_VINES                            = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "ColorMAP");
    UNIFORM_DOT3_bigLeaf_A_VINES                            = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_bigLeaf_A_VINES                = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_bigLeaf_A_VINES                         = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "CubeMAP");
    UNIFORM_MASK0_bigLeaf_A_VINES                           = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_bigLeaf_A_VINES             = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_bigLeaf_A_VINES               = glGetUniformLocation(bigLeaf_A_VINES_SHADER, "caustics_WATERMAP");









