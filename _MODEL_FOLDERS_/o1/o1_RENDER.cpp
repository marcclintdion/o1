    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, o1_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o1_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelMatrix); 
    Translate(modelMatrix,  o1_POSITION[0],
                           o1_POSITION[1], 
                              o1_POSITION[2]); 
    Rotate(modelMatrix,     o1_ROTATION[0],
                           o1_ROTATION[1], 
                              o1_ROTATION[2], 
                                o1_ROTATION[3]); 
    Scale(modelMatrix,  o1_SCALE[0],
                              o1_SCALE[1], 
                                 o1_SCALE[2] * reflection); 
    //=============================
    LoadIdentity(invertModelMatrix); 
    InvertMatrix(invertModelMatrix, modelMatrix);
//===================================================   
SelectShader(shaderNumber); 
//===================================================   
    glActiveTexture ( GL_TEXTURE0 );  
    glBindTexture(GL_TEXTURE_2D, o1_EMIT); 
    glActiveTexture (GL_TEXTURE1);  
    glBindTexture(GL_TEXTURE_2D, o1_DOT3); 
    glActiveTexture (GL_TEXTURE2);  
    glBindTexture(GL_TEXTURE_2D, o1_SKY); 
    glActiveTexture (GL_TEXTURE3);  
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture[0]); 
    glActiveTexture (GL_TEXTURE4);  
    glBindTexture(GL_TEXTURE_2D, o1_MASK0); 
    //-----------------------------------------------------  
    glDrawElements(GL_TRIANGLES, o1_INDEX_COUNT, GL_UNSIGNED_INT, 0); 
