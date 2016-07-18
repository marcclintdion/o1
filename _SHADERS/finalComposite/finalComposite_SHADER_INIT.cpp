#include    "finalComposite_SHADER_END.cpp"//_AVOID_MEMORY_LEAKS_AT_RUNTIME._THIS_DEACTIVATES_EXISTING_BUFFERS_BEFORE_RE-LOADING.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

      #if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      finalComposite_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   

    //==============================================================================================================
    //===============
    #if  TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
    filePathName = [[NSBundle mainBundle] pathForResource:@"finalComposite" ofType:@"vert"];
    vertexSource_finalComposite   = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
    filePathName = [[NSBundle mainBundle] pathForResource:@"finalComposite" ofType:@"frag"];
    fragmentSource_finalComposite = readShaderFile([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
    //===============
    #elif  TARGET_OS_MAC == 1 || WIN32 == 1
    vertexSource_finalComposite   = readShaderFile( "_SHADERS/finalComposite/finalComposite.vert" );
    fragmentSource_finalComposite = readShaderFile( "_SHADERS/finalComposite/finalComposite.frag" );
    #endif
    //===============
    //==============================================================================================================

    finalComposite_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(finalComposite_SHADER_VERTEX, 1, (const char **)&vertexSource_finalComposite, NULL);
    glCompileShader(finalComposite_SHADER_VERTEX);
    //---------------------------------------------------------------------
    finalComposite_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(finalComposite_SHADER_FRAGMENT, 1, (const char **)&fragmentSource_finalComposite, NULL);
    glCompileShader(finalComposite_SHADER_FRAGMENT);
    //------------------------------------------------
    glAttachShader(finalComposite_SHADER, finalComposite_SHADER_VERTEX);
    glAttachShader(finalComposite_SHADER, finalComposite_SHADER_FRAGMENT);
    //------------------------------------------------
    glBindAttribLocation(finalComposite_SHADER, 0, "position");
    glBindAttribLocation(finalComposite_SHADER, 1, "texture");
    //glBindAttribLocation(finalComposite _SHADER, 2, "normal");
    //------------------------------------------------
    glLinkProgram(finalComposite_SHADER);
    //------------------------------------------------
    #ifdef __APPLE__
    glDetachShader(finalComposite_SHADER, finalComposite_SHADER_VERTEX);
    glDetachShader(finalComposite_SHADER, finalComposite_SHADER_FRAGMENT);
    #endif
    //------------------------------------------------
    glDeleteShader(finalComposite_SHADER_VERTEX);
    glDeleteShader(finalComposite_SHADER_FRAGMENT);
    //---------------------------------------------------------------------------------------------------------
    UNIFORM_MODEL_MATRIX_finalComposite               = glGetUniformLocation(finalComposite_SHADER,   "modelMatrix");
    UNIFORM_TEXTURE_0_finalComposite                  = glGetUniformLocation(finalComposite_SHADER,   "Texture0");
    UNIFORM_TEXTURE_1_finalComposite                  = glGetUniformLocation(finalComposite_SHADER,   "Texture1");


