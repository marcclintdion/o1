glGenFramebuffers(1, &colorDepthShadows_UMBRA_FBO);
    //----------------------------------------------------------------------------
    glGenTextures(1, &colorDepthShadows_UMBRA_FBO_COLOR_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, colorDepthShadows_UMBRA_FBO_COLOR_TEXTURE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (((GLsizei)viewWidth * shadow_SIZE_UMBRA_MULTIPLIER) / shadow_SIZE_UMBRA_DIVISOR),
                                            (((GLsizei)viewWidth * shadow_SIZE_UMBRA_MULTIPLIER) / shadow_SIZE_UMBRA_DIVISOR), 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
    glBindTexture(GL_TEXTURE_2D, 0);
    //----------------------------------------------------------------------------
    glGenTextures(1, &colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,  (((GLsizei)viewWidth * shadow_SIZE_UMBRA_MULTIPLIER) / shadow_SIZE_UMBRA_DIVISOR),
                                                        (((GLsizei)viewWidth * shadow_SIZE_UMBRA_MULTIPLIER) / shadow_SIZE_UMBRA_DIVISOR),  0, GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
    glBindTexture(GL_TEXTURE_2D, 0);
    //----------------------------------------------------------------------------
    glBindFramebuffer(GL_FRAMEBUFFER, colorDepthShadows_UMBRA_FBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorDepthShadows_UMBRA_FBO_COLOR_TEXTURE, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,  GL_TEXTURE_2D, colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE, 0);


glGenFramebuffers(1, &colorDepthShadows_PENUMBRA_FBO);
    //----------------------------------------------------------------------------
    glGenTextures(1, &colorDepthShadows_PENUMBRA_FBO_COLOR_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_COLOR_TEXTURE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (((GLsizei)viewWidth * shadow_SIZE_PENUMBRA_MULTIPLIER) / shadow_SIZE_PENUMBRA_DIVISOR),
                                            (((GLsizei)viewWidth * shadow_SIZE_PENUMBRA_MULTIPLIER) / shadow_SIZE_PENUMBRA_DIVISOR), 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
    glBindTexture(GL_TEXTURE_2D, 0);
    //----------------------------------------------------------------------------
    glGenTextures(1, &colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,  (((GLsizei)viewWidth * shadow_SIZE_PENUMBRA_MULTIPLIER) / shadow_SIZE_PENUMBRA_DIVISOR),
                                                        (((GLsizei)viewWidth * shadow_SIZE_PENUMBRA_MULTIPLIER) / shadow_SIZE_PENUMBRA_DIVISOR),  0, GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
    glBindTexture(GL_TEXTURE_2D, 0);        
    //----------------------------------------------------------------------------
    glBindFramebuffer(GL_FRAMEBUFFER, colorDepthShadows_PENUMBRA_FBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_COLOR_TEXTURE, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,  GL_TEXTURE_2D, colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE, 0);

