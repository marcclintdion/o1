

//--------------------------



LoadIdentity(tempMatrix_B);
MultiplyMatrix(tempMatrix_B,                    projectionMatrix,           viewShadowMatrix  );


LoadIdentity(tempMatrix_C);
MultiplyMatrix(tempMatrix_C,                    tempMatrix_B,               modelMatrix  );



//========================================================================================================
glUseProgram(colorDepthShadows_SHADER);
//----------
glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
glEnableVertexAttribArray(0);
glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
glEnableVertexAttribArray(1);
glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
glEnableVertexAttribArray(2);
//---------------------------
glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_colorDepthShadows,         1, 0,           tempMatrix_C);
glUniformMatrix4fv(UNIFORM_invertViewMatrix_colorDepthShadows,          1, 0,           invertViewMatrix);
glUniformMatrix4fv(UNIFORM_invertModelMatrix_colorDepthShadows,         1, 0,           invertModelMatrix);



//----------------
glUniform4f(UNIFORM_LIGHT0_POS_colorDepthShadows,         colorDepthShadows_LIGHT0_POS[0],
            colorDepthShadows_LIGHT0_POS[1],
            colorDepthShadows_LIGHT0_POS[2],
            colorDepthShadows_LIGHT0_POS[3]);


//----------------
glUniform4f(UNIFORM_movingGlossyLight_POS_colorDepthShadows,  movingGlossyLight_POS[0],
            movingGlossyLight_POS[1],
            movingGlossyLight_POS[2],
            movingGlossyLight_POS[3]);

glUniform1f(UNIFORM_f_0_colorDepthShadows,              f_0_colorDepthShadows);
glUniform1f(UNIFORM_f_1_colorDepthShadows,              f_1_colorDepthShadows);
glUniform1f(UNIFORM_noiseScale_colorDepthShadows,       noiseScale_colorDepthShadows);
//---------

glUniform1i(UNIFORM_TEX_COLOR_colorDepthShadows,        0);
glUniform1i(UNIFORM_TEX_DOT3_colorDepthShadows,         1);
//shadow
glUniform1i(UNIFORM_TEX_MASK0_colorDepthShadows,        3);
//---------
















