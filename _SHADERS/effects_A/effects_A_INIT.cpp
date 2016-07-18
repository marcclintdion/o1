#include    "effects_A_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
effects_A_SHADER = glCreateProgram();




    //=======================================================================================================================
    #if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
        filePathName = [[NSBundle mainBundle] pathForResource:@"effects_A" ofType:@"vert"];
        vertexSource_effects_A   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
        filePathName = [[NSBundle mainBundle] pathForResource:@"effects_A" ofType:@"frag"];
        fragmentSource_effects_A = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
        //----------------------
        #elif TARGET_OS_MAC == 1 || WIN32 == 1
        vertexSource_effects_A   = readShaderFile( "_SHADERS/effects_A/effects_A.vert" );
        fragmentSource_effects_A = readShaderFile( "_SHADERS/effects_A/effects_A.frag" );
    #endif



    //=======================================================================================================================
    effects_A_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( effects_A_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_effects_A, NULL );
    glCompileShader( effects_A_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    effects_A_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( effects_A_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_effects_A, NULL );
    glCompileShader(effects_A_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( effects_A_SHADER, effects_A_SHADER_VERTEX );
    glAttachShader( effects_A_SHADER, effects_A_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(effects_A_SHADER,   0, "position");
    glBindAttribLocation(effects_A_SHADER,   1, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( effects_A_SHADER_VERTEX);
    glDeleteShader( effects_A_SHADER_FRAGMENT);
    glLinkProgram(  effects_A_SHADER);
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_effects_A                     = glGetUniformLocation(effects_A_SHADER, "projectionMatrix");
    UNIFORM_MODELVIEW_MATRIX_effects_A                      = glGetUniformLocation(effects_A_SHADER, "modelViewMatrix");
    UNIFORM_VIEW_MATRIX_effects_A                           = glGetUniformLocation(effects_A_SHADER, "viewMatrix");

    UNIFORM_MODEL_MATRIX_effects_A                          = glGetUniformLocation(effects_A_SHADER, "modelMatrix");


    UNIFORM_invertModelViewMatrix_effects_A                 = glGetUniformLocation(effects_A_SHADER, "invertModelViewMatrix");
    UNIFORM_invertViewMatrix_effects_A                      = glGetUniformLocation(effects_A_SHADER, "invertViewMatrix_L0");
    UNIFORM_invertModelMatrix_effects_A                     = glGetUniformLocation(effects_A_SHADER, "invertModelMatrix_L1");

    UNIFORM_ShadowMapMatrix_effects_A                       = glGetUniformLocation(effects_A_SHADER, "shadowMapMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POSITION_effects_A                       = glGetUniformLocation(effects_A_SHADER, "light0_POSITION");
    UNIFORM_LIGHT1_POSITION_effects_A                       = glGetUniformLocation(effects_A_SHADER, "light1_POSITION");
    //==================================
    UNIFORM_shadowBias_UMBRA_effects_A                      = glGetUniformLocation(effects_A_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_effects_A                   = glGetUniformLocation(effects_A_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_screenRatio_effects_A                           = glGetUniformLocation(effects_A_SHADER, "screenRatio");
    UNIFORM_timeIncrement_effects_A                         = glGetUniformLocation(effects_A_SHADER, "timeIncrement");
    UNIFORM_phaseShiftIncrement_effects_A                   = glGetUniformLocation(effects_A_SHADER, "phaseShiftIncrement");

    UNIFORM_f_0_effects_A                                   = glGetUniformLocation(effects_A_SHADER, "f_0");
    UNIFORM_f_1_effects_A                                   = glGetUniformLocation(effects_A_SHADER, "f_1");
    UNIFORM_f_2_effects_A                                   = glGetUniformLocation(effects_A_SHADER, "f_2");
    UNIFORM_f_3_effects_A                                   = glGetUniformLocation(effects_A_SHADER, "f_3");
    UNIFORM_f_4_effects_A                                   = glGetUniformLocation(effects_A_SHADER, "f_4");
    UNIFORM_f_5_effects_A                                   = glGetUniformLocation(effects_A_SHADER, "f_5");



    UNIFORM_waves_A_POSITION                                = glGetUniformLocation(effects_A_SHADER, "waves_A_POSITION");
    UNIFORM_waves_B_POSITION                                = glGetUniformLocation(effects_A_SHADER, "waves_B_POSITION");
    UNIFORM_waves_C_POSITION                                = glGetUniformLocation(effects_A_SHADER, "waves_C_POSITION");
    UNIFORM_waves_D_POSITION                                = glGetUniformLocation(effects_A_SHADER, "waves_D_POSITION");

    UNIFORM_waves_A_SCALE                                   = glGetUniformLocation(effects_A_SHADER, "waves_A_SCALE");
    UNIFORM_waves_B_SCALE                                   = glGetUniformLocation(effects_A_SHADER, "waves_B_SCALE");
    UNIFORM_waves_C_SCALE                                   = glGetUniformLocation(effects_A_SHADER, "waves_C_SCALE");
    UNIFORM_waves_D_SCALE                                   = glGetUniformLocation(effects_A_SHADER, "waves_D_SCALE");
    //--------------------------------
    UNIFORM_EMIT_effects_A                                  = glGetUniformLocation(effects_A_SHADER, "ColorMAP");
    UNIFORM_DOT3_effects_A                                  = glGetUniformLocation(effects_A_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_effects_A                      = glGetUniformLocation(effects_A_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_effects_A                               = glGetUniformLocation(effects_A_SHADER, "EnvMap");
    UNIFORM_MASK0_effects_A                                 = glGetUniformLocation(effects_A_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_effects_A                   = glGetUniformLocation(effects_A_SHADER, "ShadowMAP_PENUMBRA");

//######################################################


glActiveTexture (GL_TEXTURE5);
glBindTexture(GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);










