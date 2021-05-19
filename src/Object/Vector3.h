#pragma once
#include <GLFW/glfw3.h>

class Vector3
{
private:
	GLfloat position[3];

public:
	Vector3(GLfloat x = 0.0f, GLfloat y = 0.0f, GLfloat z = 0.0f);
	GLfloat X();
	GLfloat Y();
	GLfloat Z();
	GLfloat* ToArray();
	GLfloat X(GLfloat newX);
	GLfloat Y(GLfloat newY);
	GLfloat Z(GLfloat newZ);
	Vector3 operator+(const Vector3& v);
	Vector3 operator-(const Vector3& v);
	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
};

