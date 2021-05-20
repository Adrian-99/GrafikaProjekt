#pragma once
#include <GLFW/glfw3.h>
#include "Wheel.h"
#include "../Object/Vector3.h"

class WheelLinks
{
private:
	Vector3 position;					// pozycja elementu
	GLfloat size;						// wielko�� elementu
	Wheel wheel1, wheel2, wheel3;		// ko�a wchodz�ce w sk�ad elementu
	GLfloat* circleVertices;			// wska�nik do tablicy wsp�rz�dnych XZ wierzcho�k�w u�o�onych w okr�g
	GLint circleVerticesCount;			// liczba par w powy�szej tablicy
	bool leftSide;

public:
	WheelLinks(Vector3 startPosition, GLfloat size, GLboolean wheelsOnTheLeft, GLfloat* roverSpeed);
	~WheelLinks();
	void Draw();
	void TurnWheels(GLfloat turnAngle);

private:
	void DrawLink(GLfloat fromX, GLfloat fromZ, GLfloat toX, GLfloat toZ, GLfloat width);
	void DrawConnector(GLfloat x, GLfloat z, GLfloat width, bool extraWidth = false, bool leftExtraWidth = false);
};

