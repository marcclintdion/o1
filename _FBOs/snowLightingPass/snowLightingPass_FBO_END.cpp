//-----------------------------------------------------------------
if(snowLightingPass_FBO != 0)
{
    glDeleteFramebuffers(1, &snowLightingPass_FBO);
    snowLightingPass_FBO = 0;
}
//-----------------------------------------------------------------
if(snowLightingPass_FBO_COLOR_TEXTURE  != 0)
{
    glDeleteTextures(1, &snowLightingPass_FBO_COLOR_TEXTURE);
    snowLightingPass_FBO_COLOR_TEXTURE  = 0;
}
//-----------------------------------------------------------------
if(snowLightingPass_FBO_DEPTH_TEXTURE != 0)
{
    glDeleteTextures(1, &snowLightingPass_FBO_DEPTH_TEXTURE);
    snowLightingPass_FBO_DEPTH_TEXTURE = 0;
}
//-----------------------------------------------------------------
