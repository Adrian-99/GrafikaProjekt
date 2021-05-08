#pragma once
#include <GLFW/glfw3.h>
#include <cmath>

class Wheel
{
private:
	GLfloat* position;				// pozycja ko�a
	GLfloat halfTireWidth;			// po�owa szeroko�ci opony
	GLfloat halfRimWidth;			// po�owa szeroko�ci felgi
	GLfloat* rimOuterVertices;		// wska�nik do tablicy wsp�rz�dnych XZ wierzcho�k�w zewn�trznych felgi
	GLfloat* tireMiddleVertices;	// wska�nik do tablicy wsp�rz�dnych XZ wierzcho�k�w �rodkowych opony
	GLfloat* tireOuterVertices;		// wska�nik do tablicy wsp�rz�dnych XZ wierzcho�k�w zewn�trznych opony
	GLint verticesNumber;			// liczba par element�w w powy�szych tablicach

public:
	Wheel(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLfloat width);
	~Wheel();
	void Draw();
	void ChangeYPosition(GLfloat y);

private:
	void DrawRim();
	void DrawTire();
};

