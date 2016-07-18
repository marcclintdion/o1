 #ifdef GL_ES                                                                                                                                              
 #else                                                                                                                                                     
 #define highp                                                                                                                                             
 #endif                                                                                                                                                    

uniform     sampler2D       ColorMAP;
            highp   vec4    colorTexture;


uniform     sampler2D       NormalMAP;
            highp   vec3    bakedNormals;
            highp   float   nDotL0;

uniform     samplerCube     EnvMap;


uniform     sampler2D       Mask0MAP;
            highp   vec4    maskTexture;


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
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;
uniform     highp   float   f_4;
uniform     highp   float   f_5;


varying     highp   vec2    uv0_PASS;



            highp   vec3    reflection;
            highp   vec3    envColor;

varying     highp   vec4    vertexNormals;

            highp   vec4    finalColor_A;
            highp   vec4    specColor_HIGH;


            highp   vec4    diffuseColor;
            highp   vec4    copperSpecA;
            highp   vec4    copperSpecB;
            highp   vec4    copperSpecC;
            highp   vec4    copperSpecD;

varying     highp   vec3    column0_MVM;
varying     highp   vec3    column1_MVM;
varying     highp   vec3    column2_MVM;

            highp   mat3    modelViewMatrix_PASS;

varying     highp   vec4    position_PASS;


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
   
    colorTexture            =   texture2D(ColorMAP,  uv0_PASS.xy);
    
    maskTexture             =   texture2D(Mask0MAP,  uv0_PASS.xy);
    
    
    bakedNormals            =   texture2D(NormalMAP,  uv0_PASS.xy).xyz;
    bakedNormals            =   normalize(bakedNormals - 0.5) * colorTexture.x;
    lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);
    

    //nDotL0                =   exp2(   max(dot(bakedNormals, lightPos0_Normalized), 0.0)     -1.0)    ;
    nDotL0                  =   max(dot(bakedNormals, lightPos0_Normalized), 0.0)     ;


    
    
    //__CUBEMAP__=====================================================================================
    modelViewMatrix_PASS    =   highp mat3(column0_MVM, column1_MVM, column2_MVM);
    
    reflection              =   reflect(normalize(position_PASS.xyz), normalize(modelViewMatrix_PASS * bakedNormals.xyz));
    
    envColor                =   vec3(textureCube(EnvMap, reflection.xyz)) * 1.0;
    //__CUBEMAP__=====================================================================================
    

    
    
    
    highp vec4 color_A      =   highp vec4(1.0, 0.0, 1.0, 1.0) * nDotL0 * f_0 ;
    
    highp vec4 color_B      =   highp vec4(1.0, 0.2, 0.0, 1.0) * nDotL0 * nDotL0 * f_1;
    
    highp vec4 color_C      =   highp vec4(1.0, 0.7, 0.0, 1.0) * nDotL0 * nDotL0 * nDotL0 * f_2;
    
    highp vec4 color_D      =   highp vec4(1.0, 1.0, 1.0, 1.0) * nDotL0 * f_5 +  pow(nDotL0, f_4);
    
    finalColor_A            =   ((color_A  +  color_B  + color_C + highp vec4(envColor, 1.0) + color_D) * f_3);
    
    gl_FragColor            =   finalColor_A + causticsWater * causticsWaterColor * pow(nDotL0, 6.9) * 8.2 * finalColor_A;
    
    
    
    gl_FragColor            =    highp vec4(  exp2(nDotL0-1.0)  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    //gl_FragColor            =    highp vec4(  nDotL0  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    
    gl_FragColor            =  highp vec4(pow(nDotL0, 0.4545455))  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA;
    
    
    
    
    
}

















