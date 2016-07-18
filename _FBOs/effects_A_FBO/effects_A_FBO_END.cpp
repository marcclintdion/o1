//-----------------------------------------------------------------
if(effects_A_FBO != 0)
{
    glDeleteFramebuffers(1, &effects_A_FBO);
    effects_A_FBO = 0;
}
//-----------------------------------------------------------------
if(effects_A_FBO_COLOR_TEXTURE  != 0)
{
    glDeleteTextures(1, &effects_A_FBO_COLOR_TEXTURE);
    effects_A_FBO_COLOR_TEXTURE  = 0;
}
//-----------------------------------------------------------------
if(effects_A_FBO_DEPTH_TEXTURE != 0)
{
    glDeleteTextures(1, &effects_A_FBO_DEPTH_TEXTURE);
    effects_A_FBO_DEPTH_TEXTURE = 0;
}
//-----------------------------------------------------------------
