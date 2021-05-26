#pragma once
#include <GLFW/glfw3.h>
#include "Body.h"
#include "WheelLinks.h"
#include "../Object/Vector3.h"
#include "../Drawable/Terrain.h"

class Rover
{
private:
	Vector3 position;				// aktualna pozycja ³azika
	GLfloat yawAngle;				// k¹t obrotu ³azika wokó³ osi Z
	GLfloat pitchAngle;				// k¹t obrotu ³azika wokó³ osi Y
	GLfloat rollAngle;				// k¹t obrotu ³azika wokó³ osi X
	Terrain* terrainPtr;			// wskaŸnik do obiektu terenu, po którym porusza siê ³azik

	GLfloat wheelsTurnAngle;		// aktualny k¹t skrêtu kó³
	GLfloat speed;					// aktualna prêdkoœæ ³azika
	GLfloat moveSpeed = 0.25f;		// przyspieszenie ³azika
	GLfloat brakingSpeed = 0.5f;	// hamowanie ³azika

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

