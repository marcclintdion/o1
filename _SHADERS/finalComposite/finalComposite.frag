 #ifdef GL_ES                                                                                                                                        
 #else                                                                                                                                                
 #define highp                                                                                                                                       
 #endif                                                                                                                                            

    varying highp  vec2       vTexCoord;                                                                                                           

    uniform highp  sampler2D  Texture0;                                                                                                            
    uniform highp  sampler2D  Texture1;                                                                                                            


    void main()                                                                                                                                       
    {                                                                                                                                                 


       gl_FragColor           =       texture2D(Texture0, vTexCoord)     ;

//       gl_FragColor           =  vec4(texture2D(Texture0, vTexCoord));                                                                                


    }