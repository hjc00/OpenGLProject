#include <iostream>
#include <SOIL.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include "Shader.h"
#include<glm.hpp>
#include<gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include"Camera.h"
#include"Model.h"
#include<filesystem>
#include"Window.h"
#include"RenderBox.h"
#include"RenderModel.h"
#include"Stencil.h"
#include"BlendTest.h"
#include"PostProcessingExample.h"
#include"Explode.h"

int main()
{
	Camera camera(
		glm::vec3(0.0f, 0.0f, 8.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		45.0f,
		0.05f,
		5.0f);
	//RenderBox::Render(camera);
	//RenderModel(camera);
	//RenderStencil(camera);
	//RenderBlendTest(camera);
	//RenderPostPrecessingExample(camera);
	RenderExplodeModel(camera);
	return 0;
}


