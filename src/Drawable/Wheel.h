#pragma once
#include <GLFW/glfw3.h>
#include <cmath>
#include "../Object/Vector3.h"

class Wheel
{
private:
	Vector3 position;			// pozycja ko�a
	GLfloat rotationAngle;			// k�t obrotu ko�a
	GLfloat tireLeftEdgeY;
	GLfloat tireRightEdgeY;
	GLfloat rimLeftEdgeY;
	GLfloat rimRightEdgeY;
	GLfloat* rimOuterVertices;		// wska�nik do tablicy wsp�rz�dnych XZ wierzcho�k�w zewn�trznych felgi
	GLfloat* tireMiddleVertices;	// wska�nik do tablicy wsp�rz�dnych XZ wierzcho�k�w �rodkowych opony
	GLfloat* tireOuterVertices;		// wska�nik do tablicy wsp�rz�dnych XZ wierzcho�k�w zewn�trznych opony
	GLint verticesNumber;			// liczba par element�w w powy�szych tablicach

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

