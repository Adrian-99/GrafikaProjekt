#include "Wheel.h"

Wheel::Wheel(Vector3 startPosition, GLfloat radius, GLfloat width, bool isLeft)
{
	position = startPosition;

	if (isLeft) {
		rimRightEdgeY = 0.0f;
		rimLeftEdgeY = -0.7 * width;
		tireRightEdgeY = 0.15 * width;
		tireLeftEdgeY = -0.85 * width;
	}
	else {
		rimLeftEdgeY = 0.0f;
		rimRightEdgeY = 0.7 * width;
		tireLeftEdgeY = -0.15 * width;
		tireRightEdgeY = 0.85 * width;
	}

	turnAngle = 0.0f;

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
	delete[] rimOuterVertices;
	delete[] tireMiddleVertices;
	delete[] tireOuterVertices;
}

void Wheel::Draw()
{
	glPushMatrix();

	glTranslatef(position.X(), position.Y(), position.Z());
	glRotatef(turnAngle, 0.0f, 0.0f, 1.0f);

	DrawRim();
	DrawTire();

	glPopMatrix();
}

void Wheel::DrawRim()
{
	glColor3f(0.6f, 0.6f, 0.6f);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, rimLeftEdgeY, 0.0f);
	glVertex3f(rimOuterVertices[2 * verticesNumber - 2], rimLeftEdgeY, rimOuterVertices[2 * verticesNumber - 1]);
	for (GLint i = 0; i < verticesNumber; i++) {
		glVertex3f(rimOuterVertices[2 * i], rimLeftEdgeY, rimOuterVertices[2 * i + 1]);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, rimRightEdgeY, 0.0f);
	glVertex3f(rimOuterVertices[0], rimRightEdgeY, rimOuterVertices[1]);
	for (GLint i = verticesNumber - 1; i >= 0; i--) {
		glVertex3f(rimOuterVertices[2 * i], rimRightEdgeY, rimOuterVertices[2 * i + 1]);
	}
	glEnd();
}

void Wheel::DrawTire()
{
	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(rimOuterVertices[2 * verticesNumber - 2], rimLeftEdgeY, rimOuterVertices[2 * verticesNumber - 1]);
	glVertex3f(tireMiddleVertices[2 * verticesNumber - 2], tireLeftEdgeY, tireMiddleVertices[2 * verticesNumber - 1]);
	for (GLint i = 0; i < verticesNumber; i++) {
		glVertex3f(rimOuterVertices[2 * i], rimLeftEdgeY, rimOuterVertices[2 * i + 1]);
		glVertex3f(tireMiddleVertices[2 * i], tireLeftEdgeY, tireMiddleVertices[2 * i + 1]);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(rimOuterVertices[0], rimRightEdgeY, rimOuterVertices[1]);
	glVertex3f(tireMiddleVertices[0], tireRightEdgeY, tireMiddleVertices[1]);
	for (GLint i = verticesNumber - 1; i >= 0; i--) {
		glVertex3f(rimOuterVertices[2 * i], rimRightEdgeY, rimOuterVertices[2 * i + 1]);
		glVertex3f(tireMiddleVertices[2 * i], tireRightEdgeY, tireMiddleVertices[2 * i + 1]);
	}
	glEnd();

	glColor3f(0.1f, 0.05f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(tireMiddleVertices[2 * verticesNumber - 2], tireLeftEdgeY, tireMiddleVertices[2 * verticesNumber - 1]);
	glVertex3f(tireOuterVertices[2 * verticesNumber - 2], tireLeftEdgeY, tireOuterVertices[2 * verticesNumber - 1]);
	for (GLint i = 0; i < verticesNumber; i++) {
		glVertex3f(tireMiddleVertices[2 * i], tireLeftEdgeY, tireMiddleVertices[2 * i + 1]);
		glVertex3f(tireOuterVertices[2 * i], tireLeftEdgeY, tireOuterVertices[2 * i + 1]);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(tireMiddleVertices[0], tireRightEdgeY, tireMiddleVertices[1]);
	glVertex3f(tireOuterVertices[0], tireRightEdgeY, tireOuterVertices[1]);
	for (GLint i = verticesNumber - 1; i >= 0; i--) {
		glVertex3f(tireMiddleVertices[2 * i], tireRightEdgeY, tireMiddleVertices[2 * i + 1]);
		glVertex3f(tireOuterVertices[2 * i], tireRightEdgeY, tireOuterVertices[2 * i + 1]);
	}
	glEnd();

	glColor3f(0.2f, 0.1f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(tireOuterVertices[2 * verticesNumber - 2], tireLeftEdgeY, tireOuterVertices[2 * verticesNumber - 1]);
	glVertex3f(tireOuterVertices[2 * verticesNumber - 2], tireRightEdgeY, tireOuterVertices[2 * verticesNumber - 1]);
	for (GLint i = 0; i < verticesNumber; i++) {
		glVertex3f(tireOuterVertices[2 * i], tireLeftEdgeY, tireOuterVertices[2 * i + 1]);
		glVertex3f(tireOuterVertices[2 * i], tireRightEdgeY, tireOuterVertices[2 * i + 1]);
	}
	glEnd();
}

void Wheel::ChangeYPosition(GLfloat y)
{
	position = Vector3(position.X(), y, position.Z());
}

void Wheel::SetTurnAngle(GLfloat angle)
{
	turnAngle = angle;
}
