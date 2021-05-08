#include "Vertex.h"

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z)
{
	position[0] = x;
	position[1] = y;
	position[2] = z;
}

GLfloat Vertex::X()
{
	return position[0];
}

GLfloat Vertex::Y()
{
	return position[1];
}

GLfloat Vertex::Z()
{
	return position[2];
}

GLfloat* Vertex::ToArray()
{
	return position;
}

Vertex Vertex::operator+(Vertex v)
{
	return Vertex(this->position[0] + v.position[0], this->position[1] + v.position[1], this->position[2] + v.position[2]);
}

Vertex Vertex::operator-(Vertex v)
{
	return Vertex(this->position[0] - v.position[0], this->position[1] - v.position[1], this->position[2] - v.position[2]);
}
