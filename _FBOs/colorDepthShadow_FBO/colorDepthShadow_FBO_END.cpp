//-----------------------------------------------------------------
if(colorDepthShadows_UMBRA_FBO != 0)
{
    glDeleteFramebuffers(1, &colorDepthShadows_UMBRA_FBO);
    colorDepthShadows_UMBRA_FBO = 0;
}
//-----------------------------------------------------------------
if(colorDepthShadows_UMBRA_FBO_COLOR_TEXTURE  != 0)
{
    glDeleteTextures(1, &colorDepthShadows_UMBRA_FBO_COLOR_TEXTURE);
    colorDepthShadows_UMBRA_FBO_COLOR_TEXTURE  = 0;
}
//-----------------------------------------------------------------
if(colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE != 0)
{
    glDeleteTextures(1, &colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE);
    colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE = 0;
}
//-----------------------------------------------------------------

//-----------------------------------------------------------------
if(colorDepthShadows_PENUMBRA_FBO != 0)
{
    glDeleteFramebuffers(1, &colorDepthShadows_PENUMBRA_FBO);
    colorDepthShadows_PENUMBRA_FBO = 0;
}
//-----------------------------------------------------------------
if(colorDepthShadows_PENUMBRA_FBO_COLOR_TEXTURE  != 0)
{
    glDeleteTextures(1, &colorDepthShadows_PENUMBRA_FBO_COLOR_TEXTURE);
    colorDepthShadows_PENUMBRA_FBO_COLOR_TEXTURE  = 0;
}
//-----------------------------------------------------------------
if(colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE != 0)
{
    glDeleteTextures(1, &colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);
    colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE = 0;
}
//-----------------------------------------------------------------
