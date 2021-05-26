#include "Rover.h"

Rover::Rover(Vector3 startPosition, GLfloat size) :
	body(5.0f * size, 0.0f, 45.0f * size, size),
	leftWheelsWithLinks(Vector3(-10.0f * size, -40.0f * size, 50.0f * size), size, true),
	rightWheelsWithLinks(Vector3(-10.0f * size, 40.0f * size, 50.0f * size), size, false)
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

void Rover::ProcessInput(GLfloat moveDirection, GLfloat additionalTurnAngle)
{
	// Aktualizacja skrêtu kó³	
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

	// Aktualizacja prêdkoœci ³azika	
	if (moveDirection != 0.0f) {
				
		//breaking while moving forward
		if (speed > 0 and moveDirection < 0 )
			speed -= breakingSpeed;
		
		//breaking while moving backward
		else if (speed < 0 and moveDirection > 0)
			speed += breakingSpeed;

		// move forward 
		if (moveDirection == 1.0f and speed < 20)
			speed += moveSpeed;
		// move backward 
		else if (moveDirection == -1.0f and speed > -20)
			speed += -moveSpeed;
		
	}
	//momentum
	else if (moveDirection == 0.0f) {
		//TODO: add more advanced mathematical model
		if (speed > 0.0f) speed -= moveSpeed;
		if (speed < 0.0f) speed += moveSpeed;
	}

	leftWheelsWithLinks.UpdateWheels(wheelsTurnAngle, speed);
	rightWheelsWithLinks.UpdateWheels(wheelsTurnAngle, speed);

	UpdatePosition();
}

Vector3 Rover::GetPosition()
{
	return position;
}

GLfloat Rover::GetRotation()
{
	return rotationAngle;
}

void Rover::UpdatePosition()
{
	if (speed != 0.0f) {
		Vector3 moveVector;
		GLfloat distance = speed / 1.25;	//TODO: factor(1.25) depends on rover speed
		if (wheelsTurnAngle != 0.0f) {
			GLfloat turnRadius = 1 / tan(wheelsTurnAngle * 0.01745329252f) * 75.0f * size;
			rotationAngle += 360 * (distance / (2 * 3.14159265359f * turnRadius));
			while (rotationAngle > 360) rotationAngle -= 360;
			while (rotationAngle < 0) rotationAngle += 360;
		}
		moveVector.X(cos(rotationAngle * 0.01745329252f) * distance);
		moveVector.Y(sin(rotationAngle * 0.01745329252f) * distance);
		position += moveVector;
	}
}
