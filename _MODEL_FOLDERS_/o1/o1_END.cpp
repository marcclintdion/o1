    if(o1_EMIT  != 0)
    { 
        glDeleteTextures(1, &o1_EMIT); 
        o1_EMIT  = 0; 
    } 
    if(o1_DOT3 != 0) 
    { 
        glDeleteTextures(1, &o1_DOT3); 
        o1_DOT3 = 0; 
    } 
    if(o1_SKY  != 0)
    { 
        glDeleteTextures(1, &o1_SKY); 
        o1_SKY  = 0; 
    } 
    if(o1_MASK0  != 0)
    { 
        glDeleteTextures(1, &o1_MASK0); 
        o1_MASK0  = 0; 
    } 
    //-------------------------------------------------- 
    if(o1_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o1_VBO); 
        o1_VBO  = 0; 
    } 
    if(o1_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o1_INDICES_VBO); 
        o1_INDICES_VBO  = 0; 
    } 
