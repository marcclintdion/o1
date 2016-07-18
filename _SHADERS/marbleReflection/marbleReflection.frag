 #ifdef GL_ES                                                                                                                                              
 #else                                                                                                                                                     
 #define highp                                                                                                                                             
 #endif                                                                                                                                                    


varying     highp   vec2    uv0_PASS;

uniform     sampler2D       ColorMAP;
            highp   vec4    colorTexture;
            highp   vec4    ColorMix;

varying     highp   vec3    normal_PASS;
            highp   vec3    normal_VERT;

uniform     sampler2D       NormalMAP;
            highp   vec3    bakedNormals;

            highp   float   nDotL0;
            highp   float   nDotL1;

uniform     highp   vec4    light0_POS;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

            highp   vec3    lightPos0_Normalized;
            highp   vec3    lightPos1_Normalized;

uniform     sampler2D       Mask0MAP;
            highp   vec4    Mask0Texture;

uniform     sampler2D       ReflectionMAP;
            highp   vec4    reflectionTexture;
varying     highp   vec4    projectionTexcoord;

uniform     sampler2D       ShadowMAP_UMBRA;
uniform     sampler2D       ShadowMAP_PENUMBRA;

varying     highp   vec4    shadowTexcoord;
            highp   vec4    depthTexture;
uniform     highp   float   shadowBias_UMBRA;
uniform     highp   float   shadowBias_PENUMBRA;

            highp   float   compare_UMBRA;
            highp   float   depth_UMBRA;
            highp   float   shadowVal_UMBRA;

            highp   float   compare_PENUMBRA;
            highp   float   depth_PENUMBRA;
            highp   float   shadowVal_PENUMBRA;

            highp   float   compareBothShadows;

uniform     sampler2D       caustics_WATERMAP;
            highp   vec4    causticsWater;
            highp   vec4    causticsWaterColor  =   highp vec4(0.5, 0.5, 1.0, 1.0);


uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;
uniform     highp   float   f_4;



            highp   vec4    color_A = highp vec4( 0.1,0.3,0.5,1.0 );
            highp   vec4    color_B = highp vec4( 0.1,0.3,0.5,1.0 );
            highp   vec4    color_C = highp vec4( 0.1,0.3,0.5,1.0 );
            highp   float   specular_RED;
            highp   float   specular_GREEN;
            highp   float   specular_BLUE;
            highp   vec4    solarFlare;
            highp   vec4    redColor;
            highp   vec4    greenColor;
            highp   vec4    blueColor;
            highp   vec4    combineSpecular;

            highp   vec4    finalColor_A;

varying     highp   vec3    vViewVec;

            highp   vec4    lightMixL0;
            highp   vec4    lightMixL1;


            highp   vec4    specular;

            highp   float    combineMasks;

void main()
{
 
    reflectionTexture       =   texture2DProj(ReflectionMAP,  projectionTexcoord);
    

    compare_UMBRA           =   (shadowTexcoord.z / shadowTexcoord.w)- shadowBias_UMBRA;    //_
    depth_UMBRA             =   texture2DProj(ShadowMAP_UMBRA,  shadowTexcoord).r;
    shadowVal_UMBRA         =   compare_UMBRA <= depth_UMBRA ? 1.0 : 0.6;

    compare_PENUMBRA        =   (shadowTexcoord.z / shadowTexcoord.w)- shadowBias_PENUMBRA; //_
    depth_PENUMBRA          =   texture2DProj(ShadowMAP_PENUMBRA,  shadowTexcoord).r;
    shadowVal_PENUMBRA      =   compare_PENUMBRA <= depth_PENUMBRA ? 1.0 : 0.7;

    compareBothShadows      =   depth_PENUMBRA - depth_UMBRA;
    
    causticsWater           =   texture2DProj(caustics_WATERMAP, shadowTexcoord);
    causticsWater          +=   texture2DProj(caustics_WATERMAP, highp vec4((1.0-shadowTexcoord.x), shadowTexcoord.y, shadowTexcoord.z, shadowTexcoord.w ));
    
    
    colorTexture            =   texture2D(ColorMAP,  uv0_PASS.xy) * 1.0;
    
    normal_VERT             =   normalize(normal_PASS);
    
    bakedNormals            =   texture2D(NormalMAP,  uv0_PASS.xy).xyz;
    bakedNormals            =   normalize(bakedNormals - 0.5);
    
    lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);
    lightPos1_Normalized    =   normalize(lightPos1_PASS.xyz);

    nDotL0                  =   max(dot(bakedNormals, lightPos0_Normalized), 0.0);
    nDotL1                  =   max(dot(bakedNormals, lightPos1_Normalized), 0.0);

    
    Mask0Texture            =   texture2D(Mask0MAP,  uv0_PASS.xy);
    

    specular                =   highp vec4(1.149102, 1.368898, 1.458478, 1.0)  *  max(pow(nDotL0, 15.934019), 0.0)    ;
    
    
    combineMasks            =   Mask0Texture.g * Mask0Texture.b;
    
    gl_FragColor            =   ( ( (colorTexture * 1.0* f_0 * Mask0Texture.b + (colorTexture * f_1 * 1.0 * reflectionTexture * 0.5 * f_2) * combineMasks ) * f_3 * exp2(nDotL0-1.0) )
                                 
                            + specular * combineMasks
    
    
                               )   * shadowVal_UMBRA  *  shadowVal_PENUMBRA + causticsWater * causticsWaterColor * pow(nDotL0, 6.9) * 8.2 * colorTexture;
    
   
    gl_FragColor            =    highp vec4(  exp2(nDotL0-1.0)  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    //gl_FragColor            =    highp vec4(  nDotL0  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    
    gl_FragColor            =  highp vec4(     pow(    mix(nDotL0, nDotL1, 0.1)   , 0.4545455)      )  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA;
    
    
    
    
    
    
    
    
    
}
















