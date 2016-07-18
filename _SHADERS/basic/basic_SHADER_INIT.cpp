////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
basic_SHADER = glCreateProgram();

//----------------------------------------------------
const GLchar *vertexSource_basic =

"#define highp                                                                                                      \n"

"attribute          vec4    position;                                                                               \n"
"attribute          vec2    uv0;                                                                                    \n"

"uniform            mat4    projectionMatrix;                                                                       \n"
"uniform            mat4    invertViewMatrix_L0;                                                                   \n"
"uniform            mat4    invertModelMatrix_L1;                                                                   \n"

"uniform    highp   vec4    light0_POS;                                                                             \n"
"uniform    highp   vec4    light1_POS;                                                                             \n"

"varying    highp   vec3    lightPos0_PASS;                                                                          \n"
"varying    highp   vec3    lightPos1_PASS;                                                                          \n"

"varying    highp   vec2    uv0_PASS;                                                                               \n"



"//=========//                                                                                                      \n"
"void main()                                                                                                        \n"
"{                                                                                                                  \n"
"//=========//                                                                                                      \n"


"   lightPos0_PASS           = (invertModelMatrix_L1 * light0_POS).xyz;                                            \n"

"   lightPos1_PASS           = (invertModelMatrix_L1 * light1_POS).xyz;                                           \n"


"   uv0_PASS                =  uv0;                                                                                 \n"

"                                                                                                                   \n"




"   gl_Position             =  projectionMatrix * position;                                                         \n"

"//========//                                                                                                       \n"
"}\n";
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const GLchar *fragmentSource_basic =

" #ifdef GL_ES                                                                                                                                              \n"
" #else                                                                                                                                                     \n"
" #define highp                                                                                                                                             \n"
" #endif                                                                                                                                                    \n"

"uniform    sampler2D       ColorMAP;                                                                                                                       \n"
"           highp   vec4    ColorTexture;                                                                                                                   \n"
"           highp   vec4    ColorMix;                                                                                                                       \n"

"uniform    sampler2D       NormalMAP;                                                                                                                      \n"
"           highp   vec4    bakedNormals;                                                                                                                   \n"

"           highp   float   nDotL0;                                                                                                                         \n"
"           highp   float   nDotL1;                                                                                                                         \n"

"uniform    sampler2D       Mask0MAP;                                                                                                                       \n"
"           highp   vec4    Mask0Texture;                                                                                                                   \n"


"varying    highp   vec3    lightPos0_PASS;                                                                                                                 \n"
"varying    highp   vec3    lightPos1_PASS;                                                                                                                 \n"

"           highp   vec3    lightPos0_Normalized;                                                                                                           \n"
"           highp   vec3    lightPos1_Normalized;                                                                                                           \n"


"uniform    highp   float   f_0;                                                                                                                            \n"
"uniform    highp   float   f_1;                                                                                                                            \n"

"           highp   vec4    color_A = highp vec4( 0.1,0.3,0.5,1.0 );                                                                                        \n"
"           highp   vec4    color_B = highp vec4( 0.1,0.3,0.5,1.0 );                                                                                        \n"
"           highp   vec4    color_C = highp vec4( 0.1,0.3,0.5,1.0 );                                                                                        \n"
"           highp   float   specular_RED;                                                                                                                   \n"
"           highp   float   specular_GREEN;                                                                                                                 \n"
"           highp   float   specular_BLUE;                                                                                                                  \n"
"           highp   vec4    solarFlare;                                                                                                                     \n"
"           highp   vec4    redColor;                                                                                                                       \n"
"           highp   vec4    greenColor;                                                                                                                     \n"
"           highp   vec4    blueColor;                                                                                                                      \n"
"           highp   vec4    combineSpecular;                                                                                                                \n"


"           highp   vec4    lightMixL0;                                                                                                                     \n"
"           highp   vec4    lightMixL1;                                                                                                                     \n"



"varying    highp   vec2    uv0_PASS;                                                                                                                                           \n"



"//=========//                                                                                                                                                                  \n"
"void main()                                                                                                                                                                    \n"
"{                                                                                                                                                                              \n"
"//=========//                                                                                                                                                                  \n"

"   ColorTexture            =   texture2D(ColorMAP,  uv0_PASS.xy);                                                                                                              \n"

"   bakedNormals            =   texture2D(NormalMAP,  uv0_PASS.xy);                                                                                                             \n"
"   bakedNormals.xyz        =   normalize(bakedNormals.xyz - 0.5);                                                                                                              \n"

"   lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);                                                                                                                  \n"
"   lightPos1_Normalized    =   normalize(lightPos1_PASS.xyz);                                                                                                                  \n"

"   nDotL0                  =   max(dot(bakedNormals.xyz, lightPos0_Normalized), 0.0);                                                                                          \n"
"   nDotL1                  =   max(dot(bakedNormals.xyz, lightPos1_Normalized), 0.0);                                                                                          \n"


"   Mask0Texture            =   texture2D(Mask0MAP,  uv0_PASS.xy);                                                                                                              \n"




"   lightMixL0              =   highp vec4(   exp2(pow(nDotL0, 600.0))  * 0.6 * 1.691199) ;                                                                                     \n"
"   lightMixL1              =   highp vec4(   exp2(nDotL0 * nDotL1 * nDotL1) * 0.5 * f_0) ;                                                                                     \n"



"   specular_RED            =   max(pow(nDotL1,  400.0  * Mask0Texture.r), 0.0);                                                                                                \n"

"   specular_GREEN          =   max(pow(nDotL1,  500.0  * Mask0Texture.r), 0.0);                                                                                                \n"

