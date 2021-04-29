#include "Rover.h"

Rover::Rover(GLfloat x, GLfloat y, GLfloat z, GLfloat size) :
	body(x + 15.0f * size, y, z + 15.0f * size, size),
	leftWheelsWithLinks(x, y - 40.0f * size, z + 20.0f * size, size, true),
	rightWheelsWithLinks(x, y + 40.0f * size, z + 20.0f * size, size, false)
{
}

void Rover::Draw()
{
	body.Draw();
	leftWheelsWithLinks.Draw();
	rightWheelsWithLinks.Draw();
}
