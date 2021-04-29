#include "Rover.h"

Rover::Rover(GLfloat x, GLfloat y, GLfloat z, GLfloat size) :
	leftWheelsWithLinks(0.0f, -40.0f, 20.0f, 1.0f, true),
	rightWheelsWithLinks(0.0f, 40.0f, 20.0f, 1.0f, false)
{
}

void Rover::Draw()
{
	body.Draw();
	leftWheelsWithLinks.Draw();
	rightWheelsWithLinks.Draw();
}
