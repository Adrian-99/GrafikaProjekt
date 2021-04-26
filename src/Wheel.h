#pragma once
#include <GLFW/glfw3.h>
#include <cmath>

class Wheel
{
private:
	GLfloat* position;
	GLfloat halfTireWidth;
	GLfloat halfRimWidth;
	GLfloat* rimOuterVertices;
	GLfloat* tireMiddleVertices;
	GLfloat* tireOuterVertices;
	GLint verticesNumber;

public:
	Wheel(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLfloat width);
	~Wheel();
	void Draw();
	void ChangeYPosition(GLfloat y);

private:
	void DrawRim();
	void DrawTire();
};

