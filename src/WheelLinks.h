#pragma once
#include <GLFW/glfw3.h>
#include "Wheel.h"

class WheelLinks
{
private:
	GLfloat startX, startY, startZ, size;
	Wheel wheel1, wheel2, wheel3;
	GLfloat* circleVertices;
	GLint circleVerticesCount;
	GLfloat* frontLinkVertices;
	GLint frontLinkVerticesCount;

public:
	WheelLinks(GLfloat startX, GLfloat startY, GLfloat startZ, GLfloat size, GLboolean wheelsOnTheLeft);
	~WheelLinks();
	void Draw();

private:
	void DrawLink(GLfloat fromX, GLfloat fromZ, GLfloat toX, GLfloat toZ, GLfloat width);
	void DrawConnector(GLfloat x, GLfloat z, GLfloat width);
};

