#pragma once
#include <GLFW/glfw3.h>
#include "Body.h"
#include "WheelLinks.h"

class Rover
{
private:
	Body body;
	WheelLinks leftWheelsWithLinks;
	WheelLinks rightWheelsWithLinks;

public:
	Rover(GLfloat x, GLfloat y, GLfloat z, GLfloat size);
	void Draw();
};

