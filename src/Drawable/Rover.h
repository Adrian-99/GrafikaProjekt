#pragma once
#include <GLFW/glfw3.h>
#include "Body.h"
#include "WheelLinks.h"
#include "../Object/Vector3.h"

class Rover
{
private:
	Vector3 position;

	Body body;
	WheelLinks leftWheelsWithLinks;
	WheelLinks rightWheelsWithLinks;

	GLfloat wheelsTurnAngle;

public:
	Rover(Vector3 startPosition, GLfloat size);
	void Draw();
	void AddWheelsTurnAngle(GLfloat additionalAngle);
	void WheelsCentering();
};

