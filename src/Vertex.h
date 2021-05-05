#pragma once
#include <GLFW/glfw3.h>

class Vertex
{
private:
	GLfloat position[3];

public:
	Vertex(GLfloat x, GLfloat y, GLfloat z);
	GLfloat X();
	GLfloat Y();
	GLfloat Z();
	GLfloat* ToArray();
};

