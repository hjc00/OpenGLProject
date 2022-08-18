#include "Camera.h"
#include<gtc/matrix_transform.hpp>
#include<iostream>

glm::mat4 Camera::GetViewMat4() const
{
	return glm::lookAt(position, position + forward, worldUp);
}

void Camera::HandleKeyboard(DIRECTION dir, float deltaTime)
{

	if (DIRECTION::FORWARD == dir)
		position += speed * forward * deltaTime;
	if (DIRECTION::BACK == dir)
		position -= speed * forward * deltaTime;
	if (DIRECTION::LEFT == dir)
		position -= speed * right * deltaTime;
	if (DIRECTION::RIGHT == dir)
		position += speed * right * deltaTime;

	//std::cout << "camera position x" << position.x << std::endl;
	//std::cout << "camera position y" << position.y << std::endl;
	//std::cout << "camera position z" << position.z << std::endl;
}

void Camera::HandleMouse(float xoffset, float yoffset)
{
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	this->UpdateCameraVectors();
}

void Camera::HandleScroll(double yoffset)
{

	if (fov >= 1.0f && fov <= 45.0f)
		fov -= yoffset;
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= 45.0f)
		fov = 45.0f;

}

void Camera::UpdateCameraVectors()
{

	glm::vec3 front;
	front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	front.y = sin(glm::radians(this->pitch));
	front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->forward = glm::normalize(front);
	this->right = glm::normalize(glm::cross(this->forward, this->worldUp));
	this->up = glm::normalize(glm::cross(this->right, this->forward));
}
