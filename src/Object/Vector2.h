#pragma once
#include <GLFW/glfw3.h>
#include <math.h>

class Vector2
{
private:
	GLfloat position[2];

public:
	Vector2(GLfloat x = 0.0f, GLfloat y = 0.0f);
	GLfloat X();
	GLfloat Y();
	GLfloat X(GLfloat newX);
	GLfloat Y(GLfloat newY);
	Vector2 Rotate(GLfloat angle);
	GLfloat GetLength();
	GLfloat GetAngle();
	GLfloat* ToArray();
	Vector2 operator+(const Vector2& v);
	Vector2 operator-(const Vector2& v);
	Vector2 operator*(const GLfloat& num);
	Vector2 operator/(const GLfloat& num);
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(const GLfloat& num);
	Vector2& operator/=(const GLfloat& num);
	bool operator!=(const Vector2& v);
	bool operator>(const Vector2& v);
	bool operator>=(const Vector2& v);
	bool operator<(const Vector2& v);
	bool operator<=(const Vector2& v);
};

