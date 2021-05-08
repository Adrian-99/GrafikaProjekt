#pragma once
#include <GLFW/glfw3.h>
#include "Wheel.h"

class WheelLinks
{
private:
	GLfloat startX, startY, startZ;		// pozycja elementu
	GLfloat size;						// wielkoœæ elementu
	Wheel wheel1, wheel2, wheel3;		// ko³a wchodz¹ce w sk³ad elementu
	GLfloat* circleVertices;			// wskaŸnik do tablicy wspó³rzêdnych XZ wierzcho³ków u³o¿onych w okr¹g
	GLint circleVerticesCount;			// liczba par w powy¿szej tablicy

public:
	WheelLinks(GLfloat startX, GLfloat startY, GLfloat startZ, GLfloat size, GLboolean wheelsOnTheLeft);
	~WheelLinks();
	void Draw();

private:
	void DrawLink(GLfloat fromX, GLfloat fromZ, GLfloat toX, GLfloat toZ, GLfloat width);
	void DrawConnector(GLfloat x, GLfloat z, GLfloat width);
};