"   specular_BLUE           =   max(pow(nDotL1,  600.0  * Mask0Texture.r), 0.0);                                                                                                \n"

"   solarFlare              =   highp  vec4(specular_RED, specular_GREEN, specular_BLUE, 1.0);                                                                                  \n"

"   redColor                =   highp  vec4(4.0 * Mask0Texture.r, 0.0, 0.0, 1.0) * pow(nDotL1,  8.0 ) * 0.184800 + highp vec4(specular_RED, 0.0, 0.0, 1.0   ) * 2.377594 ;      \n"

"   greenColor              =   highp  vec4(0.0, 4.0 * Mask0Texture.r, 0.0, 1.0) * pow(nDotL1, 16.0 ) * 0.184800 + highp vec4(0.0, specular_GREEN, 0.0, 1.0 ) * 2.377594 ;      \n"

"   blueColor               =   highp  vec4(0.0, 0.0, 4.0 * Mask0Texture.r, 1.0) * pow(nDotL1, 32.0 ) * 0.184800 + highp vec4(0.0, 0.0, specular_BLUE, 1.0  ) * 2.377594 ;      \n"

"   combineSpecular         =   (highp  vec4(0.1, 0.32, 0.4, 1.0) * 0.168 + (redColor + greenColor + blueColor)) * Mask0Texture.r;                                              \n"


"   ColorMix                =   ColorTexture * (mix(lightMixL1 , lightMixL0 + (combineSpecular + solarFlare) * Mask0Texture.r   , nDotL0)) ;                                    \n"


"   gl_FragColor            =    ColorMix;                                                                                                                                      \n"


//"   gl_FragColor            =  highp vec4(specular_RED);                                                                                                                      \n"

//==========================================================================================================================================================
//_A_BIT_METALLIC   "   gl_FragColor            =  texture2D(ColorMAP,  uv0_PASS.xy) * highp vec4(    exp(nDotL1) * exp2(nDotL1) * 0.2     );    //USED_FOR_BASE_SPECULAR_HIGHLIGHT_PERHAPS?  \n"
//==========================================================================================================================================================
//"   gl_FragColor            =   highp  vec4(specular_RED* texture2D(ColorMAP,  uv0_PASS.xy).w, specular_GREEN * texture2D(ColorMAP,  uv0_PASS.xy).w, specular_BLUE * texture2D(ColorMAP,  uv0_PASS.xy).w, 1.0);   \n"




//==========================================================================================================================================================
//_DAY_2_           "   nDotL1                  =   max(dot(bakedNormals, lightPos_Normalized), 0.0);                                                        \n"

//_DAY_2_           "   gl_FragColor            =  texture2D(ColorMAP,  uv0_PASS.xy) * highp vec4(    exp2(nDotL1) * exp2(nDotL1) * 0.4    );               \n"
//==========================================================================================================================================================
//_NIGHT_           "   gl_FragColor            =  texture2D(ColorMAP,  uv0_PASS.xy) * highp vec4(    exp2(nDotL1) * 0.2    );                               \n"
//==========================================================================================================================================================
//_DAY_             "   gl_FragColor            =  texture2D(ColorMAP,  uv0_PASS.xy) * highp vec4(    exp2(nDotL1) * 0.7    );                               \n"



"//=========//                                                                                                                                              \n"
"}\n";
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        //=======================================================================================================================                   
        basic_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( basic_SHADER_VERTEX, 1,   &vertexSource_basic, NULL );
        glCompileShader( basic_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        basic_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( basic_SHADER_FRAGMENT, 1, &fragmentSource_basic, NULL );
        glCompileShader(basic_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( basic_SHADER, basic_SHADER_VERTEX );                                                        
        glAttachShader( basic_SHADER, basic_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(basic_SHADER,   0, "position");                                                              
        glBindAttribLocation(basic_SHADER,   1, "normal");                                                            
        glBindAttribLocation(basic_SHADER,   2, "uv0");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( basic_SHADER_VERTEX);                                                                             
        glDeleteShader( basic_SHADER_FRAGMENT);                                                                           
        glLinkProgram(basic_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    

        UNIFORM_PROJECTION_MATRIX_basic                         = glGetUniformLocation(basic_SHADER, "projectionMatrix");
        UNIFORM_invertViewMatrix_basic                          = glGetUniformLocation(basic_SHADER, "invertViewMatrix_L0");
        UNIFORM_invertModelMatrix_basic                         = glGetUniformLocation(basic_SHADER, "invertModelMatrix_L1");
        //-------------------------------
        UNIFORM_LIGHT0_POS_basic                                = glGetUniformLocation(basic_SHADER, "light0_POS");
        UNIFORM_movingGlossyLight_POS_basic                     = glGetUniformLocation(basic_SHADER, "light1_POS");
        //==================================
        UNIFORM_f_0_basic                                       = glGetUniformLocation(basic_SHADER, "f_0");
        UNIFORM_f_1_basic                                       = glGetUniformLocation(basic_SHADER, "f_1");

                                   
        //--------------------------------
        UNIFORM_TEX_COLOR_basic                                 = glGetUniformLocation(basic_SHADER, "ColorMAP");
        UNIFORM_TEX_DOT3_basic                                  = glGetUniformLocation(basic_SHADER, "NormalMAP");
        //shadow
        UNIFORM_TEX_MASK0_basic                                 = glGetUniformLocation(basic_SHADER, "Mask0MAP");

//######################################################


//#include "settings.cpp"  This should be parsed as a text file so it won't override current settings with startup settings that are pre-compiled and in loaded here











