 #ifdef GL_ES                                                                                                                                              
 #else                                                                                                                                                     
 #define highp                                                                                                                                             
 #endif                                                                                                                                                    

uniform     sampler2D       ColorMAP;
            highp   vec4    colorTexture;
            highp   vec4    colorTex_DARK;

uniform     sampler2D       NormalMAP;
            highp   vec3    bakedNormals;
            highp   float   nDotL0;
            highp   float   nDotL1;
            highp   float   mixLightLinear;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

            highp   vec3    lightPos0_Normalized;
            highp   vec3    lightPos1_Normalized;

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

uniform     highp   float   animateAniso_AO_mask;

uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;
uniform     highp   float   f_4;
uniform     highp   float   f_5;


varying     highp   vec2    uv0_PASS;



varying     highp   vec4    Vertex;
varying     highp   vec4    inverseEye;
varying     highp   vec3    invertView;
            highp   vec3    Reflect;
            highp   vec3    RH;
            highp   float   fresnel_R;

            highp   float   fresnelReflectance = 0.1;


            highp   vec4    finalColor_A;
            highp   vec4    finalColor_B;
            highp   vec4    finalColor_C;
            highp   vec4    finalColor_D;

            highp   vec4    colorTone_DARK      =   highp   vec4(1.528, 0.8389, 0.6089, 1.0);
            highp   vec4    diffuseColor;

            highp   float   specular_RED ;
            highp   float   specular_GREEN;
            highp   float   specular_BLUE;
            highp   float   adjustSplotch;

uniform     samplerCube     EnvMap;

            highp   vec4    environmentColor;
            highp   vec3    reflection;

varying     highp   vec3    column0_MVM;
varying     highp   vec3    column1_MVM;
varying     highp   vec3    column2_MVM;
varying     highp   vec4    position_PASS;

            highp   mat3 modelViewMatrix_PASS;

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
    
    maskTexture             =   texture2D(Mask0MAP,  uv0_PASS.xy);
    
    
    colorTexture            =   texture2D(ColorMAP,  uv0_PASS.xy);
    
    bakedNormals.xyz        =   texture2D(NormalMAP,  uv0_PASS.xy).xyz;
    bakedNormals.xyz        =   normalize(bakedNormals.xyz - 0.5);
    
    lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);
    lightPos1_Normalized    =   normalize(lightPos1_PASS.xyz);

    nDotL0                  =   max(dot(bakedNormals.xyz, lightPos0_Normalized.xyz), 0.0);
    nDotL1                  =   max(dot(bakedNormals.xyz, lightPos1_Normalized.xyz), 0.0);

    mixLightLinear          =   pow(mix( nDotL0, nDotL1, 0.1), 0.4545455);
    
    adjustSplotch           =   pow(maskTexture.r, f_2);
    
    specular_RED            =   pow(nDotL0   ,    f_0 * 0.900435 * adjustSplotch)   ;
    specular_GREEN          =   pow(nDotL0   ,    f_0 * 1.360475 * adjustSplotch)   ;
    specular_BLUE           =   pow(nDotL0   ,    f_0 * 2.120454 * adjustSplotch)   ;

    
   
    modelViewMatrix_PASS[0] =   column0_MVM;
    modelViewMatrix_PASS[1] =   column1_MVM;
    modelViewMatrix_PASS[2] =   column2_MVM;
    reflection              =   reflect(        normalize(position_PASS).xyz, normalize(modelViewMatrix_PASS * bakedNormals.xyz).xyz        );
    environmentColor        =   textureCube(EnvMap, reflection.xyz);
    
   
    
    
    
    
    finalColor_A            =   highp vec4(colorTexture)    * maskTexture.g * mixLightLinear * .5  * pow(maskTexture.r,  f_1);
    
    
    finalColor_B            =   colorTone_DARK              * maskTexture.g * mixLightLinear * .5  * pow(maskTexture.r,  f_1);
    

    finalColor_C            =   highp vec4(environmentColor.xyz, 1.0) * 2.0  ;    //_ENVIRONMENT
   

    
    
    gl_FragColor            =  (finalColor_B  + finalColor_A  + finalColor_C * max(pow(nDotL0,    5.5), 0.0) * f_3
    
                            +   highp vec4(specular_RED, specular_GREEN, specular_BLUE, 1.0) * 4.0  * pow(maskTexture.b,  4.0))
    
                            *   shadowVal_UMBRA * shadowVal_PENUMBRA
    
                            +   causticsWater * highp vec4(0.5, 0.5, 1.0, 1.0) * pow(mixLightLinear, 6.9) * 6.2 * colorTexture * pow(maskTexture.r,  0.230001)
    ;
    

    //gl_FragColor            =    highp vec4(  exp2(nDotL0-1.0)  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    
   //gl_FragColor            =    highp vec4(  nDotL0  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    
    gl_FragColor            =  highp vec4(mixLightLinear)  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA;
    


}

















