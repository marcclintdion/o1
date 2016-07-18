 #ifdef GL_ES                                                                                                                                              
 #else                                                                                                                                                     
 #define highp                                                                                                                                             
 #endif                                                                                                                                                    

uniform     sampler2D       ColorMAP;
            highp   vec4    colorTexture;


uniform     sampler2D       NormalMAP;
            highp   vec3    bakedNormals;
            highp   float   nDotL0;

uniform     sampler2D       Mask0MAP;
            highp   vec4    mask0texture;


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
varying     highp   vec3    normal_PASS;
            highp   vec3    vert_NORMALS;
            highp   float   VnDotL;


varying     highp   vec2    uv0_PASS;

            highp   vec3    lightPos0_Normalized;


uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;



            highp   vec4    finalColor_A;


            highp   float   specular_A;
            highp   float   specular_B;
            highp   float   specular_C;
            highp   vec4    specular_FINAL;

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
    
    mask0texture            =   texture2D(Mask0MAP,  uv0_PASS.xy);
    
    colorTexture            =   texture2D(ColorMAP,  uv0_PASS.xy) * 1.3;
    
    lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);
     
    bakedNormals            =   texture2D(NormalMAP, uv0_PASS).xyz;
    bakedNormals            =   normalize(bakedNormals - 0.5);
    nDotL0                  =   max( dot(bakedNormals, lightPos0_Normalized), 0.0);
    
    vert_NORMALS            =   normalize(normal_PASS);
    //VnDotL                  =   max(dot(vert_NORMALS, lightPos0_Normalized), 0.0);
   
    //bakedNormals            =   texture2D(NormalMAP,  uv0_PASS.xy).xyz;
    //bakedNormals            =   normalize(bakedNormals - 0.5) ;
    //nDotL0                  =   max(dot(bakedNormals, lightPos0_Normalized), 0.0);

   
    //specular_A              =   max(     pow(  VnDotL, 18.312981  *  f_3   )      , 0.0)         ;
    //specular_B              =   max(     pow(  VnDotL, 63.443005  *  f_3   )      , 0.0)         ;
    //specular_C              =   max(     pow(  VnDotL, 199.264786 *  f_3   )      , 0.0)         ;
    
    //specular_FINAL          =   highp vec4(specular_A, specular_B, specular_C, 1.0);
    
    
    finalColor_A            =   (colorTexture * mix(exp2(nDotL0-1.0), nDotL0, colorTexture.r * nDotL0)   )   *  shadowVal_UMBRA  *  shadowVal_PENUMBRA;
   
    gl_FragColor            =   finalColor_A + causticsWater * causticsWaterColor * pow(nDotL0, 6.93) * 8.2 * colorTexture;
    
    gl_FragColor.a          =   mask0texture.r;
   
    
    
    
    gl_FragColor            =    highp vec4(  exp2(nDotL0-1.0)  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    //gl_FragColor            =    highp vec4(  nDotL0  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    
    gl_FragColor            =  highp vec4(pow(nDotL0, 0.4545455))  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA;
    
   
    
    
    
    
 
}
















