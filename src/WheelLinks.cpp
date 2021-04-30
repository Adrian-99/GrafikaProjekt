#include "WheelLinks.h"

WheelLinks::WheelLinks(GLfloat startX, GLfloat startY, GLfloat startZ, GLfloat size, GLboolean wheelsOnTheLeft) :
	wheel1(startX - 65 * size, startY, startZ - 30 * size, size * 20, size * 20),
	wheel2(startX + 10 * size, startY, startZ - 30 * size, size * 20, size * 20),
	wheel3(startX + 70 * size, startY, startZ - 30 * size, size * 20, size * 20)
{
	this->startX = startX;
	this->startY = startY;
	this->startZ = startZ;
	this->size = size;

	if (wheelsOnTheLeft) {
		wheel1.ChangeYPosition(startY - size * 17);
		wheel2.ChangeYPosition(startY - size * 17);
		wheel3.ChangeYPosition(startY - size * 17);
	}
	else {
		wheel1.ChangeYPosition(startY + size * 17);
		wheel2.ChangeYPosition(startY + size * 17);
		wheel3.ChangeYPosition(startY + size * 17);
	}

	circleVerticesCount = 20;
	circleVertices = new GLfloat[circleVerticesCount * 2];

	GLfloat angle, radius = size * 5;
	for (GLint step = 0; step < circleVerticesCount; step++) {
		angle = step * 3.14 * 2 / circleVerticesCount;
		circleVertices[2 * step] = radius * cos(angle);
		circleVertices[2 * step + 1] = radius * sin(angle);
	}
}

WheelLinks::~WheelLinks()
{
	delete[] circleVertices;
}

void WheelLinks::Draw() 
{
	glPushMatrix();

	DrawConnector(startX, startZ, size * 15);
	DrawLink(startX, startZ, startX - 65 * size, startZ - 30 * size, size);
	DrawConnector(startX - 65 * size, startZ - 30 * size, size * 20);
	wheel1.Draw();
	DrawLink(startX, startZ, startX + 40 * size, startZ - 10 * size, size);
	DrawConnector(startX + 40 * size, startZ - 10 * size, size * 15);
	DrawLink(startX + 40 * size, startZ - 10 * size, startX + 10 * size, startZ - 30 * size, size);
	DrawConnector(startX + 10 * size, startZ - 30 * size, size * 20);
	wheel2.Draw();
	DrawLink(startX + 40 * size, startZ - 10 * size, startX + 70 * size, startZ - 30 * size, size);
	DrawConnector(startX + 70 * size, startZ - 30 * size, size * 20);
	wheel3.Draw();

	glPopMatrix();
}

void WheelLinks::DrawLink(GLfloat fromX, GLfloat fromZ, GLfloat toX, GLfloat toZ, GLfloat width)
{
	if (fromX < toX) {
		GLfloat tmp = fromX;
		fromX = toX;
		toX = tmp;
		tmp = fromZ;
		fromZ = toZ;
		toZ = tmp;
	}

	GLint step, stepsCount = 20;
	GLfloat x, y, z;
	GLfloat stepX = (toX - fromX) / stepsCount;
	GLfloat stepZ = (toZ - fromZ) / stepsCount;

	// Top wall
	glColor3f(0.4f, 0.4f, 0.4f);
	glBegin(GL_TRIANGLE_STRIP);
	for (step = 0; step < stepsCount; step++) {
		x = fromX + step * stepX;
		z = fromZ + 2.5 * width + step * stepZ;
		glVertex3f(x, startY - width * 5, z);
		glVertex3f(x, startY + width * 5, z);
	}
	glEnd();

	// Bottom wall
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_TRIANGLE_STRIP);
	for (step = 0; step < stepsCount; step++) {
		x = fromX + step * stepX;
		z = fromZ - 2.5 * width + step * stepZ;
		glVertex3f(x, startY + width * 5, z);
		glVertex3f(x, startY - width * 5, z);
	}
	glEnd();

	// Right wall
	glColor3f(0.35f, 0.35f, 0.35f);
	glBegin(GL_TRIANGLE_STRIP);
	y = startY + width * 5;
	for (step = 0; step < stepsCount; step++) {
		x = fromX + step * stepX;
		z = fromZ + 2.5 * width + step * stepZ;
		glVertex3f(x, y, z);
		glVertex3f(x, y, z - width * 5);
	}
	glEnd();

	// Left wall
	glBegin(GL_TRIANGLE_STRIP);
	y = startY - width * 5;
	for (step = 0; step < stepsCount; step++) {
		x = fromX + step * stepX;
		z = fromZ + 2.5 * width + step * stepZ;
		glVertex3f(x, y, z - width * 5);
		glVertex3f(x, y, z);
	}
	glEnd();
}

void WheelLinks::DrawConnector(GLfloat x, GLfloat z, GLfloat width)
{
	GLint step;
	GLfloat y;

	glColor3f(0.2f, 0.2f, 0.2f);

	// Left wall
	y = startY - width / 2;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(x, y, z);
	glVertex3f(x + circleVertices[2 * circleVerticesCount - 2], y, z + circleVertices[2 * circleVerticesCount - 1]);
	for (step = 0; step < circleVerticesCount; step++) {
		glVertex3f(x + circleVertices[2 * step], y, z + circleVertices[2 * step + 1]);
	}
	glEnd();

	// Right wall
	y = startY + width / 2;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(x, y, z);
	glVertex3f(x + circleVertices[0], y, z + circleVertices[1]);
	for (step = circleVerticesCount - 1; step >= 0; step--) {
		glVertex3f(x + circleVertices[2 * step], y, z + circleVertices[2 * step + 1]);
	}
	glEnd();

	glColor3f(0.22f, 0.22f, 0.22f);

	// Outer wall
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(x + circleVertices[circleVerticesCount * 2 - 2], startY - width / 2, z + circleVertices[circleVerticesCount * 2 - 1]);
	glVertex3f(x + circleVertices[circleVerticesCount * 2 - 2], startY + width / 2, z + circleVertices[circleVerticesCount * 2 - 1]);
	for (step = 0; step < circleVerticesCount; step++) {
		glVertex3f(x + circleVertices[step * 2], startY - width / 2, z + circleVertices[step * 2 + 1]);
		glVertex3f(x + circleVertices[step * 2], startY + width / 2, z + circleVertices[step * 2 + 1]);
	}
	glEnd();
}
