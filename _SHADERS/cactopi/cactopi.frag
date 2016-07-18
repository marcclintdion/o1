 #ifdef GL_ES                                                                                                                                              
 #else                                                                                                                                                     
 #define highp                                                                                                                                             
 #endif                                                                                                                                                    

varying     highp   vec2    uv0_PASS;

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
            highp   vec4    causticsWaterColor = highp vec4(0.5, 0.5, 1.0, 1.0);


varying     highp   vec3    lightPos0_PASS;

            highp   vec3    lightPos0_Normalized;

uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;





varying     highp   vec4    Vertex;
varying     highp   vec4    inverseEye;
varying     highp   vec3    invertView;
            highp   vec3    Reflect;
            highp   vec3    RH;
            highp   float   fresnel_R;

            highp   float   fresnelReflectance = 0.1;

varying     highp   vec4    VertexCubeMap;
varying     highp   vec3    wsI;
            highp   vec3    wsR;
            highp   vec3    envColor;

            highp   vec4    finalColor_A;
            highp   vec4    finalColor_B;
            highp   vec4    finalColor_C;


            highp   vec4    colorTone_DARK      =   highp   vec4(1.528, 0.8389, 0.6089, 1.0);
            highp   vec4    diffuseColor;

            highp   float   specular_RED ;
            highp   float   specular_GREEN;
            highp   float   specular_BLUE;
            highp   float   adjustSplotch;




void main()
{

    
    maskTexture             =   texture2D(Mask0MAP, uv0_PASS.xy);
   
    compare_UMBRA           =   (shadowTexcoord.z / shadowTexcoord.w) - shadowBias_UMBRA;
    depth_UMBRA             =   texture2DProj(ShadowMAP_UMBRA,  shadowTexcoord).r;
    shadowVal_UMBRA         =   compare_UMBRA <= depth_UMBRA ? 1.0 : 0.6;

    compare_PENUMBRA        =   (shadowTexcoord.z / shadowTexcoord.w) - shadowBias_PENUMBRA;
    depth_PENUMBRA          =   texture2DProj(ShadowMAP_PENUMBRA,  shadowTexcoord).r;
    shadowVal_PENUMBRA      =   compare_PENUMBRA <= depth_PENUMBRA ? 1.0 : 0.7;
    
    causticsWater           =   texture2DProj(caustics_WATERMAP, shadowTexcoord);
    causticsWater          +=   texture2DProj(caustics_WATERMAP, highp vec4((1.0-shadowTexcoord.x), shadowTexcoord.y, shadowTexcoord.z, shadowTexcoord.w ));
    
    colorTexture            =   texture2D(ColorMAP,   uv0_PASS.xy) * 1.0;
    
    bakedNormals            =   texture2D(NormalMAP,  uv0_PASS.xy).xyz;
    
    bakedNormals            =   normalize(bakedNormals - 0.5);
    lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);

    nDotL0                  =   max(dot(bakedNormals, lightPos0_Normalized), 0.0);
    

    
    gl_FragColor            =  colorTexture * exp2(nDotL0 - 1.0) * shadowVal_UMBRA * shadowVal_PENUMBRA + causticsWater * causticsWaterColor * pow(nDotL0, 6.92) * 8.2 * colorTexture;
    
    
    gl_FragColor            =    highp vec4(  exp2(nDotL0-1.0)  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
   
    
    //gl_FragColor            =    highp vec4(  nDotL0  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);gl_FragColor            =    highp vec4(  nDotL0  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA);
    
    
    gl_FragColor            =  highp vec4(pow(nDotL0, 0.4545455))  *  shadowVal_UMBRA  *  shadowVal_PENUMBRA;
    







}




















