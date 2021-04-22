#include "Wheel.h"

Wheel::Wheel(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLfloat width)
{
	position = new GLfloat[3];
	position[0] = x;
	position[1] = y;
	position[2] = z;

	halfTireWidth = width / 2;
	halfRimWidth = halfTireWidth * 0.7;

	verticesNumber = 128;
	rimOuterVertices = new GLfloat[verticesNumber * 2];
	tireMiddleVertices = new GLfloat[verticesNumber * 2];
	tireOuterVertices = new GLfloat[verticesNumber * 2];

	GLfloat angle;
	GLfloat rimRadius = radius * 0.6;
	GLfloat tireMiddleRadius = radius * 0.8;
	GLfloat tireTreadRadius = radius * 0.97;

	for (GLint step = 0; step < verticesNumber; step++) {
		angle = step * 3.14 * 2 / verticesNumber;

		rimOuterVertices[2 * step] = rimRadius * cos(angle);
		rimOuterVertices[2 * step + 1] = rimRadius * sin(angle);

		tireMiddleVertices[2 * step] = tireMiddleRadius * cos(angle);
		tireMiddleVertices[2 * step + 1] = tireMiddleRadius * sin(angle);

		if ((step / 2) % 2) {
			tireOuterVertices[2 * step] = radius * cos(angle);
			tireOuterVertices[2 * step + 1] = radius * sin(angle);
		}
		else {
			tireOuterVertices[2 * step] = tireTreadRadius * cos(angle);
			tireOuterVertices[2 * step + 1] = tireTreadRadius * sin(angle);
		}
	}
}

Wheel::~Wheel()
{
	delete[] position;
	delete[] rimOuterVertices;
	delete[] tireMiddleVertices;
	delete[] tireOuterVertices;
}

void Wheel::Draw()
{
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_NONE);

	glPushMatrix();

	DrawRim();
	DrawTire();

	glPopMatrix();
}

void Wheel::DrawRim()
{
	glColor3f(0.6f, 0.6f, 0.6f);

	GLfloat rimYpos = position[1] - halfRimWidth;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(position[0], rimYpos, position[2]);
	glVertex3f(position[0] + rimOuterVertices[2 * verticesNumber - 2], rimYpos, position[2] + rimOuterVertices[2 * verticesNumber - 1]);
	for (GLint i = 0; i < verticesNumber; i++) {
		glVertex3f(position[0] + rimOuterVertices[2 * i], rimYpos, position[2] + rimOuterVertices[2 * i + 1]);
	}
	glEnd();

	rimYpos = position[1] + halfRimWidth;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(position[0], rimYpos, position[2]);
	glVertex3f(position[0] + rimOuterVertices[0], rimYpos, position[2] + rimOuterVertices[1]);
	for (GLint i = verticesNumber - 1; i >= 0; i--) {
		glVertex3f(position[0] + rimOuterVertices[2 * i], rimYpos, position[2] + rimOuterVertices[2 * i + 1]);
	}
	glEnd();
}

void Wheel::DrawTire()
{
	glColor3f(0.0f, 0.0f, 0.0f);

	GLfloat rimYpos = position[1] - halfRimWidth;
	GLfloat tireYpos = position[1] - halfTireWidth;
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(position[0] + rimOuterVertices[2 * verticesNumber - 2], rimYpos, position[2] + rimOuterVertices[2 * verticesNumber - 1]);
	glVertex3f(position[0] + tireMiddleVertices[2 * verticesNumber - 2], tireYpos, position[2] + tireMiddleVertices[2 * verticesNumber - 1]);
	for (GLint i = 0; i < verticesNumber; i++) {
		glVertex3f(position[0] + rimOuterVertices[2 * i], rimYpos, position[2] + rimOuterVertices[2 * i + 1]);
		glVertex3f(position[0] + tireMiddleVertices[2 * i], tireYpos, position[2] + tireMiddleVertices[2 * i + 1]);
	}
	glEnd();

	rimYpos = position[1] + halfRimWidth;
	tireYpos = position[1] + halfTireWidth;
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(position[0] + rimOuterVertices[0], rimYpos, position[2] + rimOuterVertices[1]);
	glVertex3f(position[0] + tireMiddleVertices[0], tireYpos, position[2] + tireMiddleVertices[1]);
	for (GLint i = verticesNumber - 1; i >= 0; i--) {
		glVertex3f(position[0] + rimOuterVertices[2 * i], rimYpos, position[2] + rimOuterVertices[2 * i + 1]);
		glVertex3f(position[0] + tireMiddleVertices[2 * i], tireYpos, position[2] + tireMiddleVertices[2 * i + 1]);
	}
	glEnd();

	glColor3f(0.1f, 0.05f, 0.0f);
	tireYpos = position[1] - halfTireWidth;
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(position[0] + tireMiddleVertices[2 * verticesNumber - 2], tireYpos, position[2] + tireMiddleVertices[2 * verticesNumber - 1]);
	glVertex3f(position[0] + tireOuterVertices[2 * verticesNumber - 2], tireYpos, position[2] + tireOuterVertices[2 * verticesNumber - 1]);
	for (GLint i = 0; i < verticesNumber; i++) {
		glVertex3f(position[0] + tireMiddleVertices[2 * i], tireYpos, position[2] + tireMiddleVertices[2 * i + 1]);
		glVertex3f(position[0] + tireOuterVertices[2 * i], tireYpos, position[2] + tireOuterVertices[2 * i + 1]);
	}
	glEnd();

	tireYpos = position[1] + halfTireWidth;
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(position[0] + tireMiddleVertices[0], tireYpos, position[2] + tireMiddleVertices[1]);
	glVertex3f(position[0] + tireOuterVertices[0], tireYpos, position[2] + tireOuterVertices[1]);
	for (GLint i = verticesNumber - 1; i >= 0; i--) {
		glVertex3f(position[0] + tireMiddleVertices[2 * i], tireYpos, position[2] + tireMiddleVertices[2 * i + 1]);
		glVertex3f(position[0] + tireOuterVertices[2 * i], tireYpos, position[2] + tireOuterVertices[2 * i + 1]);
	}
	glEnd();

	glColor3f(0.2f, 0.1f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(position[0] + tireOuterVertices[2 * verticesNumber - 2], position[1] - halfTireWidth, position[2] + tireOuterVertices[2 * verticesNumber - 1]);
	glVertex3f(position[0] + tireOuterVertices[2 * verticesNumber - 2], position[1] + halfTireWidth, position[2] + tireOuterVertices[2 * verticesNumber - 1]);
	for (GLint i = 0; i < verticesNumber; i++) {
		glVertex3f(position[0] + tireOuterVertices[2 * i], position[1] - halfTireWidth, position[2] + tireOuterVertices[2 * i + 1]);
		glVertex3f(position[0] + tireOuterVertices[2 * i], position[1] + halfTireWidth, position[2] + tireOuterVertices[2 * i + 1]);
	}
	glEnd();
}
