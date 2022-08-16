#include "Window.h"


bool Window::keys[1024];
Camera Window::camera;
GLfloat Window::deltaTime = 0.0f;
GLfloat Window::lastFrameTime = 0.0f;
float Window::lastX = 800 * 0.5;
float Window::lastY = 600 * 0.5;
bool Window::isFirstMouse = true;

GLFWwindow* Window::InitWindow(const float width, const float height, Camera& cam) {
	glfwInit();
	Window::camera = cam;
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetCursorPosCallback(window, MouseCallback);
	glfwSetScrollCallback(window, ScrollCallback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// Define the viewport dimensions
	glViewport(0, 0, width, height);


	return window;
}


void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS)
		keys[key] = true;
	else if (action == GLFW_RELEASE)
		keys[key] = false;
}
void Window::DoMovement()
{
	if (keys[GLFW_KEY_W])
		Window::camera.HandleKeyboard(DIRECTION::FORWARD, deltaTime);
	if (keys[GLFW_KEY_S])
		Window::camera.HandleKeyboard(DIRECTION::BACK, deltaTime);
	if (keys[GLFW_KEY_A])
		Window::camera.HandleKeyboard(DIRECTION::LEFT, deltaTime);
	if (keys[GLFW_KEY_D])
		Window::camera.HandleKeyboard(DIRECTION::RIGHT, deltaTime);
}

void Window::MouseCallback(GLFWwindow* window, double xpos, double ypos) {
	if (isFirstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		isFirstMouse = false;
	}
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // 注意这里是相反的，因为y坐标是从底部往顶部依次增大的
	lastX = xpos;
	lastY = ypos;

	camera.HandleMouse(xoffset, yoffset);
}
void Window::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	Window::camera.HandleScroll(yoffset);
}

void Window::CalFrame() {
	GLfloat currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrameTime;
	lastFrameTime = currentFrame;
}
