

LoadIdentity(tempMatrix_A);
MultiplyMatrix(tempMatrix_A,    projectionMatrix,         viewMatrix  );
//--------------------------
LoadIdentity(tempMatrix_B);
MultiplyMatrix(tempMatrix_B,    tempMatrix_A,         modelMatrix  );


LoadIdentity(invertModelMatrix);
InvertMatrix(invertModelMatrix, modelMatrix);

LoadIdentity(modelViewMatrix);
MultiplyMatrix(modelViewMatrix, viewMatrix, modelMatrix);

LoadIdentity(invertModelViewMatrix);
InvertMatrix(invertModelViewMatrix, modelViewMatrix);


//==========================
LoadIdentity(tempMatrix_C);
MultiplyMatrix(tempMatrix_C,    textureSpaceMatrix, projectionMatrix);


LoadIdentity(tempMatrix_D);
MultiplyMatrix(tempMatrix_D,    tempMatrix_C,       viewShadowMatrix);


LoadIdentity(tempMatrix_E);
MultiplyMatrix(tempMatrix_E,    tempMatrix_D,       modelMatrix);



//========================================================================================================
glUseProgram(marbleReflection_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------

    glUniformMatrix4fv(UNIFORM_TEXTURE_SPACE_MATRIX_marbleReflection,            1, 0,       textureSpaceMatrix);

    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_marbleReflection,               1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_marbleReflection,               1, 0,       invertModelMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_marbleReflection,           1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_marbleReflection,                1, 0,       invertViewMatrix);

    glUniformMatrix4fv(UNIFORM_modelViewMatrix_marbleReflection,                 1, 0,       modelViewMatrix);

    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_marbleReflection,                 1, 0,       tempMatrix_E);


    //---------
    glUniform4f(UNIFORM_LIGHT0_POSITION_marbleReflection,                groupSceneLight_POSITION[0] + marbleReflection_LIGHT0_POSITION[0],
                                                                        groupSceneLight_POSITION[1] + marbleReflection_LIGHT0_POSITION[1],
                                                                        groupSceneLight_POSITION[2] + marbleReflection_LIGHT0_POSITION[2],
                                                                        groupSceneLight_POSITION[3] + marbleReflection_LIGHT0_POSITION[3]);

    //---------
    glUniform4f(UNIFORM_movingGlossyLight_POSITION_marbleReflection,     movingGlossyLight_POS[0],
                                                                        movingGlossyLight_POS[1],
                                                                        movingGlossyLight_POS[2],
                                                                        movingGlossyLight_POS[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_marbleReflection,         shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_marbleReflection,      shadowBias_PENUMBRA);


    glUniform1f(UNIFORM_f_0_marbleReflection,              f_0_marbleReflection);
    glUniform1f(UNIFORM_f_1_marbleReflection,              f_1_marbleReflection);
    glUniform1f(UNIFORM_f_2_marbleReflection,              f_2_marbleReflection);
    glUniform1f(UNIFORM_f_3_marbleReflection,              f_3_marbleReflection);
    glUniform1f(UNIFORM_f_4_marbleReflection,              f_4_marbleReflection);



    //---------

    glUniform1i(UNIFORM_EMIT_marbleReflection,                          0);
    glUniform1i(UNIFORM_DOT3_marbleReflection,                          1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_marbleReflection,              2);
    glUniform1i(UNIFORM_REFLECTION_marbleReflection,                    3);
    glUniform1i(UNIFORM_MASK0_marbleReflection,                         4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_marbleReflection,           5);
    glUniform1i(UNIFORM_caustics_WATERMAP_marbleReflection,             6);








