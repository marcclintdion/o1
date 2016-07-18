
#include    "tree_38_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
tree_38_SHADER = glCreateProgram();

//===============
#if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
filePathName = [[NSBundle mainBundle] pathForResource:@"tree_38" ofType:@"vert"];
vertexSource_tree_38   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
filePathName = [[NSBundle mainBundle] pathForResource:@"tree_38" ofType:@"frag"];
fragmentSource_tree_38 = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
//===============
#elif  TARGET_OS_MAC == 1 || WIN32 == 1
vertexSource_tree_38   = readShaderFile( "_SHADERS/tree_38/tree_38.vert" );
fragmentSource_tree_38 = readShaderFile( "_SHADERS/tree_38/tree_38.frag" );
#endif
//===============

    //=======================================================================================================================
    tree_38_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( tree_38_SHADER_VERTEX, 1,   (const GLchar**)&vertexSource_tree_38, NULL );
    glCompileShader( tree_38_SHADER_VERTEX);                                              //glShaderBinary
    //----------------------------------------------------
    tree_38_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);
    glShaderSource( tree_38_SHADER_FRAGMENT, 1, (const GLchar**)&fragmentSource_tree_38, NULL );
    glCompileShader(tree_38_SHADER_FRAGMENT);                                              //glShaderBinary
    //--------------------------------------------------------------------------------------------------
    glAttachShader( tree_38_SHADER, tree_38_SHADER_VERTEX );
    glAttachShader( tree_38_SHADER, tree_38_SHADER_FRAGMENT );
    //--------------------------------------------------------------------------------------------------
    glBindAttribLocation(tree_38_SHADER,   0, "position");
    glBindAttribLocation(tree_38_SHADER,   1, "normal");
    glBindAttribLocation(tree_38_SHADER,   2, "uv0");
    //--------------------------------------------------------------------------------------------------
    glDeleteShader( tree_38_SHADER_VERTEX);
    glDeleteShader( tree_38_SHADER_FRAGMENT);
    glLinkProgram(tree_38_SHADER);                                                                                      
    //--------------------------------------------------------------------------------------------------

    UNIFORM_PROJECTION_MATRIX_tree_38               = glGetUniformLocation(tree_38_SHADER, "projectionMatrix");
    UNIFORM_invertViewMatrix_tree_38                = glGetUniformLocation(tree_38_SHADER, "invertViewMatrix");
    UNIFORM_modelMatrix_tree_38                     = glGetUniformLocation(tree_38_SHADER, "modelMatrix");
    UNIFORM_invertModelMatrix_tree_38               = glGetUniformLocation(tree_38_SHADER, "invertModelMatrix");
    UNIFORM_modelViewMatrix_tree_38                 = glGetUniformLocation(tree_38_SHADER, "modelViewMatrix");
    UNIFORM_invertModelViewMatrix_tree_38           = glGetUniformLocation(tree_38_SHADER, "invertModelViewMatrix");
    UNIFORM_ShadowMapMatrix_tree_38                 = glGetUniformLocation(tree_38_SHADER, "shadowMapMatrix");
    UNIFORM_TEXTURE_SPACE_MATRIX_tree_38            = glGetUniformLocation(tree_38_SHADER, "textureSpaceMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POSITION_tree_38                 = glGetUniformLocation(tree_38_SHADER, "light0_POS");
    UNIFORM_movingGlossyLight_POSITION_tree_38      = glGetUniformLocation(tree_38_SHADER, "light1_POS");
    //==================================
    UNIFORM_shadowBias_UMBRA_tree_38                = glGetUniformLocation(tree_38_SHADER, "shadowBias_UMBRA");
    UNIFORM_shadowBias_PENUMBRA_tree_38             = glGetUniformLocation(tree_38_SHADER, "shadowBias_PENUMBRA");

    UNIFORM_f_0_tree_38                             = glGetUniformLocation(tree_38_SHADER, "f_0");
    UNIFORM_f_1_tree_38                             = glGetUniformLocation(tree_38_SHADER, "f_1");
    UNIFORM_f_2_tree_38                             = glGetUniformLocation(tree_38_SHADER, "f_2");
    UNIFORM_f_3_tree_38                             = glGetUniformLocation(tree_38_SHADER, "f_3");
    UNIFORM_f_4_tree_38                             = glGetUniformLocation(tree_38_SHADER, "f_4");
    UNIFORM_f_5_tree_38                             = glGetUniformLocation(tree_38_SHADER, "f_5");


    //--------------------------------
    UNIFORM_EMIT_tree_38                            = glGetUniformLocation(tree_38_SHADER, "ColorMAP");
    UNIFORM_DOT3_tree_38                            = glGetUniformLocation(tree_38_SHADER, "NormalMAP");
    UNIFORM_SHADOW_MAP_UMBRA_tree_38                = glGetUniformLocation(tree_38_SHADER, "ShadowMAP_UMBRA");
    UNIFORM_CUBEMAP_tree_38                         = glGetUniformLocation(tree_38_SHADER, "CubeMAP");
    UNIFORM_MASK0_tree_38                           = glGetUniformLocation(tree_38_SHADER, "Mask0MAP");
    UNIFORM_SHADOW_MAP_PENUMBRA_tree_38             = glGetUniformLocation(tree_38_SHADER, "ShadowMAP_PENUMBRA");
    UNIFORM_caustics_WATERMAP_tree_38               = glGetUniformLocation(tree_38_SHADER, "caustics_WATERMAP");

//######################################################

glActiveTexture (GL_TEXTURE5);
glBindTexture(GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);












