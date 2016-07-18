 #ifdef GL_ES                                                                                                                                              
 #else                                                                                                                                                     
 #define highp                                                                                                                                             
 #endif                                                                                                                                                    

uniform     sampler2D       ColorMAP;
            highp   vec4    colorTexture_BL;
            highp   vec4    colorTexture_BR;
            highp   vec4    colorTexture_TL;
            highp   vec4    colorTexture_TR;

            highp   vec4    colorTexture_MIX_1;
            highp   vec4    colorTexture_MIX_2;
            highp   vec4    colorTexture_MIX_3;
//            highp   vec4    colorTexture_MIX_FINAL;



uniform     sampler2D       NormalMAP;
            highp   vec3    bakedNormals;
            highp   float   nDotL0;
            highp   float   nDotL1;


uniform     sampler2D       ShadowMAP_UMBRA;
uniform     sampler2D       ShadowMAP_PENUMBRA;

varying     highp   vec4    shadowTexcoord;
            highp   vec4    depthTexture;
uniform     highp   float   shadowBias_UMBRA;
uniform     highp   float   shadowBias_PENUMBRA;

uniform     sampler2D       caustics_WATERMAP;
            highp   vec4    causticsWater;
            highp   vec4    causticsWaterColor = highp vec4(0.5, 0.5, 1.0, 1.0);

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

            highp   vec3    lightPos0_Normalized;
            highp   vec3    lightPos1_Normalized;


uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;
uniform     highp   float   f_4;



varying     highp   vec2    uv0_ORIGINAL;
varying     highp   vec2    uv0_ATLAS_BL;
varying     highp   vec2    uv0_ATLAS_BR;
varying     highp   vec2    uv0_ATLAS_TL;
varying     highp   vec2    uv0_ATLAS_TR;

            highp   vec4    mix_4_textures;

            highp   float   compare_UMBRA;
            highp   float   depth_UMBRA;
            highp   float   shadowVal_UMBRA;

            highp   float   compare_PENUMBRA;
            highp   float   depth_PENUMBRA;
            highp   float   shadowVal_PENUMBRA;

varying     highp   vec4    position_PASS;

            highp   vec3    normalizePosition;

            highp   vec3    noise_MIX;

            highp   vec4    finalColor_A;

void main()
{                                                                                                                                                          
    
    compare_UMBRA           =   (shadowTexcoord.z / shadowTexcoord.w) - shadowBias_UMBRA;
    depth_UMBRA             =   texture2DProj(ShadowMAP_UMBRA,  shadowTexcoord).r;
    shadowVal_UMBRA         =   compare_UMBRA <= depth_UMBRA ? 1.0 : 0.6;

    compare_PENUMBRA        =   (shadowTexcoord.z / shadowTexcoord.w) - shadowBias_PENUMBRA;
    depth_PENUMBRA          =   texture2DProj(ShadowMAP_PENUMBRA,  shadowTexcoord).r;
    shadowVal_PENUMBRA      =   compare_PENUMBRA <= depth_PENUMBRA ? 1.0 : 0.7;
    
    causticsWater           =   texture2DProj(caustics_WATERMAP, shadowTexcoord);
    causticsWater          +=   texture2DProj(caustics_WATERMAP, highp vec4((1.0-shadowTexcoord.x), shadowTexcoord.y, shadowTexcoord.z, shadowTexcoord.w ));
    
    
    bakedNormals            =   texture2D(NormalMAP,  uv0_ORIGINAL.xy).xyz;
    bakedNormals            =   normalize(bakedNormals - 0.5);
    
    lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);
    lightPos1_Normalized    =   normalize(lightPos1_PASS.xyz);

    nDotL0                  =   max(dot(bakedNormals, lightPos0_Normalized), 0.0);
    nDotL1                  =   max(dot(bakedNormals, lightPos1_Normalized), 0.0);
    highp float mixLightLinear  =   pow(      mix(nDotL0, nDotL1, 0.1)  , 0.4545455);

    
    colorTexture_TR         =   texture2D(ColorMAP,  uv0_ATLAS_BL.xy);
    colorTexture_BL         =   texture2D(ColorMAP,  uv0_ATLAS_BR.xy);
    colorTexture_TL         =   texture2D(ColorMAP,  uv0_ATLAS_TL.xy);
    colorTexture_BR         =   texture2D(ColorMAP,  uv0_ATLAS_TR.xy);
    
    //normalizePosition       =   normalize(position_PASS.xyz);
    
    colorTexture_MIX_1      =   mix(colorTexture_BL,    colorTexture_TR,    max( dot(highp vec3(cos(position_PASS.x   + f_4)   ),  highp vec3(nDotL1 * f_0 + f_3)    )      , 0.0)    )   ;
    colorTexture_MIX_2      =   mix(colorTexture_TL,    colorTexture_BR,    max( dot(highp vec3(sin(position_PASS.y*10.0)*-1.0 ),  highp vec3(nDotL1 * f_1 + f_3)    )       , 0.0)    )  ;
    colorTexture_MIX_3      =   mix(colorTexture_MIX_1, colorTexture_MIX_2, max( dot(highp vec3(position_PASS.z                ),  highp vec3(nDotL1 * f_2 + f_3)    )         , 0.0)   )  ;
    
    
    finalColor_A            =   colorTexture_MIX_3 * mixLightLinear *  shadowVal_UMBRA  *  shadowVal_PENUMBRA * 1.0    ;
    
    gl_FragColor            =   finalColor_A + causticsWater * causticsWaterColor * pow(nDotL1, 6.93) * 8.2 * colorTexture_MIX_3;
    
    

    
    gl_FragColor            =   highp vec4(mixLightLinear) ;// * shadowVal_UMBRA * shadowVal_PENUMBRA;

}
















