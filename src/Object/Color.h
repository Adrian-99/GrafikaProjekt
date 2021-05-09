#pragma once
#include <GLFW/glfw3.h>

class Color
{
private:
	GLfloat rgb[3];

public:
	Color(GLfloat red = 0.0f, GLfloat green = 0.0f, GLfloat blue = 0.0f);
	GLfloat Red();
	GLfloat Green();
	GLfloat Blue();
	GLfloat* ToArray();
};

