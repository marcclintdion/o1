






//================================================
#include "../UI.cpp"
//--------------------
if(KEY_Z)
{
    if(CONSOLE_OUTPUT == true)
    {
        CONSOLE_OUTPUT = false;
    }
    else if(CONSOLE_OUTPUT == false)
    {
        CONSOLE_OUTPUT = true;
    }
    KEY_Z_IS_RESET = false;
}
//--------------------
if(KEY_UP)
{
    modelNumber             += 1;
}
if(KEY_DOWN)
{
    modelNumber             -= 1;
}

    if(CONSOLE_OUTPUT)
    {
    #ifdef __APPLE__
    NSLog(@"modelNumber      =  %i",   modelNumber);
    #endif
    }
//--------------------
if(KEY_RIGHT)
{
    cycleThroughShaders     += 1;
}
if(KEY_LEFT)
{
    cycleThroughShaders     -= 1;
}
    if(CONSOLE_OUTPUT)
    {
    #ifdef __APPLE__
    NSLog(@"cycleThroughShaders = %i", cycleThroughShaders);
    #endif
    }
//--------------------
/*if(KEY_RIGHT)
{
    clipAdjust += .11;
}
if(KEY_LEFT)
{
    clipAdjust -= .11;
}
 
    if(CONSOLE_OUTPUT)
    {
    #ifdef __APPLE__
    NSLog(@"clipAdjust      =  %f",    clipAdjust);
    #endif
    }
 */
//================================================


if(KEY_L)
{
    mixGlazedVelvet_LIGHT0_POSITION[0] += 1.011;
}
if(KEY_J)
{
    mixGlazedVelvet_LIGHT0_POSITION[0] -= 1.011;
}
if(KEY_I)
{
    mixGlazedVelvet_LIGHT0_POSITION[1] += 1.011;
}
if(KEY_K)
{
    mixGlazedVelvet_LIGHT0_POSITION[1] -= 1.011;
}
if(KEY_O)
{
    mixGlazedVelvet_LIGHT0_POSITION[2] += 1.011;
}
if(KEY_U)
{
    mixGlazedVelvet_LIGHT0_POSITION[2] -= 1.011;
}

    if(CONSOLE_OUTPUT)
    {
    #ifdef __APPLE__
    NSLog(@"mixVertexAndBakedNormals_snowLighting =  %f ",     mixVertexAndBakedNormals_snowLighting);
    NSLog(@"mixGlazedVelvet_LIGHT0_POSITION[] =  %f, %f, %f ",     mixGlazedVelvet_LIGHT0_POSITION[0],mixGlazedVelvet_LIGHT0_POSITION[1],mixGlazedVelvet_LIGHT0_POSITION[2]);
    #endif
    }


//========================================================================================
if (KEY_R)
{
 
   
    //===============================================================================
    #include "../_SHADERS/mixGlazedVelvet/mixGlazedVelvet_INIT.cpp"
    #include "../_SHADERS/tree_38/tree_38_INIT.cpp"    
    
    //===============================================================================
   
}


//===========================================

if(KEY_C)
{
    f_0_snowLighting += 0.0001142;
}
if(KEY_X)
{
    f_0_snowLighting -= 0.0001142;
}
if(KEY_B)
{
    f_1_snowLighting += 0.0500142;
}
if(KEY_V)
{
    f_1_snowLighting -= 0.0500142;
}
if(KEY_M)
{
    f_2_snowLighting += 0.500142;
}
if(KEY_N)
{
    f_2_snowLighting -= 0.500142;
}

if(KEY_H)
{
    shadowBias_PENUMBRA += .000001;
}
if(KEY_G)
{
    shadowBias_PENUMBRA -= .000001;
}

