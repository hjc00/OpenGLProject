#include"Window.h"
#include"RenderBox.h"
#include"Shader.h"

void RenderBox::Render(Camera& camera)
{
	//GLFWwindow* window = InitWindow();
	GLFWwindow* window = Window::InitWindow(1280, 960, camera);

	float vertices[] = {
		// positions          // normals           // texture coords
	  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
	   0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
	   0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	   0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	  -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
	  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

	  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
	   0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
	   0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	   0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	  -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
	  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

	  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	  -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	  -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	   0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	   0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	   0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	   0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	   0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	   0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
	   0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
	   0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	   0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	  -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
	  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

	  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
	   0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
	   0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	   0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	  -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
	  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	glm::vec3 pointLightPositions[] = {
	glm::vec3(0.7f,  0.2f,  2.0f),
	glm::vec3(2.3f, -3.3f, -4.0f),
	glm::vec3(-4.0f,  2.0f, -12.0f),
	glm::vec3(0.0f,  0.0f, -3.0f)
	};

	glm::vec3 objectPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

	GLuint VBO;
	glGenBuffers(1, &VBO);

	GLuint  objectVAO;
	glGenVertexArrays(1, &objectVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);  // 把OPEN GL当前的顶点缓冲对象绑定到VBO去,让open gl 当前操纵的顶点缓冲对象是声明的VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);  // 把vertices的顶点数组设置到VBO去
	glBindVertexArray(objectVAO);
	//position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);         // 激活layout为0的顶点属性
	//normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);	 // 激活layout为1的顶点属性
	//textcoords attribute 
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);	 // 激活layout为1的顶点属性
	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);  // 把OPEN GL当前的顶点缓冲对象绑定与VBO解绑

	GLuint lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);  // 把OPEN GL当前的顶点缓冲对象绑定与VBO解绑

	Shader objectShader("ShaderFile/object.vs", "ShaderFile/object.frag");
	Shader lightShader("ShaderFile/light.vs", "ShaderFile/light.frag");
	//Shader outlineShader("ShaderFile/)
	GLuint diffuseMap = Utils::GenTexture("container2.png");
	GLuint specularMap = Utils::GenTexture("container2_specular.png");
	GLuint emitMap = Utils::GenTexture("matrix.jpg");

	objectShader.use();
	objectShader.setInt("material.diffuse", 0);
	objectShader.setInt("material.specular", 1);


	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		Window::DoMovement();
		Window::CalFrame();
		// Render
		// Clear the colorbuffer
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		//// render object

		objectShader.use();
		objectShader.setFloat("material.shininess", 32.0f);
		objectShader.setVec3("viewPos", Window::camera.Position());

		// directional light
		objectShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
		objectShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
		objectShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
		objectShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
		// point light 1
		objectShader.setVec3("pointLights[0].position", pointLightPositions[0]);
		objectShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
		objectShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
		objectShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
		objectShader.setFloat("pointLights[0].constant", 1.0f);
		objectShader.setFloat("pointLights[0].linear", 0.09);
		objectShader.setFloat("pointLights[0].quadratic", 0.032);
		//// point light 2
		objectShader.setVec3("pointLights[1].position", pointLightPositions[1]);
		objectShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
		objectShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
		objectShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
		objectShader.setFloat("pointLights[1].constant", 1.0f);
		objectShader.setFloat("pointLights[1].linear", 0.09);
		objectShader.setFloat("pointLights[1].quadratic", 0.032);
		// point light 3
		objectShader.setVec3("pointLights[2].position", pointLightPositions[2]);
		objectShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
		objectShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
		objectShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
		objectShader.setFloat("pointLights[2].constant", 1.0f);
		objectShader.setFloat("pointLights[2].linear", 0.09);
		objectShader.setFloat("pointLights[2].quadratic", 0.032);
		// point light 4
		objectShader.setVec3("pointLights[3].position", pointLightPositions[3]);
		objectShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
		objectShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
		objectShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
		objectShader.setFloat("pointLights[3].constant", 1.0f);
		objectShader.setFloat("pointLights[3].linear", 0.09);
		objectShader.setFloat("pointLights[3].quadratic", 0.032);
		// spotLight
		objectShader.setVec3("spotLight.position", Window::camera.Position());
		objectShader.setVec3("spotLight.spotDir", Window::camera.Forward());
		objectShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
		objectShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
		objectShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
		objectShader.setFloat("spotLight.constant", 1.0f);
		objectShader.setFloat("spotLight.linear", 0.09);
		objectShader.setFloat("spotLight.quadratic", 0.032);
		objectShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
		objectShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

		glm::mat4 model = glm::mat4(1.0f);
		objectShader.setMat4("model", model);

		glm::mat4 view = Window::camera.GetViewMat4();
		objectShader.setMat4("view", view);

		glm::mat4 projection = glm::perspective<float>(glm::radians(Window::camera.Fov()), 1280 / 960, 0.1f, 100.0f);
		objectShader.setMat4("projection", projection);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, diffuseMap);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, specularMap);

		// 把opengl当前的顶点数据绑定到objectVAO，代表接下来opengl对顶点数据的操作是操作objectVAO
		glBindVertexArray(objectVAO);
		for (GLuint i = 0; i < 10; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			objectShader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glBindVertexArray(0);

		lightShader.use();
		lightShader.setMat4("projection", projection);
		lightShader.setMat4("view", view);

		// we now draw as many light bulbs as we have point lights.
		glBindVertexArray(lightVAO);
		for (unsigned int i = 0; i < 4; i++)
		{
			model = glm::mat4(1.0f);
			model = glm::translate(model, pointLightPositions[i]);
			model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
			lightShader.setMat4("model", model);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		// Swap the screen buffers
		glfwSwapBuffers(window);

	}
	glDeleteVertexArrays(1, &objectVAO);
	glDeleteVertexArrays(1, &lightVAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
}
