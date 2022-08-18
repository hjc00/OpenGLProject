#ifndef STENCIL_H

#include"Shader.h"

void RenderStencil(Camera& camera)
{
	//GLFWwindow* window = InitWindow();
	GLFWwindow* window = Window::InitWindow(1280, 960, camera);

	float vertices[] = {
		// Back face
		   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
			0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // bottom-right         
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
		   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // bottom-left
		   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
		   // Front face
		   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
		   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // top-left
		   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
		   // Left face
		   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
		   -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-left
		   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
		   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
		   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
		   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
		   // Right face
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
			0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right         
			0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
			0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left     
		   // Bottom face
		   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
			0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // top-left
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
		   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
		   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
		   // Top face
		   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right     
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
		   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
		   -0.5f,  0.5f,  0.5f,  0.0f, 0.0f  // bottom-left     
	};

	glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(0.5f,  0.5f, 1.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	glm::vec3 objectPos = glm::vec3(0.0f, 0.0f, 0.0f);

	GLuint objectVBO;
	glGenBuffers(1, &objectVBO);

	GLuint  objectVAO;
	glGenVertexArrays(1, &objectVAO);
	glBindBuffer(GL_ARRAY_BUFFER, objectVBO);  // ��OPEN GL��ǰ�Ķ��㻺�����󶨵�objectVBOȥ,��open gl ��ǰ���ݵĶ��㻺�������������objectVBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);  // ��vertices�Ķ����������õ�objectVBOȥ
	glBindVertexArray(objectVAO);
	//position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);         // ����layoutΪ0�Ķ�������
	//normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);	 // ����layoutΪ1�Ķ�������
	//textcoords attribute 
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);	 // ����layoutΪ1�Ķ�������
	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);  // ��OPEN GL��ǰ�Ķ��㻺��������objectVBO���


	Shader objectShader("ShaderFile/unlit.vs", "ShaderFile/unlit.frag");
	GLuint diffuseMap = Utils::GenTexture("Resources/container2.png");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, diffuseMap);

	objectShader.use();
	objectShader.setInt("mainTex", 0);

	Shader outlineShader("ShaderFile/unlit.vs", "ShaderFile/outline.frag");
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);  // GL_REPLACE ��ͨ����ģ�����ʱ����ref��ֵ����ģ�建��ԭ����ֵ


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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//// render object



		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = Window::camera.GetViewMat4();
		glm::mat4 projection = glm::perspective<float>(glm::radians(Window::camera.Fov()), 1280 / 960, 0.1f, 100.0f);



		glStencilFunc(GL_ALWAYS, 1, 0xFF); // ��ƬԪ��Զͨ��ģ����ԣ������Բο�ֵ1д��ģ�建��
		glStencilMask(0xFF);			// ��0XFF��Ҫд���ģ��ֵ����and���㣬�õ�����Ҫд���ģ��ֵ

		// ��opengl��ǰ�Ķ������ݰ󶨵�objectVAO�����������opengl�Զ������ݵĲ����ǲ���objectVAO
		glBindVertexArray(objectVAO);

		// ������Ⱦpass
		/*glStencilFunc*/
		objectShader.use();
		model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[0]);
		objectShader.setMat4("model", model);
		objectShader.setMat4("view", view);
		objectShader.setMat4("projection", projection);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::translate(model, cubePositions[1]);
		objectShader.setMat4("model", model);
		objectShader.setMat4("view", view);
		objectShader.setMat4("projection", projection);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//glBindVertexArray(0);

		// ----------------------------------- outline pass--------------------------//
		glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
		glStencilMask(0x00);

		outlineShader.use();
		glBindVertexArray(objectVAO);
		float scale = 1.02f;
		model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[0]);
		model = glm::scale(model, glm::vec3(scale, scale, scale));
		outlineShader.setMat4("model", model);
		outlineShader.setMat4("view", view);
		outlineShader.setMat4("projection", projection);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[1]);
		model = glm::scale(model, glm::vec3(scale, scale, scale));
		outlineShader.setMat4("model", model);
		outlineShader.setMat4("view", view);
		outlineShader.setMat4("projection", projection);
		glDrawArrays(GL_TRIANGLES, 0, 36);


		glBindVertexArray(0);

		glStencilMask(0xFF);
		glStencilFunc(GL_ALWAYS, 0, 0xFF);

		// Swap the screen buffers
		glfwSwapBuffers(window);

	}
	glDeleteVertexArrays(1, &objectVAO);
	glDeleteBuffers(1, &objectVBO);

	glfwTerminate();
}


#endif // !STENCIL_H

