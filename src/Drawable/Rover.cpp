#include "Rover.h"

Rover::Rover(Vector3 startPosition, GLfloat size) :
	body(15.0f * size, 0.0f, 15.0f * size, size),
	leftWheelsWithLinks(Vector3(0.0f, -40.0f * size, 20.0f * size), size, true),
	rightWheelsWithLinks(Vector3(0.0f, 40.0f * size, 20.0f * size), size, false)
{
	position = startPosition;
	wheelsTurnAngle = 0.0f;
}

void Rover::Draw()
{
	glPushMatrix();

	glTranslatef(position.X(), position.Y(), position.Z());

	body.Draw();
	leftWheelsWithLinks.Draw();
	rightWheelsWithLinks.Draw();

	glPopMatrix();
}

void Rover::AddWheelsTurnAngle(GLfloat additionalAngle)
{
	wheelsTurnAngle += additionalAngle;
	if (wheelsTurnAngle > 30) wheelsTurnAngle = 30.0f;
	else if (wheelsTurnAngle < -30) wheelsTurnAngle = -30.0f;
	leftWheelsWithLinks.TurnWheels(wheelsTurnAngle);
	rightWheelsWithLinks.TurnWheels(wheelsTurnAngle);
}

void Rover::WheelsCentering()
{
	if (wheelsTurnAngle > 2) wheelsTurnAngle -= 2.0f;
	else if (wheelsTurnAngle < 2) wheelsTurnAngle += 2.0f;
	else if (wheelsTurnAngle != 0) wheelsTurnAngle = 0.0f;
	leftWheelsWithLinks.TurnWheels(wheelsTurnAngle);
	rightWheelsWithLinks.TurnWheels(wheelsTurnAngle);
}
