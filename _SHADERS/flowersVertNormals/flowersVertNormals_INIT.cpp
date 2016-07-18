
#include    "flowersVertNormals_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
flowersVertNormals_SHADER = glCreateProgram();

//===============
#if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"flowersVertNormals" ofType:@"vert"];
vertexSource_flowersVertNormals   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"flowersVertNormals" ofType:@"frag"];
fragmentSource_flowersVertNormals = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 || WIN32 == 1
vertexSource_flowersVertNormals   = readShaderFile( "_SHADERS/flowersVertNormals/flowersVertNormals.vert" );
fragmentSource_flowersVertNormals = readShaderFile( "_SHADERS/flowersVertNormals/flowersVertNormals.frag" );
#endif
//===============

    //=======================================================================================================================
    flowersVertNormals_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( flowersVertNormals_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_flowersVertNormals, NULL );
    glCompileShader( flowersVertNormals_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    flowersVertNormals_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( flowersVertNormals_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_flowersVertNormals, NULL );
    glCompileShader(flowersVertNormals_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( flowersVertNormals_SHADER, flowersVertNormals_SHADER_VERTEX );
    glAttachShader( flowersVertNormals_SHADER, flowersVertNormals_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(flowersVertNormals_SHADER,   0, "position");
    glBindAttribLocation(flowersVertNormals_SHADER,   1, "normal");
    glBindAttribLocation(flowersVertNormals_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( flowersVertNormals_SHADER_VERTEX);
    glDeleteShader( flowersVertNormals_SHADER_FRAGMENT);
    glLinkProgram(flowersVertNormals_SHADER);                                                                                      
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_flowersVertNormals               = glGetUniformLocation(flowersVertNormals_SHADER, "projectionMatrix");
    UNIFORM_invertViewMatrix_flowersVertNormals                = glGetUniformLocation(flowersVertNormals_SHADER, "invertViewMatrix");
    UNIFORM_modelMatrix_flowersVertNormals                     = glGetUniformLocation(flowersVertNormals_SHADER, "modelMatrix");
    UNIFORM_invertModelMatrix_flowersVertNormals               = glGetUniformLocation(flowersVertNormals_SHADER, "invertModelMatrix");
    UNIFORM_modelViewMatrix_flowersVertNormals                 = glGetUniformLocation(flowersVertNormals_SHADER, "modelViewMatrix");
    UNIFORM_invertModelViewMatrix_flowersVertNormals           = glGetUniformLocation(flowersVertNormals_SHADER, "invertModelViewMatrix");
    UNIFORM_ShadowMapMatrix_flowersVertNormals                 = glGetUniformLocation(flowersVertNormals_SHADER, "shadowMapMatrix");
    UNIFORM_TEXTURE_SPACE_MATRIX_flowersVertNormals            = glGetUniformLocation(flowersVertNormals_SHADER, "textureSpaceMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POSITION_flowersVertNormals                 = glGetUniformLocation(flowersVertNormals_SHADER, "light0_POS");
    UNIFORM_movingGlossyLight_POSITION_flowersVertNormals      = glGetUniformLocation(flowersVertNormals_SHADER, "light1_POS");
    //==================================
    UNIFORM_shadowBias_UMBRA_flowersVertNormals                = glGetUniformLocation(flowersVertNormals_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_flowersVertNormals             = glGetUniformLocation(flowersVertNormals_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_f_0_flowersVertNormals                             = glGetUniformLocation(flowersVertNormals_SHADER, "f_0");
    UNIFORM_f_1_flowersVertNormals                             = glGetUniformLocation(flowersVertNormals_SHADER, "f_1");
    UNIFORM_f_2_flowersVertNormals                             = glGetUniformLocation(flowersVertNormals_SHADER, "f_2");
    UNIFORM_f_3_flowersVertNormals                             = glGetUniformLocation(flowersVertNormals_SHADER, "f_3");
    UNIFORM_f_4_flowersVertNormals                             = glGetUniformLocation(flowersVertNormals_SHADER, "f_4");
    UNIFORM_f_5_flowersVertNormals                             = glGetUniformLocation(flowersVertNormals_SHADER, "f_5");


    //--------------------------------
    UNIFORM_EMIT_flowersVertNormals                            = glGetUniformLocation(flowersVertNormals_SHADER, "ColorMAP");
    UNIFORM_DOT3_flowersVertNormals                            = glGetUniformLocation(flowersVertNormals_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_flowersVertNormals                = glGetUniformLocation(flowersVertNormals_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_flowersVertNormals                         = glGetUniformLocation(flowersVertNormals_SHADER, "CubeMAP");
    UNIFORM_MASK0_flowersVertNormals                           = glGetUniformLocation(flowersVertNormals_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_flowersVertNormals             = glGetUniformLocation(flowersVertNormals_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_flowersVertNormals               = glGetUniformLocation(flowersVertNormals_SHADER, "caustics_WATERMAP");

//######################################################

glActiveTexture (GL_TEXTURE5);
glBindTexture(GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);












