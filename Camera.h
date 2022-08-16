#pragma once
#include<glm.hpp>

enum DIRECTION
{
	FORWARD,
	BACK,
	LEFT,
	RIGHT
};

class Camera
{
public:
	typedef   glm::vec3 VEC3;

public:
	Camera(VEC3 _pos = VEC3(0.0f, 0.0f, 0.0f),
		VEC3 _forward = VEC3(0.0f, 0.0f, -1.0f),
		VEC3 _worldUp = VEC3(0.0f, 1.0f, 0.0f),
		float _fov = 45.0f,
		float _sensitivity = 0.05f,
		float _speed = 5.0f
	) : position(_pos),
		forward(_forward),
		worldUp(_worldUp),
		fov(_fov),
		sensitivity(_sensitivity),
		speed(_speed),
		pitch(0.0f),
		yaw(-90)
	{
		this->UpdateCameraVectors();
	};

	glm::mat4 GetViewMat4() const;

	void HandleKeyboard(DIRECTION dir, float deltaTime);

	void HandleMouse(float xoffset, float yoffset);

	void HandleScroll(double yoffset);

	float Fov() const {
		return fov;
	};

	VEC3 Position() const {
		return position;
	};
	VEC3 Forward() const {
		return forward;
	};


private:
	void UpdateCameraVectors();
private:
	VEC3 position;
	VEC3 forward;
	VEC3 worldUp;
	VEC3 up;
	VEC3 right;
	float fov;
	float sensitivity;
	float speed;
	float pitch;
	float yaw;
};

