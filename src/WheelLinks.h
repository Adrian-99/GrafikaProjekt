#pragma once
#include <GLFW/glfw3.h>
#include "Wheel.h"

class WheelLinks
{
private:
	GLfloat startX, startY, startZ;		// pozycja elementu
	GLfloat size;						// wielko�� elementu
	Wheel wheel1, wheel2, wheel3;		// ko�a wchodz�ce w sk�ad elementu
	GLfloat* circleVertices;			// wska�nik do tablicy wsp�rz�dnych XZ wierzcho�k�w u�o�onych w okr�g
	GLint circleVerticesCount;			// liczba par w powy�szej tablicy

public:
	WheelLinks(GLfloat startX, GLfloat startY, GLfloat startZ, GLfloat size, GLboolean wheelsOnTheLeft);
	~WheelLinks();
	void Draw();

private:
	void DrawLink(GLfloat fromX, GLfloat fromZ, GLfloat toX, GLfloat toZ, GLfloat width);
	void DrawConnector(GLfloat x, GLfloat z, GLfloat width);
};

