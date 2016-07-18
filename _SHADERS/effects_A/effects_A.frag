#ifdef GL_ES
#else
#define highp
#endif

uniform     highp   float   timeIncrement;
uniform     highp   float   screenRatio;
uniform     highp   float   phaseShiftIncrement;

uniform     highp   float   f_0;
uniform     highp   float   f_1;
uniform     highp   float   f_2;
uniform     highp   float   f_3;
uniform     highp   float   f_4;
uniform     highp   float   f_5;



varying     highp   vec2    uv0_PASS;

varying     highp   vec4    vertexPosition;

            highp   vec4    color;

            highp   vec4    clipSpace;

uniform     highp   vec4    waves_A_POSITION;
uniform     highp   float   waves_A_SCALE;
            highp   vec4    waves_A_ADJUST;
            highp   float   waves_A;

uniform     highp   vec4    waves_B_POSITION;
uniform     highp   float   waves_B_SCALE;
            highp   vec4    waves_B_ADJUST;
            highp   float   waves_B;

uniform     highp   vec4    waves_C_POSITION;
uniform     highp   float   waves_C_SCALE;
            highp   vec4    waves_C_ADJUST;
            highp   float   waves_C;

uniform     highp   vec4    waves_D_POSITION;
uniform     highp   float   waves_D_SCALE;
            highp   vec4    waves_D_ADJUST;
            highp   float   waves_D;

            highp   float   addWaves;


void main()
{
    
    clipSpace               =   vertexPosition;
    clipSpace.x            *=   screenRatio * 1.653220;
    
    
    
    
    waves_A_ADJUST          =   (clipSpace * waves_A_SCALE) + waves_A_POSITION ;

    waves_A_ADJUST.x       +=   cos(waves_A_ADJUST.y * 0.004290 + timeIncrement * .2) * 100.0 * 2.820082;
    
    waves_A                 =   cos(        (pow(waves_A_ADJUST.x * waves_A_ADJUST.x + waves_A_ADJUST.y * waves_A_ADJUST.y,  0.290625) * 0.500000 ) * 0.964844          );
    
    
    
    waves_B_ADJUST          =   (clipSpace * waves_B_SCALE * 3.0) + waves_B_POSITION ;
    
    waves_B_ADJUST.x       +=   cos(waves_B_ADJUST.y * f_1 + timeIncrement * .3) * 80.0 * 2.820082;
    
    waves_B                 =   cos(        (pow(waves_B_ADJUST.x * waves_B_ADJUST.x + waves_B_ADJUST.y * waves_B_ADJUST.y,  0.290625) * 2.015000 - timeIncrement) * 0.395000          );
    
    
    
    waves_C_ADJUST          =   (clipSpace * waves_C_SCALE) + waves_C_POSITION ;
    
    waves_C_ADJUST.x       +=   cos(waves_C_ADJUST.y * f_2 + timeIncrement * .4  ) * 300.0 * 2.820082;
    
    waves_C                 =   cos(        (pow(waves_C_ADJUST.x * waves_C_ADJUST.x + waves_C_ADJUST.y * waves_C_ADJUST.y,  0.290625) * 0.689453 - timeIncrement) * 0.800781          ) ;
     
    
    
    addWaves                =   pow(    ((waves_A + waves_B + waves_C + 0.5) * 0.5),  f_0     )   ;     //3.546875
    
    
    gl_FragColor            =   highp vec4(1.0 - pow(addWaves, .15 * addWaves)) * f_5;
    
   
  
    
    //gl_FragColor           =  vec4(waves_C);
    
    
}

