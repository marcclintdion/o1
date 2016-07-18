 GLuint     colorDepthShadows_UMBRA_FBO,
            colorDepthShadows_UMBRA_FBO_COLOR_TEXTURE,
            colorDepthShadows_UMBRA_FBO_DEPTH_TEXTURE;


 GLuint     colorDepthShadows_PENUMBRA_FBO,
            colorDepthShadows_PENUMBRA_FBO_COLOR_TEXTURE,
            colorDepthShadows_PENUMBRA_FBO_DEPTH_TEXTURE;

GLsizei     shadow_SIZE_MULTIPLIER;
GLsizei     shadow_SIZE_DIVISOR;

GLsizei     shadow_SIZE_UMBRA_MULTIPLIER        = 1;
GLsizei     shadow_SIZE_UMBRA_DIVISOR           = 1;

GLsizei     shadow_SIZE_PENUMBRA_MULTIPLIER     = 1;
GLsizei     shadow_SIZE_PENUMBRA_DIVISOR        = 1;


GLfloat     shadow_POSITION[]               =   { 0.0,  0.0,     -20.744026    };//_NEEDS_BIAS_ADJUSTMENT, BUT_IS_BETTER_FIT={ 0.000000, 3.036000, -62.744026 };
GLfloat     shadow_ROTATION[]               =   { 0.0,  0.0                     };//-56.58615,  36.866642
