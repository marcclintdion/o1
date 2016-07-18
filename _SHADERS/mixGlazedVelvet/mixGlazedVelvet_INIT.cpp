
#include    "mixGlazedVelvet_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
mixGlazedVelvet_SHADER = glCreateProgram();

//===============
#if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"mixGlazedVelvet" ofType:@"vert"];
vertexSource_mixGlazedVelvet   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"mixGlazedVelvet" ofType:@"frag"];
fragmentSource_mixGlazedVelvet = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 || WIN32 == 1
vertexSource_mixGlazedVelvet   = readShaderFile( "_SHADERS/mixGlazedVelvet/mixGlazedVelvet.vert" );
fragmentSource_mixGlazedVelvet = readShaderFile( "_SHADERS/mixGlazedVelvet/mixGlazedVelvet.frag" );
#endif
//===============

    //=======================================================================================================================
    mixGlazedVelvet_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( mixGlazedVelvet_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_mixGlazedVelvet, NULL );
    glCompileShader( mixGlazedVelvet_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    mixGlazedVelvet_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( mixGlazedVelvet_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_mixGlazedVelvet, NULL );
    glCompileShader(mixGlazedVelvet_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( mixGlazedVelvet_SHADER, mixGlazedVelvet_SHADER_VERTEX );
    glAttachShader( mixGlazedVelvet_SHADER, mixGlazedVelvet_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(mixGlazedVelvet_SHADER,   0, "position");
    glBindAttribLocation(mixGlazedVelvet_SHADER,   1, "normal");
    glBindAttribLocation(mixGlazedVelvet_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( mixGlazedVelvet_SHADER_VERTEX);
    glDeleteShader( mixGlazedVelvet_SHADER_FRAGMENT);
    glLinkProgram(mixGlazedVelvet_SHADER);                                                                                      
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_mixGlazedVelvet               = glGetUniformLocation(mixGlazedVelvet_SHADER, "projectionMatrix");
    UNIFORM_invertViewMatrix_mixGlazedVelvet                = glGetUniformLocation(mixGlazedVelvet_SHADER, "invertViewMatrix");
    UNIFORM_modelMatrix_mixGlazedVelvet                     = glGetUniformLocation(mixGlazedVelvet_SHADER, "modelMatrix");
    UNIFORM_invertModelMatrix_mixGlazedVelvet               = glGetUniformLocation(mixGlazedVelvet_SHADER, "invertModelMatrix");
    UNIFORM_modelViewMatrix_mixGlazedVelvet                 = glGetUniformLocation(mixGlazedVelvet_SHADER, "modelViewMatrix");
    UNIFORM_invertModelViewMatrix_mixGlazedVelvet           = glGetUniformLocation(mixGlazedVelvet_SHADER, "invertModelViewMatrix");
    UNIFORM_ShadowMapMatrix_mixGlazedVelvet                 = glGetUniformLocation(mixGlazedVelvet_SHADER, "shadowMapMatrix");
    UNIFORM_TEXTURE_SPACE_MATRIX_mixGlazedVelvet            = glGetUniformLocation(mixGlazedVelvet_SHADER, "textureSpaceMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POSITION_mixGlazedVelvet                 = glGetUniformLocation(mixGlazedVelvet_SHADER, "light0_POS");
    UNIFORM_movingGlossyLight_POSITION_mixGlazedVelvet      = glGetUniformLocation(mixGlazedVelvet_SHADER, "light1_POS");
    //==================================
    UNIFORM_shadowBias_UMBRA_mixGlazedVelvet                = glGetUniformLocation(mixGlazedVelvet_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_mixGlazedVelvet             = glGetUniformLocation(mixGlazedVelvet_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_f_0_mixGlazedVelvet                             = glGetUniformLocation(mixGlazedVelvet_SHADER, "f_0");
    UNIFORM_f_1_mixGlazedVelvet                             = glGetUniformLocation(mixGlazedVelvet_SHADER, "f_1");
    UNIFORM_f_2_mixGlazedVelvet                             = glGetUniformLocation(mixGlazedVelvet_SHADER, "f_2");
    UNIFORM_f_3_mixGlazedVelvet                             = glGetUniformLocation(mixGlazedVelvet_SHADER, "f_3");
    UNIFORM_f_4_mixGlazedVelvet                             = glGetUniformLocation(mixGlazedVelvet_SHADER, "f_4");
    UNIFORM_f_5_mixGlazedVelvet                             = glGetUniformLocation(mixGlazedVelvet_SHADER, "f_5");


    //--------------------------------
    UNIFORM_EMIT_mixGlazedVelvet                            = glGetUniformLocation(mixGlazedVelvet_SHADER, "ColorMAP");
    UNIFORM_DOT3_mixGlazedVelvet                            = glGetUniformLocation(mixGlazedVelvet_SHADER, "NormalMAP");
    UNIFORM_SKY_mixGlazedVelvet                             = glGetUniformLocation(mixGlazedVelvet_SHADER, "SkyMAP");
    UNIFORM_CUBEMAP_mixGlazedVelvet                         = glGetUniformLocation(mixGlazedVelvet_SHADER, "CubeMAP");
    UNIFORM_MASK0_mixGlazedVelvet                           = glGetUniformLocation(mixGlazedVelvet_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_mixGlazedVelvet             = glGetUniformLocation(mixGlazedVelvet_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_mixGlazedVelvet               = glGetUniformLocation(mixGlazedVelvet_SHADER, "caustics_WATERMAP");

//######################################################

glActiveTexture (GL_TEXTURE5);
glBindTexture(GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);












