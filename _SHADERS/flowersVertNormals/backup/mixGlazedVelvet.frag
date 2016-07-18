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

uniform     highp   vec4    light0_POS;

varying     highp   vec3    lightPos0_PASS;
varying     highp   vec3    lightPos1_PASS;

            highp   vec3    lightPos0_Normalized;
            highp   vec3    lightPos1_Normalized;


uniform     highp   float   noiseScale;

varying     highp   vec4    normal_PASS;
            highp   vec3    vertNormals;
varying     highp   vec3    vViewVec;



uniform     highp   float   f_0;
uniform     highp   float   f_1;

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


            highp   vec4    lightMixL0;
            highp   vec4    lightMixL1;

            highp vec4      color      = highp vec4(1.0, 0.5, 0.01, 1.0);
            highp vec4      gloss      = highp vec4(0.772549, 0.588109, 0.401132, 1.0);
            highp float     cosA, sinA, tanA;


varying     highp   vec2    uv0_PASS;


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


 
    highp float angle          =  .004 * exp2(nDotL0-1.0) * exp2(nDotL1-1.0) * Mask0Texture.g;

    
    sinA = sin(angle);
    cosA = cos(angle);
    tanA = tan(angle);
 
    highp vec3 tang =  tanA * highp vec3(bakedNormals.z, bakedNormals.y, bakedNormals.x) + sinA * vec3(bakedNormals.x, bakedNormals.y, bakedNormals.z) ;
    
    //========================================================================================================
        highp float cs = -dot(viewVec, tang);
        highp float sn = sqrt(1.0 - cs * cs) ;                                 // sqrt(1.0 - cs * cs) * NdotL1<-shiny with second specular halo
        highp float cl =  dot(oglLightDir.xyz, tang) * ColorTexture.x ;
        highp float sl = sqrt(1.0 - cl * cl);                                 // sqrt(1.0 - cs * cs) * NdotL1<-shiny with second specular halo
        highp float specular = (cs * cl + sn * sl) * exp2(nDotL0-1.0);

    
    lightMixL0              =    highp vec4(   exp2(nDotL0-1.0)  ) ;

    
    
    
    specular_RED            =    max(pow(nDotL1,  400.0  * Mask0Texture.r), 0.0);

    specular_GREEN          =    max(pow(nDotL1,  500.0  * Mask0Texture.r), 0.0);

    specular_BLUE           =    max(pow(nDotL1,  600.0  * Mask0Texture.r), 0.0);

    solarFlare              =    highp  vec4(specular_RED, specular_GREEN, specular_BLUE, 1.0);

    redColor                =    highp  vec4(4.0 , 0.0, 0.0, 1.0) * pow(nDotL1, 16.0 ) * 0.184800 + highp vec4(specular_RED, 0.0, 0.0, 1.0   ) * 2.377594 ;

    greenColor              =    highp  vec4(0.0, 4.0 , 0.0, 1.0) * pow(nDotL1, 32.0 ) * 0.184800 + highp vec4(0.0, specular_GREEN, 0.0, 1.0 ) * 2.377594 ;

    blueColor               =    highp  vec4(0.0, 0.0, 4.0 , 1.0) * pow(nDotL1, 64.0 ) * 0.184800 + highp vec4(0.0, 0.0, specular_BLUE, 1.0  ) * 2.377594 ;

    combineSpecular         =    (highp  vec4(0.1, 0.32, 0.4, 1.0) * 0.168 + (redColor + greenColor + blueColor)) * Mask0Texture.r;

    ColorMix                =    ColorTexture * (mix(ColorTexture, lightMixL0 + (combineSpecular + solarFlare) * Mask0Texture.r   , exp2(nDotL0 - 1.0) )) ;


    gl_FragColor            =    mix(ColorTexture * gloss * specular, ColorMix, Mask0Texture.g);

    
    
   // gl_FragColor            =    vec4( nDotL1 );

}





