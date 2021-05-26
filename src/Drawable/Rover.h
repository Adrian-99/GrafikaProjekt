#pragma once
#include <GLFW/glfw3.h>
#include "Body.h"
#include "WheelLinks.h"
#include "../Object/Vector3.h"
#include "../Drawable/Terrain.h"

class Rover
{
private:
	Vector3 position;				// aktualna pozycja �azika
	GLfloat yawAngle;				// k�t obrotu �azika wok� osi Z
	GLfloat pitchAngle;				// k�t obrotu �azika wok� osi Y
	GLfloat rollAngle;				// k�t obrotu �azika wok� osi X
	Terrain* terrainPtr;			// wska�nik do obiektu terenu, po kt�rym porusza si� �azik

	GLfloat wheelsTurnAngle;		// aktualny k�t skr�tu k�
	GLfloat speed;					// aktualna pr�dko�� �azika
	GLfloat moveSpeed = 0.25f;		// przyspieszenie �azika
	GLfloat brakingSpeed = 0.5f;	// hamowanie �azika

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

