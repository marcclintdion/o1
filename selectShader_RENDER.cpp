

void SelectShader(var shaderNumber)
{
    
    if(shaderNumber ==   10)
    {
        #include    "_SHADERS/finalComposite/finalComposite_SHADER_RENDER.cpp"
    }
    //-----------
    if(shaderNumber ==   11)
    {
        #include    "_SHADERS/SHADOWS/colorDepthShadows/colorDepthShadows_RENDER.cpp"
    }
    //-----------
    if(shaderNumber ==   17)
    {
        //#include    "_SHADERS/basic/basic_SHADER_RENDER.cpp"
    }
    //-----------
    if(shaderNumber ==   18)
    {
        #include    "_SHADERS/copperCorrode/copperCorrode_RENDER.cpp"
    }
    //-----------   
    if(shaderNumber ==   19)
    {
        #include    "_SHADERS/mixGlazedVelvet/mixGlazedVelvet_RENDER.cpp"
    }
    //-----------   
    if(shaderNumber ==   20)
    {
        #include    "_SHADERS/tree_38/tree_38_RENDER.cpp"
    }
    //-----------
    
    //-----------
    if(shaderNumber ==   21)
    {
        #include    "_SHADERS/copperCorrode_B/copperCorrode_B_RENDER.cpp"
    }
    //-----------
    if(shaderNumber ==   22)
    {
        #include    "_SHADERS/cactopi/cactopi_RENDER.cpp"
    }
    //-----------
    if(shaderNumber ==   23)
    {
        #include    "_SHADERS/bigLeaf_A_VINES/bigLeaf_A_VINES_RENDER.cpp"
    }
    //-----------
    if(shaderNumber ==   24)
    {
        #include    "_SHADERS/bigLeaf_A_SHADER/bigLeaf_A_SHADER_RENDER.cpp"
    }
    //-----------     
    if(shaderNumber ==   25)
    {
        #include    "_SHADERS/marbleReflection/marbleReflection_RENDER.cpp"
    }
    //-----------
    if(shaderNumber ==   26)
    {
        #include    "_SHADERS/pearlPaint_A/pearlPaint_A_RENDER.cpp"
    }
    //-----------
    if(shaderNumber ==   27)
    {
        #include    "_SHADERS/effects_A/effects_A_RENDER.cpp"
    }
    //-----------
    if(shaderNumber ==   28)
    {
        #include    "_SHADERS/snowLighting/snowLighting_RENDER.cpp"
    }

    if(shaderNumber ==   29)
    {
        #include    "_SHADERS/flowersVertNormals/flowersVertNormals_RENDER.cpp"
    }
    //-----------


}
