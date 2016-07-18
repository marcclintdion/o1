
LoadIdentity(tempMatrix_A);
MultiplyMatrix(tempMatrix_A,    projectionMatrix,   viewMatrix  );
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

//==========================

LoadIdentity(tempMatrix_D);
MultiplyMatrix(tempMatrix_D,    viewMatrix,         modelMatrix  );//_<tempMatrix_D> is being reused


LoadIdentity(invertModelViewMatrix);
InvertMatrix(invertModelViewMatrix, tempMatrix_D);




//========================================================================================================
glUseProgram(domeTreeBranchTexture_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_domeTreeBranchTexture_SHADER,             1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_invertModelViewMatrix_domeTreeBranchTexture_SHADER,         1, 0,       invertModelViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_domeTreeBranchTexture_SHADER,              1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_domeTreeBranchTexture_SHADER,             1, 0,       invertModelMatrix);

    glUniformMatrix4fv(UNIFORM_ShadowMapMatrix_domeTreeBranchTexture_SHADER,               1, 0,       tempMatrix_E);


    //---------
    glUniform4f(UNIFORM_LIGHT0_POS_domeTreeBranchTexture_SHADER,    groupSceneLight_POSITION[0] + domeTreeBranchTexture_SHADER_LIGHT0_POS[0],
                                                                    groupSceneLight_POSITION[1] + domeTreeBranchTexture_SHADER_LIGHT0_POS[1],
                                                                    groupSceneLight_POSITION[2] + domeTreeBranchTexture_SHADER_LIGHT0_POS[2],
                                                                    groupSceneLight_POSITION[3] + domeTreeBranchTexture_SHADER_LIGHT0_POS[3]);


    //---------
    glUniform4f(UNIFORM_LIGHT1_POS_domeTreeBranchTexture_SHADER,    movingGlossyLight_POS[0],
                                                                    movingGlossyLight_POS[1],
                                                                    movingGlossyLight_POS[2],
                                                                    movingGlossyLight_POS[3]);

    glUniform4f(UNIFORM_position_MODEL_domeTreeBranchTexture_SHADER,    domeTree_4tex_POSITION[0],
                                                                        domeTree_4tex_POSITION[1],
                                                                        domeTree_4tex_POSITION[2],
                                                                        domeTree_4tex_POSITION[3]);



    glUniform1f(UNIFORM_shadowBias_UMBRA_domeTreeBranchTexture_SHADER,         shadowBias_UMBRA);
    glUniform1f(UNIFORM_shadowBias_PENUMBRA_domeTreeBranchTexture_SHADER,      shadowBias_PENUMBRA);


    glUniform2f(UNIFORM_adjusted_UV_IN_domeTreeBranchTexture_SHADER,   adjust_UVs[0] , adjust_UVs[1]);

    glUniform1f(UNIFORM_f_0_domeTreeBranchTexture_SHADER,              f_0_domeTreeBranchTexture_SHADER);
    glUniform1f(UNIFORM_f_1_domeTreeBranchTexture_SHADER,              f_1_domeTreeBranchTexture_SHADER);
    glUniform1f(UNIFORM_f_2_domeTreeBranchTexture_SHADER,              f_2_domeTreeBranchTexture_SHADER);
    glUniform1f(UNIFORM_f_3_domeTreeBranchTexture_SHADER,              f_3_domeTreeBranchTexture_SHADER);
    glUniform1f(UNIFORM_f_4_domeTreeBranchTexture_SHADER,              f_4_domeTreeBranchTexture_SHADER);

    //---------

    glUniform1i(UNIFORM_EMIT_domeTreeBranchTexture_SHADER,                     0);
    glUniform1i(UNIFORM_DOT3_domeTreeBranchTexture_SHADER,                     1);
    glUniform1i(UNIFORM_SHADOW_MAP_UMBRA_domeTreeBranchTexture_SHADER,         2);
    glUniform1i(UNIFORM_CUBEMAP_domeTreeBranchTexture_SHADER,                  3);
    glUniform1i(UNIFORM_MASK0_domeTreeBranchTexture_SHADER,                    4);
    glUniform1i(UNIFORM_SHADOW_MAP_PENUMBRA_domeTreeBranchTexture_SHADER,      5);
    glUniform1i(UNIFORM_caustics_WATERMAP_domeTreeBranchTexture_SHADER,        6);
    //---------








