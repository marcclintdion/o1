 #ifdef GL_ES                                                                                                                                              
 #else                                                                                                                                                     
 #define highp                                                                                                                                             
 #endif                                                                                                                                                    

uniform     sampler2D       ColorMAP;
            highp   vec4    colorTexture;


uniform     sampler2D       NormalMAP;
            highp   vec3    bakedNormals;
            highp   float   nDotL0;


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

uniform     sampler2D       caustics_WATERMAP;
            highp   vec4    causticsWater;
            highp   vec4    causticsWaterColor  =   highp vec4(0.5, 0.5, 1.0, 1.0);

varying     highp   vec3    lightPos0_PASS;

            highp   vec3    lightPos0_Normalized;


uniform     highp   float   f_0;


varying     highp   vec2    uv0_PASS;


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
    
    colorTexture            =   texture2D(ColorMAP,  uv0_PASS.xy) * 1.0;
    
    bakedNormals            =   texture2D(NormalMAP,  uv0_PASS.xy).xyz;
    bakedNormals            =   normalize(bakedNormals - 0.5);
    lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);

    nDotL0                  =   max(dot(bakedNormals, lightPos0_Normalized), 0.0);

    
    
    finalColor_A            =   colorTexture * highp vec4(exp2(nDotL0-1.0))  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA       ;
   
    gl_FragColor            =   finalColor_A + causticsWater * causticsWaterColor * pow(nDotL0, 6.92) * 8.2 * colorTexture;
    
    
    gl_FragColor            =    highp vec4(  exp2(nDotL0-1.0)  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    //gl_FragColor            =    highp vec4(  nDotL0  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    
    gl_FragColor            =  highp vec4(pow(nDotL0, 0.4545455))  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA;
    






}
















