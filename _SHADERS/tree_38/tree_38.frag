#ifdef GL_ES
#else
#define highp
#endif


varying     highp   vec2    uv0_PASS;

uniform     sampler2D       ColorMAP;
highp   vec4    colorTexture;
highp   vec4    ColorMix;

varying     highp   vec3    vertexNormals;
highp   vec3    normal_VERT;

uniform     sampler2D       NormalMAP;
highp   vec4    bakedNormals;

highp   float   nDotL0;
highp   float   nDotL1;
highp   float   VnDotL0;
highp   float   mixLightLinear;

uniform     highp   vec4    light0_POS;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

//highp   vec3    lightPos0_Normalized;
//highp   vec3    lightPos1_Normalized;

uniform     sampler2D       Mask0MAP;
highp   vec4    Mask0Texture;


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


uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;
uniform     highp   float   f_4;
uniform     highp   float   f_5;


highp   float   compareBothShadows;

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


highp   vec4    color      = highp vec4(1.0, 0.5, 0.01, 1.0);
highp   vec4    gloss      = highp vec4(0.772549, 0.588109, 0.401132, 1.0);
highp   float   cosA, sinA, tanA;

highp   vec3    viewVec;
highp   vec3    oglLightDir;

highp   float   angle;

highp   vec3    tang;

highp   float   cs;
highp   float   sn;
highp   float   cl;
highp   float   sl;
highp   float   specular;

highp   vec4    velvetWaves;


/*uniform     samplerCube     CubeMAP;
 highp   vec4    environmentColor;
 highp   vec3    reflection;
 
 varying     highp   vec3    column0_MVM;
 varying     highp   vec3    column1_MVM;
 varying     highp   vec3    column2_MVM;
 varying     highp   vec4    position_PASS;
 
 highp   mat3 modelViewMatrix_PASS;
 */

void main()
{
    /*
     modelViewMatrix_PASS[0] =   column0_MVM;
     modelViewMatrix_PASS[1] =   column1_MVM;
     modelViewMatrix_PASS[2] =   column2_MVM;
     reflection              =   reflect(        normalize(position_PASS).xyz, normalize(modelViewMatrix_PASS * bakedNormals.xyz).xyz        );
     environmentColor        =   textureCube(CubeMAP, reflection.xyz);
     */
    
    
    
    
    highp vec4 blurRadius1   =   highp vec4(0.02, 0.0,  0.0,  0.0);
    highp vec4 blurRadius2   =   highp vec4(0.0,  0.02, 0.0,  0.0);
    highp vec4 blurRadius3   =   highp vec4(0.0,  0.0,  0.02, 0.0);
    highp vec4 blurRadius4   =   highp vec4(0.0,  0.0,  0.0,  0.02);
    
    compare_UMBRA           =   (shadowTexcoord.z / shadowTexcoord.w) - shadowBias_UMBRA;
    
    depth_UMBRA             =   texture2DProj(ShadowMAP_UMBRA,  shadowTexcoord).r;
    shadowVal_UMBRA         +=   (compare_UMBRA <= depth_UMBRA ? 1.0 : 0.70) * 0.2;
    
    depth_UMBRA             =   texture2DProj(ShadowMAP_UMBRA,  shadowTexcoord + blurRadius1).r;
    shadowVal_UMBRA         +=   (compare_UMBRA <= depth_UMBRA ? 1.0 : 0.70) * 0.2;
    
    depth_UMBRA             =   texture2DProj(ShadowMAP_UMBRA,  shadowTexcoord + blurRadius2).r;
    shadowVal_UMBRA         +=   (compare_UMBRA <= depth_UMBRA ? 1.0 : 0.70) * 0.2;
    
    depth_UMBRA             =   texture2DProj(ShadowMAP_UMBRA,  shadowTexcoord + blurRadius3).r;
    shadowVal_UMBRA         +=   (compare_UMBRA <= depth_UMBRA ? 1.0 : 0.70) * 0.2;
    
    depth_UMBRA             =   texture2DProj(ShadowMAP_UMBRA,  shadowTexcoord + blurRadius4).r;
    shadowVal_UMBRA         +=   (compare_UMBRA <= depth_UMBRA ? 1.0 : 0.70) * 0.2;
    
    
    compare_PENUMBRA        =   (shadowTexcoord.z / shadowTexcoord.w) - shadowBias_PENUMBRA;
    
    depth_PENUMBRA          =   texture2DProj(ShadowMAP_PENUMBRA,  shadowTexcoord).r;
    shadowVal_PENUMBRA      +=   (compare_PENUMBRA <= depth_PENUMBRA ? 1.0 : 0.80) * 0.2;
    
    depth_PENUMBRA          =   texture2DProj(ShadowMAP_PENUMBRA,  shadowTexcoord + blurRadius1).r;
    shadowVal_PENUMBRA      +=   (compare_PENUMBRA <= depth_PENUMBRA ? 1.0 : 0.80) * 0.2;
    
    depth_PENUMBRA          =   texture2DProj(ShadowMAP_PENUMBRA,  shadowTexcoord + blurRadius2).r;
    shadowVal_PENUMBRA      +=   (compare_PENUMBRA <= depth_PENUMBRA ? 1.0 : 0.80) * 0.2;
    
    depth_PENUMBRA          =   texture2DProj(ShadowMAP_PENUMBRA,  shadowTexcoord + blurRadius3).r;
    shadowVal_PENUMBRA      +=   (compare_PENUMBRA <= depth_PENUMBRA ? 1.0 : 0.80) * 0.2;
    
    depth_PENUMBRA          =   texture2DProj(ShadowMAP_PENUMBRA,  shadowTexcoord + blurRadius4).r;
    shadowVal_PENUMBRA      +=   (compare_PENUMBRA <= depth_PENUMBRA ? 1.0 : 0.80) * 0.2;
    
    
    
    colorTexture            =   texture2D(ColorMAP,  uv0_PASS.xy) * 1.0;
    
    bakedNormals.xyz        =   texture2D(NormalMAP,  uv0_PASS.xy).xyz;
    bakedNormals.xyz        =   normalize(bakedNormals.xyz - 0.5);
    
    
    VnDotL0                 =   max(       dot(    normalize(vertexNormals.xyz), normalize(lightPos0_PASS)      )    , 0.0      )    ;
    
    nDotL0                  =   max(dot(bakedNormals.xyz, normalize(lightPos0_PASS.xyz)), 0.0);
    nDotL1                  =   max(dot(bakedNormals.xyz, normalize(lightPos1_PASS.xyz)), 0.0);
    
    
    mixLightLinear          =   pow(      mix( VnDotL0, max( mix((nDotL1 + 0.15), nDotL0, 0.5), 0.0 ), 0.85 )  , 0.4545455      );
    
    //mixLightLinear          =   mix(nDotL0, nDotL1, 0.5);
    
    
    gl_FragColor            =   1.0 * highp vec4(247.0/255.0) * shadowVal_UMBRA * shadowVal_PENUMBRA;
    
    //gl_FragColor            =   highp vec4(mixLightLinear) * shadowVal_UMBRA * shadowVal_PENUMBRA;
    
    gl_FragColor.a          =   colorTexture.a;
    
    
}
















