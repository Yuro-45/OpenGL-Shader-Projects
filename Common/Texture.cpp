#include"Texture.h"
#include<iostream>
#include<stb image/stb_image.h>

GLuint loadTexture(const char* path, GLint filter)
{
	// Flips the image so it appears right side up (OpenGL reads images bottom to top)
	stbi_set_flip_vertically_on_load(true);
	int imgWidth, imgHeight, numColCh;
	unsigned char* bytes = stbi_load(path, &imgWidth, &imgHeight, &numColCh, 0);
	if (bytes == NULL)
	{
		std::cout << "Failed to load texture: " << path << std::endl;
		return 0;
	}

	// jpg has 3 color channels (RGB), png usually has 4 (RGBA)
	GLenum format = (numColCh == 4) ? GL_RGBA : GL_RGB;

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// rows of RGB images aren't always 4-byte aligned
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, format, imgWidth, imgHeight, 0, format, GL_UNSIGNED_BYTE, bytes);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(bytes);
	glBindTexture(GL_TEXTURE_2D, 0);
	return texture;
}
