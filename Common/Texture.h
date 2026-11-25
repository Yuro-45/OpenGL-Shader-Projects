#ifndef TEXTURE_H
#define TEXTURE_H

#include<glad/glad.h>

// Loads an image file into a new texture and returns the texture's ID (0 on failure)
// filter: GL_LINEAR for smooth images, GL_NEAREST for pixel art
GLuint loadTexture(const char* path, GLint filter = GL_LINEAR);

#endif
