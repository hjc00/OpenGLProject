
#include "RenderModel.h"
#include"Shader.h"
#include"Window.h"
#include <gtc/type_ptr.hpp>
#include"Model.h"

void RenderModel(Camera& camera) {

	GLFWwindow* window = Window::InitWindow(1280, 960, camera);

	Shader ourShader("ShaderFile/model_loading.vs", "ShaderFile/model_loading.fs");
	Model ourModel("Models/nanosuit/nanosuit.obj");

	glEnable(GL_DEPTH_TEST);
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

		ourShader.use();   // <-- Don't forget this one!
	// Transformation matrices
		glm::mat4 projection = glm::perspective(Window::camera.Fov(), (float)1280 / (float)960, 0.1f, 100.0f);
		glm::mat4 view = Window::camera.GetViewMat4();
		glUniformMatrix4fv(glGetUniformLocation(ourShader.Program(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(ourShader.Program(), "view"), 1, GL_FALSE, glm::value_ptr(view));

		// Draw the loaded model
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(ourShader.Program(), "model"), 1, GL_FALSE, glm::value_ptr(model));
		ourModel.Draw(ourShader);

		// Swap the screen buffers
		glfwSwapBuffers(window);

	}

}