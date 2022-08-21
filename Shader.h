#pragma once
#include<gl/glew.h>
#include<string>
#include<gtc/matrix_transform.hpp>

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragPath, const char* geoPath = nullptr);
	inline	void use() const {
		glUseProgram(progrom);
	}
	inline	GLuint Program() const {
		return progrom;
	};

	void setVec3(const char* locName, const float x, const float y, const float z);
	void setVec2(const char* locName, const float x, const float y);
	void setVec3(const char* locName, glm::vec3 vector);
	void setFloat(const char* locName, const float val);
	void setInt(const char* locName, int val);
	void setMat4(const char* locName, glm::mat4 mat);

private:

	GLuint progrom;
	std::string getShaderCode(const char* filePath) const;
	GLuint complieShader(const char* shaderCode, const int shaderType, GLint& success, GLchar* infoLog);
};

