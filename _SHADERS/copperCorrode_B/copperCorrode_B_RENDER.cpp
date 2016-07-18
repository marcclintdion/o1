
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

LoadIdentity(invertModelMatrix);
InvertMatrix(invertModelMatrix, modelMatrix);

//==========================================================================

//==========================
LoadIdentity(tempMatrix_C);
MultiplyMatrix(tempMatrix_C,    textureSpaceMatrix, projectionMatrix);


LoadIdentity(tempMatrix_D);
MultiplyMatrix(tempMatrix_D,    tempMatrix_C,       viewShadowMatrix);


LoadIdentity(tempMatrix_E);
MultiplyMatrix(tempMatrix_E,    tempMatrix_D,       modelMatrix);



//========================================================================================================
glUseProgram(copperCorrode_B_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_copperCorrode_B,             1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_MODELVIEW_MATRIX_copperCorrode_B,              1, 0,       modelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_copperCorrode_B,         1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_copperCorrode_B,              1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_copperCorrode_B,             1, 0,       invertModelMatrix);

    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_copperCorrode_B,               1, 0,       tempMatrix_E);

    //---------
    glUniform4f(UNIFORM_LIGHT0_POS_copperCorrode_B,     groupSceneLight_POSITION[0] + copperCorrode_B_LIGHT0_POS[0] + copperCorrode_B_adjustReflection_POSITION[0],
                                                        groupSceneLight_POSITION[1] + copperCorrode_B_LIGHT0_POS[1] + copperCorrode_B_adjustReflection_POSITION[1],
                                                        groupSceneLight_POSITION[2] + copperCorrode_B_LIGHT0_POS[2] + copperCorrode_B_adjustReflection_POSITION[2],
                                                        groupSceneLight_POSITION[3] + copperCorrode_B_LIGHT0_POS[3] + copperCorrode_B_adjustReflection_POSITION[3]);

/*
    //---------
    glUniform4f(UNIFORM_LIGHT0_POS_copperCorrode_B,     copperCorrode_B_LIGHT0_POS[0],
                                                        copperCorrode_B_LIGHT0_POS[1],
                                                        copperCorrode_B_LIGHT0_POS[2],
                                                        copperCorrode_B_LIGHT0_POS[3]);

*/
    //---------
    glUniform4f(UNIFORM_LIGHT1_POS_copperCorrode_B,     copperCorrode_B_LIGHT1_POS[0],
                                                        copperCorrode_B_LIGHT1_POS[1],
                                                        copperCorrode_B_LIGHT1_POS[2],
                                                        copperCorrode_B_LIGHT1_POS[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_copperCorrode_B,         shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_copperCorrode_B,      shadowBias_PENUMBRA);

    glUniform1f(UNIFORM_animateAniso_AO_mask_copperCorrode_B,   animateAniso_AO_mask_copperCorrode_B);

    glUniform1f(UNIFORM_f_0_copperCorrode_B,                    f_0_copperCorrode_B);
    glUniform1f(UNIFORM_f_1_copperCorrode_B,                    f_1_copperCorrode_B);
    glUniform1f(UNIFORM_f_2_copperCorrode_B,                    f_2_copperCorrode_B);
    glUniform1f(UNIFORM_f_3_copperCorrode_B,                    f_3_copperCorrode_B);
    glUniform1f(UNIFORM_f_4_copperCorrode_B,                    f_4_copperCorrode_B);
    glUniform1f(UNIFORM_f_5_copperCorrode_B,                    f_5_copperCorrode_B);

    //---------

    glUniform1i(UNIFORM_EMIT_copperCorrode_B,                     0);
    glUniform1i(UNIFORM_DOT3_copperCorrode_B,                     1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_copperCorrode_B,         2);
    glUniform1i(UNIFORM_CUBEMAP_copperCorrode_B,                  3);
    glUniform1i(UNIFORM_MASK0_copperCorrode_B,                    4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_copperCorrode_B,      5);
    glUniform1i(UNIFORM_caustics_WATERMAP_copperCorrode_B,              6);

    //---------













