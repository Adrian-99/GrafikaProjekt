#pragma once
#include <GLFW/glfw3.h>
#include "Body.h"
#include "WheelLinks.h"
#include "../Object/Vector3.h"

class Rover
{
private:
	Vector3 position;
	GLfloat rotationAngle;

	GLfloat wheelsTurnAngle;
	GLfloat speed;

	GLfloat size;
	Body body;
	WheelLinks leftWheelsWithLinks;
	WheelLinks rightWheelsWithLinks;

public:
	Rover(Vector3 startPosition, GLfloat size);
	void Draw();
	void ProcessInput(GLfloat additionalSpeed, GLfloat additionalTurnAngle);

private:
	void UpdatePosition();
};

