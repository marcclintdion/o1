

mixGlazedVelvet_SHADER = glCreateProgram();

    vertexSource_mixGlazedVelvet        = readShaderFile( "_SHADERS/mixGlazedVelvet/mixGlazedVelvet.vert" );
    fragmentSource_mixGlazedVelvet      = readShaderFile( "_SHADERS/mixGlazedVelvet/mixGlazedVelvet.frag" );


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

    UNIFORM_PROJECTION_MATRIX_mixGlazedVelvet                           = glGetUniformLocation(mixGlazedVelvet_SHADER, "projectionMatrix");
    UNIFORM_invertViewMatrix_mixGlazedVelvet                            = glGetUniformLocation(mixGlazedVelvet_SHADER, "invertViewMatrix");
    UNIFORM_invertModelMatrix_mixGlazedVelvet                           = glGetUniformLocation(mixGlazedVelvet_SHADER, "invertModelMatrix");
    //-------------------------------
    UNIFORM_LIGHT0_POS_mixGlazedVelvet                                  = glGetUniformLocation(mixGlazedVelvet_SHADER, "light0_POS");
    UNIFORM_movingGlossyLight_POS_mixGlazedVelvet                       = glGetUniformLocation(mixGlazedVelvet_SHADER, "light1_POS");
    //==================================
    UNIFORM_f_0_mixGlazedVelvet                                         = glGetUniformLocation(mixGlazedVelvet_SHADER, "f_0");
    UNIFORM_f_1_mixGlazedVelvet                                         = glGetUniformLocation(mixGlazedVelvet_SHADER, "f_1");

    UNIFORM_noiseScale_mixGlazedVelvet                                  = glGetUniformLocation(mixGlazedVelvet_SHADER, "noiseScale");
                                  
    //--------------------------------
    UNIFORM_TEX_COLOR_mixGlazedVelvet                                   = glGetUniformLocation(mixGlazedVelvet_SHADER, "ColorMAP");
    UNIFORM_TEX_DOT3_mixGlazedVelvet                                    = glGetUniformLocation(mixGlazedVelvet_SHADER, "NormalMAP");
    //shadow
    UNIFORM_TEX_MASK0_mixGlazedVelvet                                   = glGetUniformLocation(mixGlazedVelvet_SHADER, "Mask0MAP");

//######################################################


//#include "settings.cpp"  This should be parsed as a text file so it won't override current settings with startup settings that are pre-compiled and in loaded here











