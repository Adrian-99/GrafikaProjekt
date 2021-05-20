#pragma once
#include <GLFW/glfw3.h>
#include <cmath>
#include "../Object/Vector3.h"

class Wheel
{
private:
	Vector3 position;			// pozycja ko³a
	GLfloat rotationAngle;			// k¹t obrotu ko³a
	GLfloat tireLeftEdgeY;
	GLfloat tireRightEdgeY;
	GLfloat rimLeftEdgeY;
	GLfloat rimRightEdgeY;
	GLfloat* rimOuterVertices;		// wskaŸnik do tablicy wspó³rzêdnych XZ wierzcho³ków zewnêtrznych felgi
	GLfloat* tireMiddleVertices;	// wskaŸnik do tablicy wspó³rzêdnych XZ wierzcho³ków œrodkowych opony
	GLfloat* tireOuterVertices;		// wskaŸnik do tablicy wspó³rzêdnych XZ wierzcho³ków zewnêtrznych opony
	GLint verticesNumber;			// liczba par elementów w powy¿szych tablicach

	GLfloat turnAngle;

public:
	Wheel(Vector3 startPosition, GLfloat radius, GLfloat width, bool isLeft);
	~Wheel();
	void Draw();
	void ChangeYPosition(GLfloat y);
	void SetTurnAngle(GLfloat angle);
	void AddRotationAngle(GLfloat angle);

private:
	void DrawRim();
	void DrawTire();
};

