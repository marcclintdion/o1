/*
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
*/

LoadIdentity(modelMatrix);

//========================================================================================================
glUseProgram(effects_A_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);

    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_effects_A,             1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_MODELVIEW_MATRIX_effects_A,              1, 0,       modelViewMatrix);
    glUniformMatrix4fv(UNIFORM_VIEW_MATRIX_effects_A,                   1, 0,       viewMatrix);

    glUniformMatrix4fv(UNIFORM_MODEL_MATRIX_effects_A,                  1, 0,       modelMatrix);

    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_effects_A,         1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_effects_A,              1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_effects_A,             1, 0,       invertModelMatrix);

    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_effects_A,               1, 0,       tempMatrix_E);


    //---------
    glUniform4f(UNIFORM_LIGHT0_POSITION_effects_A,      effects_A_LIGHT0_POSITION[0],
                                                        effects_A_LIGHT0_POSITION[1],
                                                        effects_A_LIGHT0_POSITION[2],
                                                        effects_A_LIGHT0_POSITION[3]);
    //---------
/*    glUniform4f(UNIFORM_LIGHT0_POSITION_effects_A,    groupSceneLight_POSITIONITION[0] + effects_A_LIGHT0_POSITION[0],
                                                        groupSceneLight_POSITIONITION[1] + effects_A_LIGHT0_POSITION[1],
                                                        groupSceneLight_POSITIONITION[2] + effects_A_LIGHT0_POSITION[2],
                                                        groupSceneLight_POSITIONITION[3] + effects_A_LIGHT0_POSITION[3]);
*/
    //---------
    glUniform4f(UNIFORM_LIGHT1_POSITION_effects_A,      effects_A_LIGHT1_POSITION[0],
                                                        effects_A_LIGHT1_POSITION[1],
                                                        effects_A_LIGHT1_POSITION[2],
                                                        effects_A_LIGHT1_POSITION[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_effects_A,     shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_effects_A,  shadowBias_PENUMBRA);

    glUniform1f(UNIFORM_f_0_effects_A,                  f_0_effects_A);
    glUniform1f(UNIFORM_f_1_effects_A,                  f_1_effects_A);
    glUniform1f(UNIFORM_f_2_effects_A,                  f_2_effects_A);
    glUniform1f(UNIFORM_f_3_effects_A,                  f_3_effects_A);
    glUniform1f(UNIFORM_f_4_effects_A,                  f_4_effects_A);
    glUniform1f(UNIFORM_f_5_effects_A,                  f_5_effects_A);

    glUniform1f(UNIFORM_screenRatio_effects_A,          screenRatio);

    glUniform1f(UNIFORM_timeIncrement_effects_A,              timeIncrement_CAUSTICS_WATER);
    glUniform1f(UNIFORM_phaseShiftIncrement_effects_A,  phaseShiftIncrement_CAUSTICS_WATER);

    glUniform4f(UNIFORM_waves_A_POSITION,               waves_A_POSITION[0],
                                                        waves_A_POSITION[1],
                                                        waves_A_POSITION[2],
                                                        waves_A_POSITION[3]);

    glUniform4f(UNIFORM_waves_B_POSITION,               waves_B_POSITION[0],
                                                        waves_B_POSITION[1],
                                                        waves_B_POSITION[2],
                                                        waves_B_POSITION[3]);

    glUniform4f(UNIFORM_waves_C_POSITION,               waves_C_POSITION[0],
                                                        waves_C_POSITION[1],
                                                        waves_C_POSITION[2],
                                                        waves_C_POSITION[3]);

    glUniform4f(UNIFORM_waves_D_POSITION,               waves_D_POSITION[0],
                                                        waves_D_POSITION[1],
                                                        waves_D_POSITION[2],
                                                        waves_D_POSITION[3]);


    glUniform1f(UNIFORM_waves_A_SCALE,                  waves_A_SCALE);
    glUniform1f(UNIFORM_waves_B_SCALE,                  waves_B_SCALE);
    glUniform1f(UNIFORM_waves_C_SCALE,                  waves_C_SCALE);
    glUniform1f(UNIFORM_waves_D_SCALE,                  waves_D_SCALE);


    //---------

    glUniform1i(UNIFORM_EMIT_effects_A,                     0);
    glUniform1i(UNIFORM_DOT3_effects_A,                     1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_effects_A,         2);
    glUniform1i(UNIFORM_CUBEMAP_effects_A,                  3);
    glUniform1i(UNIFORM_MASK0_effects_A,                    4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_effects_A,      5);
    //---------










