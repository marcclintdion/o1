
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
glUseProgram(pearlPaint_A_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_pearlPaint_A,             1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_MODELVIEW_MATRIX_pearlPaint_A,              1, 0,       modelViewMatrix);
    glUniformMatrix4fv(UNIFORM_VIEW_MATRIX_pearlPaint_A,                   1, 0,       viewMatrix);

    glUniformMatrix4fv(UNIFORM_MODEL_MATRIX_pearlPaint_A,                  1, 0,       modelMatrix);

    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_pearlPaint_A,         1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_pearlPaint_A,              1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_pearlPaint_A,             1, 0,       invertModelMatrix);

    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_pearlPaint_A,               1, 0,       tempMatrix_E);


    //---------
    glUniform4f(UNIFORM_LIGHT0_POSITION_pearlPaint_A,    pearlPaint_A_LIGHT0_POSITION[0],
                                                    pearlPaint_A_LIGHT0_POSITION[1],
                                                    pearlPaint_A_LIGHT0_POSITION[2],
                                                    pearlPaint_A_LIGHT0_POSITION[3]);

    //---------
/*    glUniform4f(UNIFORM_LIGHT0_POSITION_pearlPaint_A,  groupSceneLight_POSITIONITION[0] + pearlPaint_A_LIGHT0_POSITION[0],
                                                    groupSceneLight_POSITIONITION[1] + pearlPaint_A_LIGHT0_POSITION[1],
                                                    groupSceneLight_POSITIONITION[2] + pearlPaint_A_LIGHT0_POSITION[2],
                                                    groupSceneLight_POSITIONITION[3] + pearlPaint_A_LIGHT0_POSITION[3]);
*/
    //---------
    glUniform4f(UNIFORM_LIGHT1_POSITION_pearlPaint_A,       pearlPaint_A_LIGHT1_POSITION[0],
                                                        pearlPaint_A_LIGHT1_POSITION[1],
                                                        pearlPaint_A_LIGHT1_POSITION[2],
                                                        pearlPaint_A_LIGHT1_POSITION[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_pearlPaint_A,         shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_pearlPaint_A,      shadowBias_PENUMBRA);


    glUniform1f(UNIFORM_f_0_pearlPaint_A,              f_0_pearlPaint_A);
    glUniform1f(UNIFORM_f_1_pearlPaint_A,              f_1_pearlPaint_A);
    glUniform1f(UNIFORM_f_2_pearlPaint_A,              f_2_pearlPaint_A);
    glUniform1f(UNIFORM_f_3_pearlPaint_A,              f_3_pearlPaint_A);
    glUniform1f(UNIFORM_f_4_pearlPaint_A,              f_4_pearlPaint_A);
    glUniform1f(UNIFORM_f_5_pearlPaint_A,              f_5_pearlPaint_A);

    glUniform1f(UNIFORM_timeIncrement_pearlPaint_A,    timeIncrement_BULDGE_pearlPaint_A);

    //---------

    glUniform1i(UNIFORM_EMIT_pearlPaint_A,                     0);
    glUniform1i(UNIFORM_DOT3_pearlPaint_A,                     1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_pearlPaint_A,         2);
    glUniform1i(UNIFORM_CUBEMAP_pearlPaint_A,                  3);
    glUniform1i(UNIFORM_MASK0_pearlPaint_A,                    4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_pearlPaint_A,      5);
    glUniform1i(UNIFORM_caustics_WATERMAP_pearlPaint_A,        6);









