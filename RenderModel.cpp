
#include "RenderModel.h"
#include "Shader.h"
#include "Window.h"
#include <gtc/type_ptr.hpp>
#include "Model.h"
#include "Utils.h"

glm::mat4 GetLightSpaceTransform(glm::vec3 lightPos, GLfloat nearPlaneWidth, GLfloat zFar, GLfloat zNear)
{
	// 光源方向的projection
	glm::mat4 lightSpaceProj = glm::ortho(-nearPlaneWidth, nearPlaneWidth, -nearPlaneWidth, nearPlaneWidth, zNear, zFar);
	glm::mat4 lightSpaceView = glm::lookAt(lightPos, vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 lightSpaceTransform = lightSpaceProj * lightSpaceView;

	return lightSpaceTransform;
}

void RenderModel(Camera &camera)
{

	GLFWwindow *window = Window::InitWindow(1280, 960, camera);

	Shader modelShader("ShaderFile/model_loading.vs", "ShaderFile/model_loading.fs");
	Model ourModel("Models/nanosuit/nanosuit.obj");

	float skyboxVertices[] = {
		// positions
		-1.0f, 1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,

		-1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, 1.0f,

		-1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, -1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f};
	float cubeVertices[] = {
		// positions          // texture Coords
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f};
	float floorVertices[] = {
		// positions          // texture Coords
		5.0f, -0.5f, 5.0f,
		-5.0f, -0.5f, 5.0f,
		-5.0f, -0.5f, -5.0f,

		5.0f, -0.5f, 5.0f,
		-5.0f, -0.5f, -5.0f,
		5.0f, -0.5f, -5.0f};

	// cube VAO
	unsigned int cubeVAO, cubeVBO;
	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
	// skybox VAO
	unsigned int skyboxVAO, skyboxVBO;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

	unsigned int floorVAO, floorVBO;
	glGenVertexArrays(1, &floorVAO);
	glGenBuffers(1, &floorVBO);
	glBindVertexArray(floorVAO);
	glBindBuffer(GL_ARRAY_BUFFER, floorVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), &floorVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

	vector<std::string> faces{
		"Resources/skybox/right.jpg",
		"Resources/skybox/left.jpg",
		"Resources/skybox/top.jpg",
		"Resources/skybox/bottom.jpg",
		"Resources/skybox/front.jpg",
		"Resources/skybox/back.jpg"};

	unsigned int cubemapTexture = Utils::LoadCubemap(faces);
	GLuint cubeTexture = Utils::GenTexture("Resources/container2.png");

	Shader skyboxShader("ShaderFile/skybox.vs", "ShaderFile/skybox.frag");
	Shader unlitShader("ShaderFile/unlit_with_shadow.vs", "ShaderFile/unlit_with_shadow.fs");
	//Shader unlitShader("ShaderFile/unlit.vs", "ShaderFile/unlit.fs");
	//Shader simpleColorShader("ShaderFile/SimpleColor.vs", "ShaderFile/SimpleColor.fs");
	Shader simpleColorShader("ShaderFile/SimpleColorWithShadow.vs", "ShaderFile/SimpleColorWithShadow.fs");

	Shader shadowMapShader("ShaderFile/ShadowMap.vs", "ShaderFile/ShadowMap.fs");
	Shader debugShadowMapShader("ShaderFile/DebugDepth.vs", "ShaderFile/DebugDepth.fs");

	// 生成shadowmap
	const int shadowMapWidth = 1024, shadowMapHeight = 1024;
	GLuint shadowMap;
	glGenTextures(1, &shadowMap);
	glBindTexture(GL_TEXTURE_2D, shadowMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapWidth, shadowMapHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	//GLfloat borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
	//glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	unsigned int shadowMapFBO;
	glGenFramebuffers(1, &shadowMapFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glEnable(GL_DEPTH_TEST);
	skyboxShader.use();
	skyboxShader.setInt("skybox", 0);

	float quadVertices[] = {
		// positions        // texture Coords
		-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 0.0f, 1.0f, 0.0f};
	unsigned int quadVAO = 0;
	unsigned int quadVBO;
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &quadVBO);
	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));

	GLfloat nearPlaneWidth = 10;
	GLfloat zFar = 100.5f, zNear = 0.1f;
	glm::vec3 lightPos(-2.0f, 4.0f, -3.0f);

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		Window::DoMovement();
		Window::CalFrame();

#pragma region shadow map pass
		// 渲染深度图

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 lightSpaceTransform = GetLightSpaceTransform(lightPos, nearPlaneWidth, zFar, zNear);
		shadowMapShader.use();
		shadowMapShader.setMat4("lightSpaceTransform", lightSpaceTransform);

		// shadow map pass
		glViewport(0, 0, shadowMapWidth, shadowMapHeight);
		glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
		glClear(GL_DEPTH_BUFFER_BIT);

		glm::mat4 model = glm::mat4(1.0f);
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down a bit so it's at the center of the scene
		//model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));		// it's a bit too big for our scene, so scale it down
		//shadowMapShader.setMat4("model", model);
		//ourModel.Draw(shadowMapShader);
		//glBindVertexArray(0);


		// cubes
		glBindVertexArray(cubeVAO);
		glActiveTexture(GL_TEXTURE0);
		shadowMapShader.setMat4("model", model);
		glBindTexture(GL_TEXTURE_2D, cubeTexture);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		// floor
		glBindVertexArray(floorVAO);
		shadowMapShader.use();
		shadowMapShader.setMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
		/// normal pass
		glViewport(0, 0, 1280, 960);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		// model
		glm::mat4 view = Window::camera.GetViewMat4();
		glm::mat4 projection = glm::perspective<float>(glm::radians(Window::camera.Fov()), 1280 / 960, 0.1f, 1000.0f);
		//modelShader.use();
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // Translate it down a bit so it's at the center of the scene
		//model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));		// It's a bit too big for our scene, so scale it down
		//modelShader.setMat4("model", model);
		//modelShader.setMat4("model", model);
		//modelShader.setMat4("view", view);
		//ourModel.Draw(modelShader);
		//glBindVertexArray(0);

		model = glm::mat4(1.0f);
		// cubes
		glBindVertexArray(cubeVAO);
		unlitShader.use();
		unlitShader.setMat4("model", model);
		unlitShader.setMat4("view", view);
		unlitShader.setMat4("projection", projection);
		unlitShader.setMat4("lightSpaceVP", lightSpaceTransform);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, cubeTexture);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, shadowMap);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glBindVertexArray(0);

		// floor
		glBindVertexArray(floorVAO);
		simpleColorShader.use();
		simpleColorShader.setMat4("model", model);
		simpleColorShader.setMat4("view", view);
		simpleColorShader.setMat4("projection", projection);
		simpleColorShader.setMat4("lightSpaceVP", lightSpaceTransform);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, shadowMap);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		//// debugger shadow map‘
		// debugShadowMapShader.use();
		// debugShadowMapShader.setFloat("near_plane", zNear);
		// debugShadowMapShader.setFloat("far_plane", zFar);
		// glActiveTexture(GL_TEXTURE0);
		// glBindTexture(GL_TEXTURE_2D, shadowMap);
		//glBindVertexArray(quadVAO);
		//glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);


		glBindVertexArray(0);

#pragma endregion
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &skyboxVAO);
	glDeleteBuffers(1, &skyboxVBO);
}