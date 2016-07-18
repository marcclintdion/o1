
#include    "domeTreeBranchTexture_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
domeTreeBranchTexture_SHADER = glCreateProgram();


//===============
#ifdef  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"domeTreeBranchTexture" ofType:@"vert"];
vertexSource_domeTreeBranchTexture_SHADER   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"domeTreeBranchTexture" ofType:@"frag"];
fragmentSource_domeTreeBranchTexture_SHADER = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 || WIN32 == 1
vertexSource_domeTreeBranchTexture_SHADER   = readShaderFile( "_SHADERS/domeTreeBranchTexture/domeTreeBranchTexture.vert" );
fragmentSource_domeTreeBranchTexture_SHADER = readShaderFile( "_SHADERS/domeTreeBranchTexture/domeTreeBranchTexture.frag" );
#endif
//===============
    //=======================================================================================================================
    domeTreeBranchTexture_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( domeTreeBranchTexture_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_domeTreeBranchTexture_SHADER, NULL );
    glCompileShader( domeTreeBranchTexture_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    domeTreeBranchTexture_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( domeTreeBranchTexture_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_domeTreeBranchTexture_SHADER, NULL );
    glCompileShader(domeTreeBranchTexture_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( domeTreeBranchTexture_SHADER, domeTreeBranchTexture_SHADER_VERTEX );
    glAttachShader( domeTreeBranchTexture_SHADER, domeTreeBranchTexture_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(domeTreeBranchTexture_SHADER,   0, "position");
    glBindAttribLocation(domeTreeBranchTexture_SHADER,   1, "normal");
    glBindAttribLocation(domeTreeBranchTexture_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( domeTreeBranchTexture_SHADER_VERTEX);
    glDeleteShader( domeTreeBranchTexture_SHADER_FRAGMENT);
    glLinkProgram(domeTreeBranchTexture_SHADER);
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_domeTreeBranchTexture_SHADER             = glGetUniformLocation(domeTreeBranchTexture_SHADER, "projectionMatrix");
    UNIFORM_invertModelMatrix_domeTreeBranchTexture_SHADER             = glGetUniformLocation(domeTreeBranchTexture_SHADER, "invertModelMatrix");
    UNIFORM_invertViewMatrix_domeTreeBranchTexture_SHADER              = glGetUniformLocation(domeTreeBranchTexture_SHADER, "invertViewMatrix");
    UNIFORM_invertModelViewMatrix_domeTreeBranchTexture_SHADER         = glGetUniformLocation(domeTreeBranchTexture_SHADER, "invertModelViewMatrix");

    UNIFORM_ShadowMapMatrix_domeTreeBranchTexture_SHADER               = glGetUniformLocation(domeTreeBranchTexture_SHADER, "shadowMapMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POS_domeTreeBranchTexture_SHADER                    = glGetUniformLocation(domeTreeBranchTexture_SHADER, "light0_POS");
    UNIFORM_LIGHT1_POS_domeTreeBranchTexture_SHADER                    = glGetUniformLocation(domeTreeBranchTexture_SHADER, "light1_POS");
    //------
    UNIFORM_position_MODEL_domeTreeBranchTexture_SHADER                = glGetUniformLocation(domeTreeBranchTexture_SHADER, "position_MODEL");
    //------
    UNIFORM_shadowBias_UMBRA_domeTreeBranchTexture_SHADER              = glGetUniformLocation(domeTreeBranchTexture_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_domeTreeBranchTexture_SHADER           = glGetUniformLocation(domeTreeBranchTexture_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_adjusted_UV_IN_domeTreeBranchTexture_SHADER                = glGetUniformLocation(domeTreeBranchTexture_SHADER, "adjusted_UV_IN");

    UNIFORM_f_0_domeTreeBranchTexture_SHADER                           = glGetUniformLocation(domeTreeBranchTexture_SHADER, "f_0");
    UNIFORM_f_1_domeTreeBranchTexture_SHADER                           = glGetUniformLocation(domeTreeBranchTexture_SHADER, "f_1");
    UNIFORM_f_2_domeTreeBranchTexture_SHADER                           = glGetUniformLocation(domeTreeBranchTexture_SHADER, "f_2");
    UNIFORM_f_3_domeTreeBranchTexture_SHADER                           = glGetUniformLocation(domeTreeBranchTexture_SHADER, "f_3");
    UNIFORM_f_4_domeTreeBranchTexture_SHADER                           = glGetUniformLocation(domeTreeBranchTexture_SHADER, "f_4");

    //--------------------------------
    UNIFORM_EMIT_domeTreeBranchTexture_SHADER                          = glGetUniformLocation(domeTreeBranchTexture_SHADER, "ColorMAP");
    UNIFORM_DOT3_domeTreeBranchTexture_SHADER                          = glGetUniformLocation(domeTreeBranchTexture_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_domeTreeBranchTexture_SHADER              = glGetUniformLocation(domeTreeBranchTexture_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_domeTreeBranchTexture_SHADER                       = glGetUniformLocation(domeTreeBranchTexture_SHADER, "CubeMAP");
    UNIFORM_MASK0_domeTreeBranchTexture_SHADER                         = glGetUniformLocation(domeTreeBranchTexture_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_domeTreeBranchTexture_SHADER           = glGetUniformLocation(domeTreeBranchTexture_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_domeTreeBranchTexture_SHADER             = glGetUniformLocation(domeTreeBranchTexture_SHADER, "caustics_WATERMAP");
//######################################################











