#include "Rover.h"

Rover::Rover(Vector3 startPosition, GLfloat size) :
	body(5.0f * size, 0.0f, 45.0f * size, size),
	leftWheelsWithLinks(Vector3(-10.0f * size, -40.0f * size, 50.0f * size), size, true, &speed),
	rightWheelsWithLinks(Vector3(-10.0f * size, 40.0f * size, 50.0f * size), size, false, &speed)
{
	position = startPosition;
	rotationAngle = 0.0f;
	wheelsTurnAngle = 0.0f;
	speed = 0.0f;

	this->size = size;
}

void Rover::Draw()
{
	glPushMatrix();

	glTranslatef(position.X(), position.Y(), position.Z());
	glRotatef(rotationAngle + 180.0f, 0.0f, 0.0f, 1.0f);

	body.Draw();
	leftWheelsWithLinks.Draw();
	rightWheelsWithLinks.Draw();

	glPopMatrix();
}

void Rover::ProcessInput(GLfloat additionalSpeed, GLfloat additionalTurnAngle)
{
	if (additionalTurnAngle != 0.0f) {
		wheelsTurnAngle += additionalTurnAngle;
		if (wheelsTurnAngle > 25.0f) wheelsTurnAngle = 25.0f;
		else if (wheelsTurnAngle < -25.0f) wheelsTurnAngle = -25.0f;
	}
	else {
		if (wheelsTurnAngle > 2.0f) wheelsTurnAngle -= 2.0f;
		else if (wheelsTurnAngle < -2.0f) wheelsTurnAngle += 2.0f;
		else if (wheelsTurnAngle != 0.0f) wheelsTurnAngle = 0.0f;
	}
	leftWheelsWithLinks.TurnWheels(wheelsTurnAngle);
	rightWheelsWithLinks.TurnWheels(wheelsTurnAngle);

	// TODO: Aktualizacja prêdkoœci tutaj
	//additionalSpeed == velocity
	
	// move forward or backward
	if (additionalSpeed != 0.0f) {
		if (speed < 20 and speed > -20)
			speed += additionalSpeed;
	}
	//momentum
	else if (additionalSpeed == 0.0f) {
		//TODO: add more advanced mathematical model
		if (speed > 0.0f) speed -= 0.25f;
		if (speed < 0.0f) speed += 0.25f;		
		//std::cout << "momentum-speed: " << speed << std::endl;
	}

	UpdatePosition();
}

void Rover::UpdatePosition()
{
	if (speed != 0.0f) {
		Vector3 moveVector;
		GLfloat distance = speed / 1.25;	//TODO: factor depends on rover speed
		if (wheelsTurnAngle != 0.0f) {
			GLfloat turnRadius = 1 / tan(wheelsTurnAngle * 0.01745329252f) * 75.0f * size;
			rotationAngle += 360 * (distance / (2 * 3.14159265359f * turnRadius));
		}
		moveVector.X(cos(rotationAngle * 0.01745329252f) * distance);
		moveVector.Y(sin(rotationAngle * 0.01745329252f) * distance);
		position += moveVector;
	}
}
