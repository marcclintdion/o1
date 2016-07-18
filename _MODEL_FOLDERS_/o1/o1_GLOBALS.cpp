GLfloat o1_POSITION[]             = { 0.000000f, 0.000000f, 0.000000f, 1.0 }; 
GLfloat o1_ROTATION[]             = { 0.0, 0.0, 1.0, 0.0 }; 
GLfloat o1_SCALE[]                = { 1.000000f, 1.000000f, 1.000000f, 1.0 }; 
//--------------------------------------
GLuint o1_VBO; 
GLuint o1_INDICES_VBO; 
//--------------------------------------
GLuint o1_EMIT; 
GLuint o1_DOT3; 
GLuint o1_SKY; 

GLuint o1_MASK0; 

//---------------------------------------------
GLfloat o1_boundingBox[6]; 


//---------------------------------------------
GLuint o1_INDEX_COUNT;    


GLuint o1_modelNumber;    


void load_o1_VBO(void)           
{
    #include    "o1_VBO.cpp"           
    glGenBuffers(1,              &o1_VBO);    
    glBindBuffer(GL_ARRAY_BUFFER, o1_VBO);       
    glBufferData(GL_ARRAY_BUFFER, sizeof(o1), o1, GL_STATIC_DRAW);      
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}
void load_o1_INDICES(void)           
{
    #include    "o1_INDICES.cpp"           
    glGenBuffers(1,              &o1_INDICES_VBO);    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o1_INDICES_VBO);       
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(o1_INDICES), o1_INDICES, GL_STATIC_DRAW);      
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
