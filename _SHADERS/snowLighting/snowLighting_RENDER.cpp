

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
glUseProgram(snowLighting_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_snowLighting,               1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_snowLighting,                1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_snowLighting,               1, 0,       invertModelMatrix);
    glUniformMatrix4fv(UNIFORM_modelMatrix_snowLighting,                     1, 0,       modelMatrix);
    glUniformMatrix4fv(UNIFORM_modelViewMatrix_snowLighting,                 1, 0,       modelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_snowLighting,           1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_snowLighting,                 1, 0,       tempMatrix_E);
    glUniformMatrix4fv(UNIFORM_TEXTURE_SPACE_MATRIX_snowLighting,            1, 0,       textureSpaceMatrix);


    //---------
    glUniform4f(UNIFORM_LIGHT0_POSITION_snowLighting,                groupSceneLight_POSITION[0] + snowLighting_LIGHT0_POSITION[0] + snowLighting_adjustReflection_POSITION[0],
                                                                        groupSceneLight_POSITION[1] + snowLighting_LIGHT0_POSITION[1] + snowLighting_adjustReflection_POSITION[1],
                                                                        groupSceneLight_POSITION[2] + snowLighting_LIGHT0_POSITION[2] + snowLighting_adjustReflection_POSITION[2],
                                                                        groupSceneLight_POSITION[3] + snowLighting_LIGHT0_POSITION[3] + snowLighting_adjustReflection_POSITION[3]);

    //---------
    glUniform4f(UNIFORM_movingGlossyLight_POSITION_snowLighting,     movingGlossyLight_POS[0],
                                                                        movingGlossyLight_POS[1],
                                                                        movingGlossyLight_POS[2],
                                                                        movingGlossyLight_POS[3]);

    glUniform1f(UNIFORM_shadowBias_UMBRA_snowLighting,              shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_snowLighting,           shadowBias_PENUMBRA);

    glUniform1f(UNIFORM_UVmap_SWITCH_1_snowLighting,                UVmap_SWITCH_1);

    glUniform1f(UNIFORM_f_0_snowLighting,                           f_0_snowLighting);
    glUniform1f(UNIFORM_f_1_snowLighting,                           f_1_snowLighting);
    glUniform1f(UNIFORM_f_2_snowLighting,                           f_2_snowLighting);
    glUniform1f(UNIFORM_f_3_snowLighting,                           f_3_snowLighting);
    glUniform1f(UNIFORM_f_4_snowLighting,                           f_4_snowLighting);
    glUniform1f(UNIFORM_f_5_snowLighting,                           f_5_snowLighting);

    glUniform1f(UNIFORM_mixVertexAndBakedNormals_snowLighting,      mixVertexAndBakedNormals_snowLighting);


    //---------

    glUniform1i(UNIFORM_EMIT_snowLighting,                       0);
    glUniform1i(UNIFORM_DOT3_snowLighting,                       1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_snowLighting,           2);
    glUniform1i(UNIFORM_CUBEMAP_snowLighting,                    3);
    glUniform1i(UNIFORM_MASK0_snowLighting,                      4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_snowLighting,        5);
    glUniform1i(UNIFORM_caustics_WATERMAP_snowLighting,          6);


//---------










