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

GLfloat* Vector3::ToArray()
{
	return position;
}

Vector3 Vector3::operator+(Vector3 v)
{
	return Vector3(this->position[0] + v.position[0], this->position[1] + v.position[1], this->position[2] + v.position[2]);
}

Vector3 Vector3::operator-(Vector3 v)
{
	return Vector3(this->position[0] - v.position[0], this->position[1] - v.position[1], this->position[2] - v.position[2]);
}
