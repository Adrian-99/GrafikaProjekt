#include "Vector3.h"

Vector3::Vector3(GLfloat x, GLfloat y, GLfloat z)
{
	position[0] = x;
	position[1] = y;
	position[2] = z;
}

GLfloat Vector3::X()
{
	return position[0];
}

GLfloat Vector3::Y()
{
	return position[1];
}

GLfloat Vector3::Z()
{
	return position[2];
}

GLfloat Vector3::X(GLfloat newX)
{
	position[0] = newX;
	return newX;
}

GLfloat Vector3::Y(GLfloat newY)
{
	position[1] = newY;
	return newY;
}

GLfloat Vector3::Z(GLfloat newZ)
{
	position[2] = newZ;
	return newZ;
}

Vector3 Vector3::Rotate(GLfloat xAxisAngle, GLfloat yAxisAngle, GLfloat zAxisAngle)
{
	xAxisAngle = xAxisAngle * 0.01745329252f;
	yAxisAngle = yAxisAngle * 0.01745329252f;
	zAxisAngle = zAxisAngle * 0.01745329252f;
	Vector3 result = *this;

	result.position[1] = result.position[1] * cos(xAxisAngle) - result.position[2] * sin(xAxisAngle);
	result.position[2] = result.position[1] * sin(xAxisAngle) + result.position[2] * cos(xAxisAngle);

	result.position[0] = result.position[0] * cos(yAxisAngle) + result.position[2] * sin(yAxisAngle);
	result.position[2] = -result.position[0] * sin(yAxisAngle) + result.position[2] * cos(yAxisAngle);

	result.position[0] = result.position[0] * cos(zAxisAngle) - result.position[1] * sin(zAxisAngle);
	result.position[1] = result.position[0] * sin(zAxisAngle) + result.position[1] * cos(zAxisAngle);

	return result;
}

GLfloat Vector3::GetLength()
{
	return sqrt(pow(position[0], 2) + pow(position[1], 2) + pow(position[2], 2));
}

GLfloat* Vector3::ToArray()
{
	return position;
}

Vector2 Vector3::ToVector2()
{
	return Vector2(position[0], position[1]);
}

Vector3 Vector3::operator+(const Vector3& v)
{
	return Vector3(this->position[0] + v.position[0], this->position[1] + v.position[1], this->position[2] + v.position[2]);
}

Vector3 Vector3::operator-(const Vector3& v)
{
	return Vector3(this->position[0] - v.position[0], this->position[1] - v.position[1], this->position[2] - v.position[2]);
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	position[0] += v.position[0];
	position[1] += v.position[1];
	position[2] += v.position[2];
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
	position[0] -= v.position[0];
	position[1] -= v.position[1];
	position[2] -= v.position[2];
	return *this;
}
