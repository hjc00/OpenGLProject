#include "Shader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <gtc/type_ptr.hpp>

Shader::Shader(const char *vertexPath, const char *fragPath, const char *geoPath)
{

	std::string vShaderCode = getShaderCode(vertexPath);
	std::string fShaderCode = getShaderCode(fragPath);
	std::string gShaderCode;
	if (geoPath != nullptr)
	{
		gShaderCode = getShaderCode(geoPath);
	}

	GLint success;		 // ������
	GLchar infoLog[512]; // ������־
	GLuint vertex = complieShader(vShaderCode.c_str(), GL_VERTEX_SHADER, success, infoLog);
	GLuint fragment = complieShader(fShaderCode.c_str(), GL_FRAGMENT_SHADER, success, infoLog);
	GLuint geometry = NULL;
	if (geoPath != nullptr)
	{
		geometry = complieShader(gShaderCode.c_str(), GL_GEOMETRY_SHADER, success, infoLog);
	}

	// Shader Program
	this->progrom = glCreateProgram();
	glAttachShader(this->progrom, vertex);
	glAttachShader(this->progrom, fragment);
	if (geoPath != NULL)
	{
		glAttachShader(this->progrom, geometry);
	}
	glLinkProgram(this->progrom);
	// Print linking errors if any
	glGetProgramiv(this->progrom, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->progrom, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
				  << infoLog << std::endl;
		std::cout << " shader is " << vertexPath << " " << fragPath << std::endl;
	}
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (geoPath != nullptr)
	{
		glDeleteShader(geometry);
	}
}

void Shader::setVec3(const char *locName, const float x, const float y, const float z)
{
	glUniform3f(glGetUniformLocation(this->progrom, locName), x, y, z);
}

void Shader::setVec2(const char *locName, const float x, const float y)
{
	glUniform2f(glGetUniformLocation(this->progrom, locName), x, y);
}

void Shader::setVec3(const char *locName, glm::vec3 vector)
{
	glUniform3f(glGetUniformLocation(this->progrom, locName), vector.x, vector.y, vector.z);
}

void Shader::setFloat(const char *locName, const float val)
{
	glUniform1f(glGetUniformLocation(this->progrom, locName), val);
}

void Shader::setInt(const char *locName, int val)
{
	glUniform1i(glGetUniformLocation(this->progrom, locName), val);
}

void Shader::setMat4(const char *locName, glm::mat4 mat)
{
	glUniformMatrix4fv(glGetUniformLocation(this->progrom, locName), 1, GL_FALSE, glm::value_ptr(mat));
}

std::string Shader::getShaderCode(const char *filePath) const
{
	std::ifstream shaderFile;
	std::string shaderCode;
	try
	{
		shaderFile.open(filePath);
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		shaderCode = shaderStream.str();
	}
	catch (const std::exception &)
	{
		std::cout << "shader file read failed! path: " << filePath << std::endl;
	}
	return shaderCode;
}

GLuint Shader::complieShader(const char *shaderCode, const int shaderType, GLint &success, GLchar *infoLog)
{

	GLuint shader;

	// Vertex Shader
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderCode, NULL);
	glCompileShader(shader);
	// Print compile errors if any
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "error:: compile shader failed...." << shaderType << infoLog << std::endl;
	}

	return shader;
}
