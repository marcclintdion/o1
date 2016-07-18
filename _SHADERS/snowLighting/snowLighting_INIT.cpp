
#include    "snowLighting_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
snowLighting_SHADER = glCreateProgram();

//===============
#if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"snowLighting" ofType:@"vert"];
vertexSource_snowLighting   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"snowLighting" ofType:@"frag"];
fragmentSource_snowLighting = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif TARGET_OS_MAC == 1 || WIN32 == 1
vertexSource_snowLighting   = readShaderFile( "_SHADERS/snowLighting/snowLighting.vert" );
fragmentSource_snowLighting = readShaderFile( "_SHADERS/snowLighting/snowLighting.frag" );
#endif
//===============


    //=======================================================================================================================
    snowLighting_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( snowLighting_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_snowLighting, NULL );
    glCompileShader( snowLighting_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    snowLighting_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( snowLighting_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_snowLighting, NULL );
    glCompileShader(snowLighting_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( snowLighting_SHADER, snowLighting_SHADER_VERTEX );
    glAttachShader( snowLighting_SHADER, snowLighting_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(snowLighting_SHADER,   0, "position");
    glBindAttribLocation(snowLighting_SHADER,   1, "normal");
    glBindAttribLocation(snowLighting_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( snowLighting_SHADER_VERTEX);
    glDeleteShader( snowLighting_SHADER_FRAGMENT);
    glLinkProgram(snowLighting_SHADER);                                                                                      
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_snowLighting               = glGetUniformLocation(snowLighting_SHADER, "projectionMatrix");
    UNIFORM_invertViewMatrix_snowLighting                = glGetUniformLocation(snowLighting_SHADER, "invertViewMatrix");
    UNIFORM_modelMatrix_snowLighting                     = glGetUniformLocation(snowLighting_SHADER, "modelMatrix");
    UNIFORM_invertModelMatrix_snowLighting               = glGetUniformLocation(snowLighting_SHADER, "invertModelMatrix");
    UNIFORM_modelViewMatrix_snowLighting                 = glGetUniformLocation(snowLighting_SHADER, "modelViewMatrix");
    UNIFORM_invertModelViewMatrix_snowLighting           = glGetUniformLocation(snowLighting_SHADER, "invertModelViewMatrix");
    UNIFORM_ShadowMapMatrix_snowLighting                 = glGetUniformLocation(snowLighting_SHADER, "shadowMapMatrix");
    UNIFORM_TEXTURE_SPACE_MATRIX_snowLighting            = glGetUniformLocation(snowLighting_SHADER, "textureSpaceMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POSITION_snowLighting                 = glGetUniformLocation(snowLighting_SHADER, "light0_POS");
    UNIFORM_movingGlossyLight_POSITION_snowLighting      = glGetUniformLocation(snowLighting_SHADER, "light1_POS");
    //==================================
    UNIFORM_shadowBias_UMBRA_snowLighting                = glGetUniformLocation(snowLighting_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_snowLighting             = glGetUniformLocation(snowLighting_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_UVmap_SWITCH_1_snowLighting                  = glGetUniformLocation(snowLighting_SHADER, "UVmap_SWITCH_1");

    UNIFORM_f_0_snowLighting                             = glGetUniformLocation(snowLighting_SHADER, "f_0");
    UNIFORM_f_1_snowLighting                             = glGetUniformLocation(snowLighting_SHADER, "f_1");
    UNIFORM_f_2_snowLighting                             = glGetUniformLocation(snowLighting_SHADER, "f_2");
    UNIFORM_f_3_snowLighting                             = glGetUniformLocation(snowLighting_SHADER, "f_3");
    UNIFORM_f_4_snowLighting                             = glGetUniformLocation(snowLighting_SHADER, "f_4");
    UNIFORM_f_5_snowLighting                             = glGetUniformLocation(snowLighting_SHADER, "f_5");

    UNIFORM_mixVertexAndBakedNormals_snowLighting        = glGetUniformLocation(snowLighting_SHADER, "mixVertexAndBakedNormals");

    //--------------------------------
    UNIFORM_EMIT_snowLighting                            = glGetUniformLocation(snowLighting_SHADER, "ColorMAP");
    UNIFORM_DOT3_snowLighting                            = glGetUniformLocation(snowLighting_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_snowLighting                = glGetUniformLocation(snowLighting_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_snowLighting                         = glGetUniformLocation(snowLighting_SHADER, "CubeMAP");
    UNIFORM_MASK0_snowLighting                           = glGetUniformLocation(snowLighting_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_snowLighting             = glGetUniformLocation(snowLighting_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_snowLighting               = glGetUniformLocation(snowLighting_SHADER, "caustics_WATERMAP");

//######################################################

glActiveTexture (GL_TEXTURE5);
glBindTexture(GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);












