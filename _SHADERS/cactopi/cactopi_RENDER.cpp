
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
glUseProgram(cactopi_SHADER);
//----------

    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------



    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_cactopi,             1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_MODELVIEW_MATRIX_cactopi,              1, 0,       modelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_cactopi,         1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_cactopi,              1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_cactopi,             1, 0,       invertModelMatrix);

    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_cactopi,               1, 0,       tempMatrix_E);

    //---------
    glUniform4f(UNIFORM_LIGHT0_POS_cactopi,   groupSceneLight_POSITION[0] + cactopi_LIGHT0_POS[0],
                                                        groupSceneLight_POSITION[1] + cactopi_LIGHT0_POS[1],
                                                        groupSceneLight_POSITION[2] + cactopi_LIGHT0_POS[2],
                                                        groupSceneLight_POSITION[3] + cactopi_LIGHT0_POS[3]);

/*
    //---------
    glUniform4f(UNIFORM_LIGHT0_POS_cactopi,     cactopi_LIGHT0_POS[0],
                                                        cactopi_LIGHT0_POS[1],
                                                        cactopi_LIGHT0_POS[2],
                                                        cactopi_LIGHT0_POS[3]);

*/
    //---------
    glUniform4f(UNIFORM_LIGHT1_POS_cactopi,     cactopi_LIGHT1_POS[0],
                                                        cactopi_LIGHT1_POS[1],
                                                        cactopi_LIGHT1_POS[2],
                                                        cactopi_LIGHT1_POS[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_cactopi,         shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_cactopi,      shadowBias_PENUMBRA);

    glUniform1f(UNIFORM_f_0_cactopi,                    f_0_cactopi);
    glUniform1f(UNIFORM_f_1_cactopi,                    f_1_cactopi);
    glUniform1f(UNIFORM_f_2_cactopi,                    f_2_cactopi);
    glUniform1f(UNIFORM_f_3_cactopi,                    f_3_cactopi);


    //---------

    glUniform1i(UNIFORM_EMIT_cactopi,                       0);
    glUniform1i(UNIFORM_DOT3_cactopi,                       1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_cactopi,           2);
    glUniform1i(UNIFORM_CUBEMAP_cactopi,                    3);
    glUniform1i(UNIFORM_MASK0_cactopi,                      4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_cactopi,        5);
    glUniform1i(UNIFORM_caustics_WATERMAP_cactopi,          6);

    //---------














