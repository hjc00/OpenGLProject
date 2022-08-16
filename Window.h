#ifndef WINDOW_H

#include "3rd/include/GL/glew.h"
#include"3rd/include/GLFW/glfw3.h"
#include"Camera.h"

class Window
{
public:

	static GLFWwindow* InitWindow(const float width, const float height,Camera& cam);
	static void DoMovement();
	static void CalFrame();

	static Camera camera;
private:
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static	void MouseCallback(GLFWwindow* window, double xpos, double ypos);
	static	void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);


	static float lastX;
	static float lastY;
	static GLfloat deltaTime;   // 当前帧遇上一帧的时间差
	static GLfloat lastFrameTime;   // 上一帧的时间

	static bool isFirstMouse;
	static bool keys[1024];

};



#endif // !WINDOW_H
