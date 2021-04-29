#pragma once
#include <GLFW/glfw3.h>
#include <cmath>

class Wheel
{
private:
	GLfloat* position;				// pozycja ko³a
	GLfloat halfTireWidth;			// po³owa szerokoœci opony
	GLfloat halfRimWidth;			// po³owa szerokoœci felgi
	GLfloat* rimOuterVertices;		// wskaŸnik do tablicy wspó³rzêdnych XZ wierzcho³ków zewnêtrznych felgi
	GLfloat* tireMiddleVertices;	// wskaŸnik do tablicy wspó³rzêdnych XZ wierzcho³ków œrodkowych opony
	GLfloat* tireOuterVertices;		// wskaŸnik do tablicy wspó³rzêdnych XZ wierzcho³ków zewnêtrznych opony
	GLint verticesNumber;			// liczba par elementów w powy¿szych tablicach

public:
	Wheel(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLfloat width);
	~Wheel();
	void Draw();
	void ChangeYPosition(GLfloat y);

private:
	void DrawRim();
	void DrawTire();
};

