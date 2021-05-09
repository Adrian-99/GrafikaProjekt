#pragma once
#include <GLFW/glfw3.h>

class Vector2
{
private:
	GLfloat position[2];

public:
	Vector2(GLfloat x = 0.0f, GLfloat y = 0.0f);
	GLfloat X();
	GLfloat Y();
	GLfloat* ToArray();
};

