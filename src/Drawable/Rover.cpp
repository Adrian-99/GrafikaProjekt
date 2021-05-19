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

void Rover::ProcessInput(GLfloat additionalSpeed, GLfloat additionalTurnAngle)
{
	if (additionalTurnAngle != 0.0f) {
		wheelsTurnAngle += additionalTurnAngle;
		if (wheelsTurnAngle > 30.0f) wheelsTurnAngle = 30.0f;
		else if (wheelsTurnAngle < -30.0f) wheelsTurnAngle = -30.0f;
	}
	else {
		if (wheelsTurnAngle > 2.0f) wheelsTurnAngle -= 2.0f;
		else if (wheelsTurnAngle < -2.0f) wheelsTurnAngle += 2.0f;
		else if (wheelsTurnAngle != 0.0f) wheelsTurnAngle = 0.0f;
		leftWheelsWithLinks.TurnWheels(wheelsTurnAngle);
		rightWheelsWithLinks.TurnWheels(wheelsTurnAngle);
	}
	leftWheelsWithLinks.TurnWheels(wheelsTurnAngle);
	rightWheelsWithLinks.TurnWheels(wheelsTurnAngle);

	// TODO: Aktualizacja prêdkoœci tutaj
}
