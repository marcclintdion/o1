

LoadIdentity(tempMatrix_A);
MultiplyMatrix(tempMatrix_A,    projectionMatrix,           viewMatrix  );
//--------------------------
LoadIdentity(tempMatrix_B);
MultiplyMatrix(tempMatrix_B,    tempMatrix_A,               modelMatrix  );

//==========================

LoadIdentity(invertModelMatrix);
InvertMatrix(invertModelMatrix, modelMatrix);

//----------

LoadIdentity(modelViewMatrix);
MultiplyMatrix(modelViewMatrix,    viewMatrix,         modelMatrix  );


LoadIdentity(invertModelViewMatrix);
InvertMatrix(invertModelViewMatrix, modelViewMatrix);

//----------



//==========================
LoadIdentity(tempMatrix_C);
MultiplyMatrix(tempMatrix_C,    textureSpaceMatrix, projectionMatrix);


LoadIdentity(tempMatrix_D);
MultiplyMatrix(tempMatrix_D,    tempMatrix_C,       viewShadowMatrix);


LoadIdentity(tempMatrix_E);
MultiplyMatrix(tempMatrix_E,    tempMatrix_D,       modelMatrix);



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
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_mixGlazedVelvet,               1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_mixGlazedVelvet,                1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_mixGlazedVelvet,               1, 0,       invertModelMatrix);
    glUniformMatrix4fv(UNIFORM_modelMatrix_mixGlazedVelvet,                     1, 0,       modelMatrix);
    glUniformMatrix4fv(UNIFORM_modelViewMatrix_mixGlazedVelvet,                 1, 0,       modelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_mixGlazedVelvet,           1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_mixGlazedVelvet,                 1, 0,       tempMatrix_E);
    glUniformMatrix4fv(UNIFORM_TEXTURE_SPACE_MATRIX_mixGlazedVelvet,            1, 0,       textureSpaceMatrix);


    //---------
    glUniform4f(UNIFORM_LIGHT0_POSITION_mixGlazedVelvet,                groupSceneLight_POSITION[0] + mixGlazedVelvet_LIGHT0_POSITION[0] + mixGlazedVelvet_adjustReflection_POSITION[0],
                                                                        groupSceneLight_POSITION[1] + mixGlazedVelvet_LIGHT0_POSITION[1] + mixGlazedVelvet_adjustReflection_POSITION[1],
                                                                        groupSceneLight_POSITION[2] + mixGlazedVelvet_LIGHT0_POSITION[2] + mixGlazedVelvet_adjustReflection_POSITION[2],
                                                                        groupSceneLight_POSITION[3] + mixGlazedVelvet_LIGHT0_POSITION[3] + mixGlazedVelvet_adjustReflection_POSITION[3]);

    //---------
    glUniform4f(UNIFORM_movingGlossyLight_POSITION_mixGlazedVelvet,     movingGlossyLight_POS[0],
                                                                        movingGlossyLight_POS[1],
                                                                        movingGlossyLight_POS[2],
                                                                        movingGlossyLight_POS[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_mixGlazedVelvet,         shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_mixGlazedVelvet,      shadowBias_PENUMBRA);


    glUniform1f(UNIFORM_f_0_mixGlazedVelvet,              f_0_mixGlazedVelvet);
    glUniform1f(UNIFORM_f_1_mixGlazedVelvet,              f_1_mixGlazedVelvet);
    glUniform1f(UNIFORM_f_2_mixGlazedVelvet,              f_2_mixGlazedVelvet);
    glUniform1f(UNIFORM_f_3_mixGlazedVelvet,              f_3_mixGlazedVelvet);
    glUniform1f(UNIFORM_f_4_mixGlazedVelvet,              f_4_mixGlazedVelvet);
    glUniform1f(UNIFORM_f_5_mixGlazedVelvet,              f_5_mixGlazedVelvet);



    //---------

    glUniform1i(UNIFORM_EMIT_mixGlazedVelvet,                       0);
    glUniform1i(UNIFORM_DOT3_mixGlazedVelvet,                       1);
    glUniform1i(UNIFORM_SKY_mixGlazedVelvet,                        2);
    glUniform1i(UNIFORM_CUBEMAP_mixGlazedVelvet,                    3);
    glUniform1i(UNIFORM_MASK0_mixGlazedVelvet,                      4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_mixGlazedVelvet,        5);
    glUniform1i(UNIFORM_caustics_WATERMAP_mixGlazedVelvet,          6);


//---------










