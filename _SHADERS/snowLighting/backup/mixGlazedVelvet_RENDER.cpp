

//--------------------------



LoadIdentity(tempMatrix_A);
MultiplyMatrix(tempMatrix_A,                    projectionMatrix,           viewMatrix  );

LoadIdentity(tempMatrix_B);
MultiplyMatrix(tempMatrix_B,                    tempMatrix_A,               modelMatrix  );



//========================================================================================================
glUseProgram(mixGlazedVelvet_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_mixGlazedVelvet,           1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_mixGlazedVelvet,           1, 0,        invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_mixGlazedVelvet,           1, 0,       invertModelMatrix);



    //----------------
    glUniform4f(UNIFORM_LIGHT0_POS_mixGlazedVelvet,         groupSceneLights[0] + mixGlazedVelvet_LIGHT0_POS[0],
                                                            groupSceneLights[1] + mixGlazedVelvet_LIGHT0_POS[1],
                                                            groupSceneLights[2] + mixGlazedVelvet_LIGHT0_POS[2],
                                                            groupSceneLights[3] + mixGlazedVelvet_LIGHT0_POS[3]);


    //----------------
    glUniform4f(UNIFORM_movingGlossyLight_POS_mixGlazedVelvet,  movingGlossyLight_POS[0],
                                                                movingGlossyLight_POS[1],
                                                                movingGlossyLight_POS[2],
                                                                movingGlossyLight_POS[3]);

    glUniform1f(UNIFORM_f_0_mixGlazedVelvet,              f_0_mixGlazedVelvet);
    glUniform1f(UNIFORM_f_1_mixGlazedVelvet,              f_1_mixGlazedVelvet);
    glUniform1f(UNIFORM_noiseScale_mixGlazedVelvet,       noiseScale_mixGlazedVelvet);
    //---------

    glUniform1i(UNIFORM_TEX_COLOR_mixGlazedVelvet,        0);
    glUniform1i(UNIFORM_TEX_DOT3_mixGlazedVelvet,         1);
    //shadow
    glUniform1i(UNIFORM_TEX_MASK0_mixGlazedVelvet,        3);
    //---------
















