#pragma once
#include <GLFW/glfw3.h>
#include "Body.h"
#include "WheelLinks.h"
#include "../Object/Vector3.h"
#include "../Drawable/Terrain.h"

class Rover
{
private:
	Vector3 position;
	GLfloat rotationAngle;
	Terrain* terrainPtr;

	GLfloat wheelsTurnAngle;
	GLfloat speed;
	GLfloat moveSpeed = 0.25f;
	GLfloat breakingSpeed = 0.5f;

	GLfloat size;
	Body body;
	WheelLinks leftWheelsWithLinks;
	WheelLinks rightWheelsWithLinks;

public:
	Rover(Vector3 startPosition, GLfloat size, Terrain* terrainPtr);
	void Draw();
	void ProcessInput(GLfloat additionalSpeed, GLfloat additionalTurnAngle);
	Vector3 GetPosition();
	GLfloat GetRotation();

private:
	void UpdatePosition();
};

