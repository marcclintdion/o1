
LoadIdentity(tempMatrix_A);
MultiplyMatrix(tempMatrix_A,       projectionMatrix,         viewMatrix  );
//--------------------------
LoadIdentity(tempMatrix_B);
MultiplyMatrix(tempMatrix_B,       tempMatrix_A,             modelMatrix  );
//==========================

//========================================================================== modelView/invertModelView
LoadIdentity(modelViewMatrix);
MultiplyMatrix(modelViewMatrix,    viewMatrix,               modelMatrix  );
//-----------
LoadIdentity(invertModelViewMatrix);
InvertMatrix(invertModelViewMatrix, modelViewMatrix);
//==========================================================================

//==========================
LoadIdentity(tempMatrix_C);
MultiplyMatrix(tempMatrix_C,    textureSpaceMatrix, projectionMatrix);


LoadIdentity(tempMatrix_D);
MultiplyMatrix(tempMatrix_D,    tempMatrix_C,       viewShadowMatrix);


LoadIdentity(tempMatrix_E);
MultiplyMatrix(tempMatrix_E,    tempMatrix_D,       modelMatrix);



//========================================================================================================
glUseProgram(copperCorrode_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_copperCorrode,             1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_MODELVIEW_MATRIX_copperCorrode,              1, 0,       modelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_copperCorrode,         1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_copperCorrode,              1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_copperCorrode,             1, 0,       invertModelMatrix);

    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_copperCorrode,               1, 0,       tempMatrix_E);


    //---------
    glUniform4f(UNIFORM_LIGHT0_POS_copperCorrode,   groupSceneLight_POSITION[0] + copperCorrode_LIGHT0_POS[0],
                                                    groupSceneLight_POSITION[1] + copperCorrode_LIGHT0_POS[1],
                                                    groupSceneLight_POSITION[2] + copperCorrode_LIGHT0_POS[2],
                                                    groupSceneLight_POSITION[3] + copperCorrode_LIGHT0_POS[3]);


    //---------
    glUniform4f(UNIFORM_LIGHT1_POS_copperCorrode,       copperCorrode_LIGHT1_POS[0],
                                                        copperCorrode_LIGHT1_POS[1],
                                                        copperCorrode_LIGHT1_POS[2],
                                                        copperCorrode_LIGHT1_POS[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_copperCorrode,         shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_copperCorrode,      shadowBias_PENUMBRA);


    glUniform1f(UNIFORM_f_0_copperCorrode,              f_0_copperCorrode);
    glUniform1f(UNIFORM_f_1_copperCorrode,              f_1_copperCorrode);
    glUniform1f(UNIFORM_f_2_copperCorrode,              f_2_copperCorrode);
    glUniform1f(UNIFORM_f_3_copperCorrode,              f_3_copperCorrode);
    glUniform1f(UNIFORM_f_4_copperCorrode,              f_4_copperCorrode);
    glUniform1f(UNIFORM_f_5_copperCorrode,              f_5_copperCorrode);

    //---------

    glUniform1i(UNIFORM_EMIT_copperCorrode,                     0);
    glUniform1i(UNIFORM_DOT3_copperCorrode,                     1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_copperCorrode,         2);
    glUniform1i(UNIFORM_CUBEMAP_copperCorrode,                  3);
    glUniform1i(UNIFORM_MASK0_copperCorrode,                    4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_copperCorrode,      5);
    glUniform1i(UNIFORM_caustics_WATERMAP_copperCorrode,        6);
    //---------










