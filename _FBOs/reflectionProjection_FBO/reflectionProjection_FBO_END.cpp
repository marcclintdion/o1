//-----------------------------------------------------------------
if(reflectionProjection_FBO != 0)
{
    glDeleteFramebuffers(1, &reflectionProjection_FBO);
    reflectionProjection_FBO = 0;
}
//-----------------------------------------------------------------
if(reflectionProjection_FBO_COLOR_TEXTURE  != 0)
{
    glDeleteTextures(1, &reflectionProjection_FBO_COLOR_TEXTURE);
    reflectionProjection_FBO_COLOR_TEXTURE  = 0;
}
//-----------------------------------------------------------------
if(reflectionProjection_FBO_DEPTH_TEXTURE != 0)
{
    glDeleteTextures(1, &reflectionProjection_FBO_DEPTH_TEXTURE);
    reflectionProjection_FBO_DEPTH_TEXTURE = 0;
}
//-----------------------------------------------------------------
