#ifndef UTILS_H

#include"3rd/include/GL/glew.h"
#include"3rd/include/simple_opengl_image/SOIL.h"
#include <iostream>
#include<vector>

static class Utils
{
public:
	static GLuint GenTexture(const char* path);
	static unsigned int LoadCubemap(std::vector<std::string> faces);
private:

};

#endif // !UTILS_H

