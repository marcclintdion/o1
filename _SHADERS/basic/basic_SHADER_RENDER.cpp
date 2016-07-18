

LoadIdentity(tempMatrix_A);
MultiplyMatrix(tempMatrix_A,                    projectionMatrix,         viewMoveMatrix  );
//--------------------------
LoadIdentity(tempMatrix_B);
MultiplyMatrix(tempMatrix_B,                    tempMatrix_A,         modelWorldMatrix  );




//========================================================================================================
glUseProgram(basic_SHADER);
//----------
    glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
    glEnableVertexAttribArray(2);
    //---------------------------
    glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_basic,          1, 0,       tempMatrix_B);
    glUniformMatrix4fv(UNIFORM_invertViewMatrix_basic,           1, 0,       invertViewMatrix);
    glUniformMatrix4fv(UNIFORM_invertModelMatrix_basic,          1, 0,       invertRotationMatrix);



    //----------------
    glUniform4f(UNIFORM_LIGHT0_POS_basic,       basic_LIGHT0_POS[0],
                                                basic_LIGHT0_POS[1],
                                                basic_LIGHT0_POS[2],
                                                basic_LIGHT0_POS[3]);


    //----------------
    glUniform4f(UNIFORM_movingGlossyLight_POS_basic,        movingGlossyLight_POS[0],
                                                            movingGlossyLight_POS[1],
                                                            movingGlossyLight_POS[2],
                                                            movingGlossyLight_POS[3]);

    glUniform1f(UNIFORM_f_0_basic,              f_0_basic);
    glUniform1f(UNIFORM_f_1_basic,              f_1_basic);
    //---------

    glUniform1i(UNIFORM_TEX_COLOR_basic,        0);
    glUniform1i(UNIFORM_TEX_DOT3_basic,         1);
    //shadow
    glUniform1i(UNIFORM_TEX_MASK0_basic,        3);
    //---------
















