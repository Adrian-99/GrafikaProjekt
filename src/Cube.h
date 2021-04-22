#pragma once
#include <GLFW/glfw3.h>

class Cube
{
private:
	// Parametry wierzcholkow
	GLfloat sa[3];
	GLfloat sb[3];
	GLfloat sc[3];
	GLfloat sd[3];
	GLfloat se[3];
	GLfloat sf[3];
	GLfloat sg[3];
	GLfloat sh[3];

public:
	Cube(GLfloat x, GLfloat y, GLfloat z, GLfloat size);
	void Draw();
};

