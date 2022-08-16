#ifndef MESH_H
#define MESH_H

#include<gl/glew.h>
#include<glm.hpp>
#include<gtc/matrix_transform.hpp>
#include<string>
#include<vector>
#include"Shader.h"

using std::string;
using std::vector;
using glm::vec3;
using glm::vec2;

struct Vertex
{
	// Position
	glm::vec3 Position;
	// Normal
	glm::vec3 Normal;
	// TexCoords
	glm::vec2 TexCoords;
};

struct Texture
{
	GLuint id;
	string type;
	string path;
};


class Mesh
{
public:
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures) :
		vertices(vertices), indices(indices), textures(textures)
	{
		setUpMesh();
	};
	vector<Vertex>& Vertices() {
		return this->vertices;
	}

	vector<unsigned int>& Indices() {
		return this->indices;
	}

	vector<Texture>& Textures() {
		return this->textures;
	}

	void Draw(Shader& shader);

private:
	void setUpMesh();


private:
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	unsigned int VAO, objectVBO, EBO;

};

#endif // !MESH_H
