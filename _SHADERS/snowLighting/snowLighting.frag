 #ifdef GL_ES                                                                                                                                              
 #else                                                                                                                                                     
 #define highp                                                                                                                                             
 #endif                                                                                                                                                    

uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;
uniform     highp   float   f_4;
uniform     highp   float   f_5;


uniform     sampler2D       ColorMAP;
            highp   vec4    colorTexture;
            highp   vec4    ColorMix;

varying     highp   vec3    vertexNormals_0;
varying     highp   vec3    vertexNormals_1;
            highp   vec3    normal_VERT;

uniform     sampler2D       NormalMAP;
            highp   vec4    bakedNormals;

            highp   float   VnDotL0;
            highp   float   VnDotL1;

            highp   float   nDotL0;
            highp   float   nDotL1;

            highp   float   snowLight_A;
            highp   float   snowLight_B;
            highp   float   snowLightShadow_A;
            highp   float   snowLightShadow_B;
            highp   float   mixSnowLight;
            highp   float   mixSnowLightShadow;
uniform     highp   float   mixVertexAndBakedNormals;

uniform     highp   vec4    light0_POS;

varying     highp   vec3    VlightPos0_PASS;
varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

uniform     sampler2D       Mask0MAP;
            highp   vec4    mask0Texture;


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

varying     highp   vec4    projectionTexcoord;
uniform     sampler2D       caustics_WATERMAP;
            highp   vec4    causticsWater;

varying     highp   vec2    uv0_PASS_MIX;
varying     highp   vec2    uv0_PASS_ORIGINAL;

varying     highp   vec2    uv0_ATLAS_BL;
varying     highp   vec2    uv0_ATLAS_BR;
varying     highp   vec2    uv0_ATLAS_TL;
varying     highp   vec2    uv0_ATLAS_TR;
varying     highp   float   wave_1_UV_ATLAS;
varying     highp   float   wave_2_UV_ATLAS;

            highp   vec4    domeTreeAtlas_1;
            highp   vec4    domeTreeAtlas_2;
            highp   vec4    domeTreeAtlas_3;
            highp   vec4    domeTreeAtlas_4;

            highp   vec4    domeTreeAtlas_MIX_1;
            highp   vec4    domeTreeAtlas_MIX_2;
            highp   vec4    domeTreeAtlas_MIX_3;


            highp   vec4    finalColor_FILTER;

uniform     highp   float   UVmap_SWITCH_1;


void main()
{
    
    
    
    
    compare_UMBRA           =   (shadowTexcoord.z / shadowTexcoord.w) - shadowBias_UMBRA;
    depth_UMBRA             =   texture2DProj(ShadowMAP_UMBRA,  shadowTexcoord).r;
    shadowVal_UMBRA         =   compare_UMBRA <= depth_UMBRA ? 1.0 : 0.60;

    compare_PENUMBRA        =   (shadowTexcoord.z / shadowTexcoord.w) - shadowBias_PENUMBRA;
    depth_PENUMBRA          =   texture2DProj(ShadowMAP_PENUMBRA,  shadowTexcoord).r;
    shadowVal_PENUMBRA      =   compare_PENUMBRA <= depth_PENUMBRA ? 1.0 : 0.70;

    mask0Texture            =   texture2D(Mask0MAP, uv0_PASS_MIX);
    

    domeTreeAtlas_1         =   texture2D(ColorMAP,  uv0_ATLAS_BL.xy);
    domeTreeAtlas_2         =   texture2D(ColorMAP,  uv0_ATLAS_BR.xy);
    domeTreeAtlas_3         =   texture2D(ColorMAP,  uv0_ATLAS_TL.xy);
    domeTreeAtlas_4         =   texture2D(ColorMAP,  uv0_ATLAS_TR.xy);

    domeTreeAtlas_MIX_1     =   mix(domeTreeAtlas_4, domeTreeAtlas_2, wave_1_UV_ATLAS );

    domeTreeAtlas_MIX_2     =   mix(domeTreeAtlas_3, domeTreeAtlas_MIX_1, wave_2_UV_ATLAS );
    
    
    colorTexture            =   texture2D(ColorMAP,  uv0_PASS_MIX.xy);


    
    finalColor_FILTER       =   mix(colorTexture,  domeTreeAtlas_MIX_2,  UVmap_SWITCH_1);
 
    
    
    
    
    
    bakedNormals.xyz        =   texture2D(NormalMAP,  uv0_PASS_ORIGINAL.xy).xyz;
    bakedNormals.xyz        =   normalize(bakedNormals.xyz - 0.5);

    
    VnDotL0                 =   max(       dot(    normalize(vertexNormals_0.xyz), normalize(light0_POS.xyz)      )    , 0.0      )    ;
    VnDotL1                 =   max(       dot(    normalize(vertexNormals_1.xyz), normalize(highp vec3(0.0, 0.0, 1.0))      )    , 0.0      )    ;
    
    nDotL0                  =   max(dot(bakedNormals.xyz, normalize(lightPos0_PASS.xyz)), 0.0);
    nDotL1                  =   max(dot(bakedNormals.xyz, normalize(lightPos1_PASS.xyz)), 0.0);
    
    
    
    snowLight_A             =   pow(      mix( nDotL0, max( nDotL1 + 0.15, 0.0 ), 0.15 )  , 0.4545455      );
    snowLightShadow_A       =   snowLight_A * shadowVal_UMBRA * shadowVal_PENUMBRA;
    
    snowLight_B             =   pow(      mix( VnDotL0, max(  VnDotL1 + 0.15, 0.0 ), 0.15 )  , 0.4545455      );
    snowLightShadow_B       =   snowLight_B * shadowVal_UMBRA * shadowVal_PENUMBRA;
    
    mixSnowLight            =   mix(snowLight_A,        snowLight_B,        mixVertexAndBakedNormals);
    mixSnowLightShadow      =   mix(snowLightShadow_A,  snowLightShadow_B,  mixVertexAndBakedNormals);
    
    
   
    gl_FragColor            =   highp vec4(finalColor_FILTER) * mix(mixSnowLight,  mixSnowLightShadow,  pow( mix(nDotL0, VnDotL0, mixVertexAndBakedNormals), 0.4545455)  )
    
                            +   highp vec4(0.0)
    
                            ;
    
    
    
    
    
    
    gl_FragColor.a          =  mask0Texture.r;
    
     
  
}











/*uniform     samplerCube     CubeMAP;
 highp   vec4    environmentColor;
 highp   vec3    reflection;
 
 varying     highp   vec3    column0_MVM;
 varying     highp   vec3    column1_MVM;
 varying     highp   vec3    column2_MVM;
 varying     highp   vec4    position_PASS;
 
 highp   mat3 modelViewMatrix_PASS;
 */


/*
void main()
//----------
    modelViewMatrix_PASS[0] =   column0_MVM;
    modelViewMatrix_PASS[1] =   column1_MVM;
    modelViewMatrix_PASS[2] =   column2_MVM;
    reflection              =   reflect(        normalize(position_PASS).xyz, normalize(modelViewMatrix_PASS * bakedNormals.xyz).xyz        );
    environmentColor        =   textureCube(CubeMAP, reflection.xyz);
*/





