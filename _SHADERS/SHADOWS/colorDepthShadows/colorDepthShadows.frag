 #ifdef GL_ES                                                                                                                                              
 #else                                                                                                                                                     
 #define highp                                                                                                                                             
 #endif                                                                                                                                                    

uniform sampler2D           ColorMAP;
            highp   vec4    ColorTexture;
            highp   vec4    ColorMix;

uniform sampler2D           NormalMAP;
            highp   vec4    bakedNormals;

            highp   float   nDotL0;
            highp   float   nDotL1;
            highp   float   nDotL2;

uniform sampler2D           Mask0MAP;
            highp   vec4    Mask0Texture;

varying     highp   vec2    uv0_PASS;

uniform     highp   vec4    light0_POS;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

            highp   vec3    lightPos0_Normalized;
            highp   vec3    lightPos1_Normalized;


varying     highp   vec4    normal_PASS;
varying     highp   vec3    vViewVec;
            highp   vec3    vertNormals;


uniform     highp   float   f_0;
uniform     highp   float   f_1;





void main()
{                                                                                                                                                                              

    vertNormals             =   normalize(normal_PASS.xyz);
    
    ColorTexture            =   texture2D(ColorMAP,  uv0_PASS.xy);

    bakedNormals            =   texture2D(NormalMAP,  uv0_PASS.xy);
    bakedNormals.xyz        =   normalize(bakedNormals.xyz - 0.5);

    lightPos0_Normalized    =   normalize(lightPos0_PASS.xyz);
    lightPos1_Normalized    =   normalize(lightPos1_PASS.xyz);

    nDotL0                  =   max(dot(bakedNormals.xyz, lightPos0_Normalized), 0.0);
    nDotL1                  =   max(dot(bakedNormals.xyz, lightPos1_Normalized), 0.0);

    
    Mask0Texture            =   texture2D(Mask0MAP,  uv0_PASS.xy);
    
    
    highp vec3 viewVec         =  normalize(vViewVec);
    highp vec3 oglLightDir     =  highp vec3(light0_POS.x, light0_POS.y, -light0_POS.z);


    gl_FragColor            =    highp vec4(  pow(gl_FragCoord.z, 100.0)  );
    
    
   // gl_FragColor            =    vec4( nDotL1 );

}





