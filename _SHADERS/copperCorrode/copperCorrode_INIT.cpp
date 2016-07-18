#include    "copperCorrode_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=

copperCorrode_SHADER = glCreateProgram();
//------------------

//===============
#if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"copperCorrode" ofType:@"vert"];
vertexSource_copperCorrode   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"copperCorrode" ofType:@"frag"];
fragmentSource_copperCorrode = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 || WIN32 == 1
vertexSource_copperCorrode   = readShaderFile( "_SHADERS/copperCorrode/copperCorrode.vert" );
fragmentSource_copperCorrode = readShaderFile( "_SHADERS/copperCorrode/copperCorrode.frag" );
#endif
//===============


    //=======================================================================================================================
    copperCorrode_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( copperCorrode_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_copperCorrode, NULL );
    glCompileShader( copperCorrode_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    copperCorrode_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( copperCorrode_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_copperCorrode, NULL );
    glCompileShader(copperCorrode_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( copperCorrode_SHADER, copperCorrode_SHADER_VERTEX );
    glAttachShader( copperCorrode_SHADER, copperCorrode_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(copperCorrode_SHADER,   0, "position");
    glBindAttribLocation(copperCorrode_SHADER,   1, "normal");
    glBindAttribLocation(copperCorrode_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( copperCorrode_SHADER_VERTEX);
    glDeleteShader( copperCorrode_SHADER_FRAGMENT);
    glLinkProgram(  copperCorrode_SHADER);
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_copperCorrode                     = glGetUniformLocation(copperCorrode_SHADER, "projectionMatrix");
    UNIFORM_MODELVIEW_MATRIX_copperCorrode                      = glGetUniformLocation(copperCorrode_SHADER, "modelViewMatrix");
    UNIFORM_invertModelViewMatrix_copperCorrode                 = glGetUniformLocation(copperCorrode_SHADER, "invertModelViewMatrix");
    UNIFORM_invertViewMatrix_copperCorrode                      = glGetUniformLocation(copperCorrode_SHADER, "invertViewMatrix_L0");
    UNIFORM_invertModelMatrix_copperCorrode                     = glGetUniformLocation(copperCorrode_SHADER, "invertModelMatrix_L1");

    UNIFORM_ShadowMapMatrix_copperCorrode                       = glGetUniformLocation(copperCorrode_SHADER, "shadowMapMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POS_copperCorrode                            = glGetUniformLocation(copperCorrode_SHADER, "light0_POS");
    UNIFORM_LIGHT1_POS_copperCorrode                            = glGetUniformLocation(copperCorrode_SHADER, "light1_POS");
    //==================================
    UNIFORM_shadowBias_UMBRA_copperCorrode                      = glGetUniformLocation(copperCorrode_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_copperCorrode                   = glGetUniformLocation(copperCorrode_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_f_0_copperCorrode                                   = glGetUniformLocation(copperCorrode_SHADER, "f_0");
    UNIFORM_f_1_copperCorrode                                   = glGetUniformLocation(copperCorrode_SHADER, "f_1");
    UNIFORM_f_2_copperCorrode                                   = glGetUniformLocation(copperCorrode_SHADER, "f_2");
    UNIFORM_f_3_copperCorrode                                   = glGetUniformLocation(copperCorrode_SHADER, "f_3");
    UNIFORM_f_4_copperCorrode                                   = glGetUniformLocation(copperCorrode_SHADER, "f_4");
    UNIFORM_f_5_copperCorrode                                   = glGetUniformLocation(copperCorrode_SHADER, "f_5");

    //--------------------------------
    UNIFORM_EMIT_copperCorrode                                  = glGetUniformLocation(copperCorrode_SHADER, "ColorMAP");
    UNIFORM_DOT3_copperCorrode                                  = glGetUniformLocation(copperCorrode_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_copperCorrode                      = glGetUniformLocation(copperCorrode_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_copperCorrode                               = glGetUniformLocation(copperCorrode_SHADER, "EnvMap");
    UNIFORM_MASK0_copperCorrode                                 = glGetUniformLocation(copperCorrode_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_copperCorrode                   = glGetUniformLocation(copperCorrode_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_copperCorrode                           = glGetUniformLocation(copperCorrode_SHADER, "caustics_WATERMAP");
//######################################################


glActiveTexture (GL_TEXTURE5);
glBindTexture(GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);










