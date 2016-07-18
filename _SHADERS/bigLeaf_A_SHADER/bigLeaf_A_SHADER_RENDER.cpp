

LoadIdentity(tempMatrix_A);
MultiplyMatrix(tempMatrix_A,    projectionMatrix,         viewMatrix  );
//--------------------------
LoadIdentity(tempMatrix_B);
MultiplyMatrix(tempMatrix_B,    tempMatrix_A,         modelMatrix  );



//==========================
LoadIdentity(tempMatrix_C);
MultiplyMatrix(tempMatrix_C,    textureSpaceMatrix, projectionMatrix);


LoadIdentity(tempMatrix_D);
MultiplyMatrix(tempMatrix_D,    tempMatrix_C,       viewShadowMatrix);


LoadIdentity(tempMatrix_E);
MultiplyMatrix(tempMatrix_E,    tempMatrix_D,       modelMatrix);



//========================================================================================================
glUseProgram(bigLeaf_A_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_bigLeaf_A_SHADER,             1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_bigLeaf_A_SHADER,              1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_bigLeaf_A_SHADER,             1, 0,       invertModelMatrix);

    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_bigLeaf_A_SHADER,               1, 0,       tempMatrix_E);


    //---------
    glUniform4f(UNIFORM_LIGHT0_POS_bigLeaf_A_SHADER,   groupSceneLight_POSITION[0] + bigLeaf_A_SHADER_LIGHT0_POS[0],
                                                    groupSceneLight_POSITION[1] + bigLeaf_A_SHADER_LIGHT0_POS[1],
                                                    groupSceneLight_POSITION[2] + bigLeaf_A_SHADER_LIGHT0_POS[2],
                                                    groupSceneLight_POSITION[3] + bigLeaf_A_SHADER_LIGHT0_POS[3]);


    //---------
    glUniform4f(UNIFORM_LIGHT1_POS_bigLeaf_A_SHADER,       bigLeaf_A_SHADER_LIGHT1_POS[0],
                                                        bigLeaf_A_SHADER_LIGHT1_POS[1],
                                                        bigLeaf_A_SHADER_LIGHT1_POS[2],
                                                        bigLeaf_A_SHADER_LIGHT1_POS[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_bigLeaf_A_SHADER,         shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_bigLeaf_A_SHADER,      shadowBias_PENUMBRA);


    glUniform1f(UNIFORM_f_0_bigLeaf_A_SHADER,              f_0_bigLeaf_A_SHADER);
    glUniform1f(UNIFORM_f_1_bigLeaf_A_SHADER,              f_1_bigLeaf_A_SHADER);
    glUniform1f(UNIFORM_f_2_bigLeaf_A_SHADER,              f_2_bigLeaf_A_SHADER);
    glUniform1f(UNIFORM_f_3_bigLeaf_A_SHADER,              f_3_bigLeaf_A_SHADER);

    //---------

    glUniform1i(UNIFORM_EMIT_bigLeaf_A_SHADER,                       0);
    glUniform1i(UNIFORM_DOT3_bigLeaf_A_SHADER,                       1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_bigLeaf_A_SHADER,           2);
    glUniform1i(UNIFORM_CUBEMAP_bigLeaf_A_SHADER,                    3);
    glUniform1i(UNIFORM_MASK0_bigLeaf_A_SHADER,                      4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_bigLeaf_A_SHADER,        5);
    glUniform1i(UNIFORM_caustics_WATERMAP_bigLeaf_A_SHADER,          6);












