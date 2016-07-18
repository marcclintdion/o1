

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
glUseProgram(flowersVertNormals_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_flowersVertNormals,               1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_flowersVertNormals,                1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_flowersVertNormals,               1, 0,       invertModelMatrix);
    glUniformMatrix4fv(UNIFORM_modelMatrix_flowersVertNormals,                     1, 0,       modelMatrix);
    glUniformMatrix4fv(UNIFORM_modelViewMatrix_flowersVertNormals,                 1, 0,       modelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_flowersVertNormals,           1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_flowersVertNormals,                 1, 0,       tempMatrix_E);
    glUniformMatrix4fv(UNIFORM_TEXTURE_SPACE_MATRIX_flowersVertNormals,            1, 0,       textureSpaceMatrix);


    //---------
    glUniform4f(UNIFORM_LIGHT0_POSITION_flowersVertNormals,                groupSceneLight_POSITION[0] + flowersVertNormals_LIGHT0_POSITION[0] + flowersVertNormals_adjustReflection_POSITION[0],
                                                                        groupSceneLight_POSITION[1] + flowersVertNormals_LIGHT0_POSITION[1] + flowersVertNormals_adjustReflection_POSITION[1],
                                                                        groupSceneLight_POSITION[2] + flowersVertNormals_LIGHT0_POSITION[2] + flowersVertNormals_adjustReflection_POSITION[2],
                                                                        groupSceneLight_POSITION[3] + flowersVertNormals_LIGHT0_POSITION[3] + flowersVertNormals_adjustReflection_POSITION[3]);

    //---------
    glUniform4f(UNIFORM_movingGlossyLight_POSITION_flowersVertNormals,     movingGlossyLight_POS[0],
                                                                        movingGlossyLight_POS[1],
                                                                        movingGlossyLight_POS[2],
                                                                        movingGlossyLight_POS[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_flowersVertNormals,         shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_flowersVertNormals,      shadowBias_PENUMBRA);


    glUniform1f(UNIFORM_f_0_flowersVertNormals,              f_0_flowersVertNormals);
    glUniform1f(UNIFORM_f_1_flowersVertNormals,              f_1_flowersVertNormals);
    glUniform1f(UNIFORM_f_2_flowersVertNormals,              f_2_flowersVertNormals);
    glUniform1f(UNIFORM_f_3_flowersVertNormals,              f_3_flowersVertNormals);
    glUniform1f(UNIFORM_f_4_flowersVertNormals,              f_4_flowersVertNormals);
    glUniform1f(UNIFORM_f_5_flowersVertNormals,              f_5_flowersVertNormals);



    //---------

    glUniform1i(UNIFORM_EMIT_flowersVertNormals,                       0);
    glUniform1i(UNIFORM_DOT3_flowersVertNormals,                       1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_flowersVertNormals,           2);
    glUniform1i(UNIFORM_CUBEMAP_flowersVertNormals,                    3);
    glUniform1i(UNIFORM_MASK0_flowersVertNormals,                      4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_flowersVertNormals,        5);
    glUniform1i(UNIFORM_caustics_WATERMAP_flowersVertNormals,          6);


//---------










