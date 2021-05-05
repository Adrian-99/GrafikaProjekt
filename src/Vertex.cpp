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