if(KEY_RIGHT)//THESE_TWO_KEYS_ARE_NOW_BOOLEAN
{
    renderTurntable = true;
}
if(KEY_LEFT)//THESE_TWO_KEYS_ARE_NOW_BOOLEAN
{
    renderTurntable = false;
}
if(KEY_DOT)
{
    f_5_snowLighting += 0.01042;
}
if(KEY_COMMA)
{
    f_5_snowLighting -= 0.01042;
}

    if(CONSOLE_OUTPUT)
    {
    #ifdef __APPLE__
    NSLog(@"-");
    NSLog(@"shadowBias_PENUMBRA =  %f", shadowBias_PENUMBRA);
    NSLog(@"f_1_snowLighting =  %f", f_1_snowLighting);
    NSLog(@"f_2_snowLighting =  %f", f_2_snowLighting);
    NSLog(@"f_3_snowLighting =  %f", f_3_snowLighting);
    NSLog(@"f_4_snowLighting =  %f", f_4_snowLighting);
    NSLog(@"f_5_snowLighting =  %f", f_5_snowLighting);
    #endif
    }


/*
//===========================================
if(KEY_M)
{
    shadowBias_UMBRA    += 0.00000100288;
}
if(KEY_N)
{
    shadowBias_UMBRA    -= 0.00000100288;
}
if(KEY_B)
{
    shadowBias_PENUMBRA += 0.00000100288;
}
if(KEY_V)
{
    shadowBias_PENUMBRA -= 0.00000100288;
}
 
    if(CONSOLE_OUTPUT)
    {
    #ifdef __APPLE__
    NSLog(@"shadowBias_UMBRA =  %f", shadowBias_UMBRA);
    NSLog(@"shadowBias_PENUMBRA =  %f", shadowBias_PENUMBRA);
    #endif
    }
*/




if(KEY_J)
{
    shadow_POSITION[0] -= 1.012;
}
if(KEY_L)
{
    shadow_POSITION[0] += 1.012;//__CONSIDER MOVING KEYBOARD CONTROLS TO UPPER HALF OF THIS FILE :)
}
if(KEY_K)
{
    shadow_POSITION[1] -= 1.012;
}
if(KEY_I)
{
    shadow_POSITION[1] += 1.012;
}
if(KEY_U)
{
    shadow_POSITION[2] -= 1.012;
}
if(KEY_O)
{
    shadow_POSITION[2] += 1.012;
}


if(KEY_N)
{
    groupSceneLight_RADIAN[0] -= 0.01256;
}
if(KEY_M)
{
    groupSceneLight_RADIAN[0] += 0.01256;
}
if(KEY_C)
{
    groupSceneLight_RADIAN[1] -= 0.01256;
}
if(KEY_V)
{
    groupSceneLight_RADIAN[1] += 0.01256;
}
 
    if(CONSOLE_OUTPUT)
    {
    #ifdef __APPLE__
    NSLog(@"shadow_POSITION[] =  %f, %f, %f ", shadow_POSITION[0],shadow_POSITION[1],shadow_POSITION[2] );
    NSLog(@"groupSceneLight_RADIAN[] =  %f, %f ",     groupSceneLight_RADIAN[0],groupSceneLight_RADIAN[1]);
    #endif
    }


//========================================================================================

/*
 if(KEY_B)
 {
 f_0_copperCorrode += 0.0112;
 }
 if(KEY_V)
 {
 f_0_copperCorrode -= 0.0112;
 }
    if(CONSOLE_OUTPUT)
    {
    #ifdef __APPLE__
    NSLog(@"f_0_copperCorrode =  %f", f_0_copperCorrode );
    #endif
    }
//========================================================================================
 
if(KEY_M)
{
    f_1_copperCorrode += 1.0112;
}
if(KEY_N)
{
    f_1_copperCorrode -= 1.0112;
}
    if(CONSOLE_OUTPUT)
    {
    #ifdef __APPLE__
    NSLog(@"f_1_copperCorrode =  %f", f_1_basic );
    #endif
    }
 //========================================================================================
 */



#ifdef WIN32
if(KEY_F8)
{
    ofstream outSettings("settings.cpp");
}
#endif


