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
            highp   vec4    causticsColor = highp vec4(0.5, 0.5, 1.0, 1.0);

varying     highp   vec3    lightPos0_PASS;

            highp   vec3    lightPos0_Normalized;


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
            highp   vec3    reflectHalfAngle;
            highp   float   fresnel_R;
            highp   float   fresnelReflectance = 0.1;

varying     highp   vec4    VertexCubeMap;
varying     highp   vec3    wsI;
            highp   vec3    wsR;
            highp   vec3    envColor;

            highp   vec4    finalColor_A;
            highp   vec4    specColor_HIGH;



            highp   vec4    diffuseColor;
            highp   vec4    copperSpecA;
            highp   vec4    copperSpecB;
            highp   vec4    copperSpecC;
            highp   vec4    copperSpecD;


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
    bakedNormals            =   normalize(bakedNormals - 0.5);
    lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);

    nDotL0                  =   max(dot(bakedNormals, lightPos0_Normalized), 0.0);

    
    wsR                     =   reflect(normalize(inverseEye.xyz), normalize(bakedNormals.xyz));
    envColor                =   vec3(textureCube(EnvMap, wsR));
    
    //Reflect               =   reflect(invertView, bakedNormals.xyz);
    reflectHalfAngle        =   normalize(wsR + invertView); //this component is sensitive to ---> (Reflect +/- invertView)
    fresnel_R               =   pow(dot(reflectHalfAngle, invertView), 56.423126 ) ;
   
    
    diffuseColor            =   colorTexture * nDotL0 * maskTexture.r * 3.0;
    
    specColor_HIGH          =   vec4(    max(  pow(nDotL0, 512.0 * maskTexture.r * maskTexture.r * pow(maskTexture.g, 15.0)), 0.0  )    ) * vec4(1.0, 0.877921, 0.702192, 1.0) * 2.0 * pow(maskTexture.g, 60.0) ;
    
    copperSpecA             =   colorTexture * vec4(envColor, 1.0) - (1.0 -  maskTexture.g ) * 2.844343;
    
    copperSpecB             =   colorTexture * specColor_HIGH  * 3.6;

    copperSpecC             =   colorTexture * specColor_HIGH  * 3.6 + vec4(envColor, 1.0) * f_1;
    
    //copperSpecD             =   colorTexture * specColor_HIGH  * 3.6 + vec4(envColor, 1.0) * f_5;
    
    finalColor_A            =   mix(diffuseColor,  copperSpecA * 1.673991 + copperSpecB * f_2 + copperSpecC * f_3, pow(maskTexture.g, 15.0));
    
    gl_FragColor            =   (   mix(         vec4(.45, .7, .7, 1.0) * finalColor_A,   finalColor_A,        1.0-fresnel_R)      ) * shadowVal_UMBRA * shadowVal_PENUMBRA* f_5 + causticsWater * causticsColor * pow(nDotL0, 6.93) * 8.2 * colorTexture;
    
    
    gl_FragColor            =    highp vec4(  exp2(nDotL0-1.0)  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    
    //gl_FragColor            =    highp vec4(  nDotL0  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);

    
    
    gl_FragColor            =  highp vec4(pow(nDotL0, 0.4545455))  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA;
    



}

















