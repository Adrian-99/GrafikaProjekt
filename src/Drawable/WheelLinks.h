#pragma once
#include <GLFW/glfw3.h>
#include "Wheel.h"
#include "../Object/Vector3.h"

class WheelLinks
{
private:
	Vector3 position;					// pozycja elementu
	GLfloat size;						// wielkoœæ elementu
	Wheel wheel1, wheel2, wheel3;		// ko³a wchodz¹ce w sk³ad elementu
	GLfloat* circleVertices;			// wskaŸnik do tablicy wspó³rzêdnych XZ wierzcho³ków u³o¿onych w okr¹g
	GLint circleVerticesCount;			// liczba par w powy¿szej tablicy
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

