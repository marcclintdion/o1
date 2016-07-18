#include    "copperCorrode_B_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
copperCorrode_B_SHADER = glCreateProgram();



//-------------------------

//===============
#if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"copperCorrode_B" ofType:@"vert"];
vertexSource_copperCorrode_B   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"copperCorrode_B" ofType:@"frag"];
fragmentSource_copperCorrode_B = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 ||  WIN32 == 1
vertexSource_copperCorrode_B   = readShaderFile( "_SHADERS/copperCorrode_B/copperCorrode_B.vert" );
fragmentSource_copperCorrode_B = readShaderFile( "_SHADERS/copperCorrode_B/copperCorrode_B.frag" );
#endif
//===============


    //=======================================================================================================================
    copperCorrode_B_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( copperCorrode_B_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_copperCorrode_B, NULL );
    glCompileShader( copperCorrode_B_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    copperCorrode_B_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( copperCorrode_B_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_copperCorrode_B, NULL );
    glCompileShader(copperCorrode_B_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( copperCorrode_B_SHADER, copperCorrode_B_SHADER_VERTEX );
    glAttachShader( copperCorrode_B_SHADER, copperCorrode_B_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(copperCorrode_B_SHADER,   0, "position");
    glBindAttribLocation(copperCorrode_B_SHADER,   1, "normal");
    glBindAttribLocation(copperCorrode_B_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( copperCorrode_B_SHADER_VERTEX);
    glDeleteShader( copperCorrode_B_SHADER_FRAGMENT);
    glLinkProgram(  copperCorrode_B_SHADER);
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_copperCorrode_B                   = glGetUniformLocation(copperCorrode_B_SHADER, "projectionMatrix");
    UNIFORM_MODELVIEW_MATRIX_copperCorrode_B                    = glGetUniformLocation(copperCorrode_B_SHADER, "modelViewMatrix");
    UNIFORM_invertModelViewMatrix_copperCorrode_B               = glGetUniformLocation(copperCorrode_B_SHADER, "invertModelViewMatrix");
    UNIFORM_invertViewMatrix_copperCorrode_B                    = glGetUniformLocation(copperCorrode_B_SHADER, "invertViewMatrix");
    UNIFORM_invertModelMatrix_copperCorrode_B                   = glGetUniformLocation(copperCorrode_B_SHADER, "invertModelMatrix");

    UNIFORM_ShadowMapMatrix_copperCorrode_B                     = glGetUniformLocation(copperCorrode_B_SHADER, "shadowMapMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POS_copperCorrode_B                          = glGetUniformLocation(copperCorrode_B_SHADER, "light0_POS");
    UNIFORM_LIGHT1_POS_copperCorrode_B                          = glGetUniformLocation(copperCorrode_B_SHADER, "light1_POS");
    //==================================
    UNIFORM_shadowBias_UMBRA_copperCorrode_B                    = glGetUniformLocation(copperCorrode_B_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_copperCorrode_B                 = glGetUniformLocation(copperCorrode_B_SHADER, "shadowBias_PENUMBRA");


    UNIFORM_animateAniso_AO_mask_copperCorrode_B                = glGetUniformLocation(copperCorrode_B_SHADER, "animateAniso_AO_mask");

    UNIFORM_f_0_copperCorrode_B                                 = glGetUniformLocation(copperCorrode_B_SHADER, "f_0");
    UNIFORM_f_1_copperCorrode_B                                 = glGetUniformLocation(copperCorrode_B_SHADER, "f_1");
    UNIFORM_f_2_copperCorrode_B                                 = glGetUniformLocation(copperCorrode_B_SHADER, "f_2");
    UNIFORM_f_3_copperCorrode_B                                 = glGetUniformLocation(copperCorrode_B_SHADER, "f_3");
    UNIFORM_f_4_copperCorrode_B                                 = glGetUniformLocation(copperCorrode_B_SHADER, "f_4");
    UNIFORM_f_5_copperCorrode_B                                 = glGetUniformLocation(copperCorrode_B_SHADER, "f_5");

    //--------------------------------
    UNIFORM_EMIT_copperCorrode_B                                = glGetUniformLocation(copperCorrode_B_SHADER, "ColorMAP");
    UNIFORM_DOT3_copperCorrode_B                                = glGetUniformLocation(copperCorrode_B_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_copperCorrode_B                    = glGetUniformLocation(copperCorrode_B_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_copperCorrode_B                             = glGetUniformLocation(copperCorrode_B_SHADER, "EnvMap");
    UNIFORM_MASK0_copperCorrode_B                               = glGetUniformLocation(copperCorrode_B_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_copperCorrode_B                 = glGetUniformLocation(copperCorrode_B_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_copperCorrode_B                   = glGetUniformLocation(copperCorrode_B_SHADER, "caustics_WATERMAP");

//######################################################












