#ifndef MODEL_H
#define MODEL_H

#include<string>
#include<vector>
#include<iostream>
#include <SOIL.h>
#include"Shader.h"
#include"Mesh.h"
#include <Importer.hpp>
#include <scene.h>
#include <postprocess.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;


unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);

class Model
{
public:
	Model(const string& path, bool gamma = false) :gammaCorrection(gamma)
	{
		loadModel(path);
	};

	void Draw(Shader& shader)
	{
		for (unsigned int i = 0; i < meshes.size(); i++)
		{
			meshes[i].Draw(shader);
		}
	};

	vector<Mesh> meshes;
	vector<Texture> textures_loaded;
private:
	void loadModel(const string& path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

private:
	
	string directory;
	bool gammaCorrection;
};



#endif // !MODEL_H
