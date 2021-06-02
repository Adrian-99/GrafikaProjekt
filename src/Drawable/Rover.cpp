#include "Rover.h"

Rover::Rover(Vector3 startPosition, GLfloat size, Terrain* terrainPtr) :
	body(5.0f * size, 0.0f, 45.0f * size, size),
	leftWheelsWithLinks(Vector3(-10.0f * size, -40.0f * size, 50.0f * size), size, true),
	rightWheelsWithLinks(Vector3(-10.0f * size, 40.0f * size, 50.0f * size), size, false)
{
	position = startPosition;
	yawAngle = 0.0f;
	pitchAngle = 0.0f;
	rollAngle = 0.0f;
	wheelsTurnAngle = 0.0f;
	speed = 0.0f;
	this->size = size;
	this->terrainPtr = terrainPtr;
}

void Rover::Draw()
{
	glPushMatrix();

	glTranslatef(position.X(), position.Y(), position.Z());
	glRotatef(yawAngle + 180.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(pitchAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(rollAngle, 1.0f, 0.0f, 0.0f);

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
				
		//braking while moving forward
		if (speed > 0 and moveDirection < 0 )
			speed -= brakingSpeed;
		
		//braking while moving backward
		else if (speed < 0 and moveDirection > 0)
			speed += brakingSpeed;

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
	return yawAngle;
}

void Rover::UpdatePosition()
{
	if (speed != 0.0f) {
		Vector3 moveVector;
		GLfloat distance = speed / 1.25;
		if (wheelsTurnAngle != 0.0f) {
			GLfloat turnRadius = 1 / tan(wheelsTurnAngle * 0.01745329252f) * 75.0f * size;
			yawAngle += 360 * (distance / (2 * 3.14159265359f * turnRadius));
			while (yawAngle > 360) yawAngle -= 360;
			while (yawAngle < 0) yawAngle += 360;
		}
		moveVector.X(cos(yawAngle * 0.01745329252f) * distance);
		moveVector.Y(sin(yawAngle * 0.01745329252f) * distance);
		position += moveVector;

		Vector2 leftFrontXY = Vector2(75.0f * size * cos(pitchAngle * 0.01745329252f), 40.0f * size * cos(rollAngle * 0.01745329252f));
		Vector2 rightFrontXY = Vector2(75.0f * size * cos(pitchAngle * 0.01745329252f), -40.0f * size * cos(-rollAngle * 0.01745329252f));
		Vector2 leftBackXY = Vector2(-60.0f * size * cos(-pitchAngle * 0.01745329252f), 40.0f * size * cos(rollAngle * 0.01745329252f));
		Vector2 rightBackXY = Vector2(-60.0f * size * cos(-pitchAngle * 0.01745329252f), -40.0f * size * cos(-rollAngle * 0.01745329252f));

		GLfloat leftFrontHeight = terrainPtr->GetApproxHeightAt(position.ToVector2() + leftFrontXY.Rotate(yawAngle));
		GLfloat rightFrontHeight = terrainPtr->GetApproxHeightAt(position.ToVector2() + rightFrontXY.Rotate(yawAngle));
		GLfloat leftBackHeight = terrainPtr->GetApproxHeightAt(position.ToVector2() + leftBackXY.Rotate(yawAngle));
		GLfloat rightBackHeight = terrainPtr->GetApproxHeightAt(position.ToVector2() + rightBackXY.Rotate(yawAngle));

		GLfloat newPitchAngle = (asin((leftFrontHeight - leftBackHeight) / 135.0f) + asin((rightFrontHeight - rightBackHeight) / 135.0f)) * 57.2957795 / 2;
		GLfloat newRollAngle = (asin((rightFrontHeight - leftFrontHeight) / 80.0f) + asin((rightBackHeight - leftBackHeight) / 80.0f)) * 57.2957795 / 2;

		GLfloat angleMaxStep = 10.0f;

		if (newPitchAngle - pitchAngle < -angleMaxStep) pitchAngle -= angleMaxStep;
		else if (newPitchAngle - pitchAngle > angleMaxStep) pitchAngle += angleMaxStep;
		else pitchAngle = newPitchAngle;

		if (newRollAngle - rollAngle < -angleMaxStep) rollAngle -= angleMaxStep;
		else if (newRollAngle - rollAngle > angleMaxStep) rollAngle += angleMaxStep;
		else rollAngle = newRollAngle;

		position.Z((leftFrontHeight + rightFrontHeight + leftBackHeight + rightBackHeight) / 4);

		std::cout << "Yaw: " << yawAngle << "; Pitch: " << pitchAngle << "; Roll: " << rollAngle << std::endl;
	}
}
