#include "WheelLinks.h"

WheelLinks::WheelLinks(Vector3 startPosition, GLfloat size, GLboolean wheelsOnTheLeft) :
	wheel1(Vector3(-65 * size, 0.0f, -30 * size), size * 20, size * 20, wheelsOnTheLeft),
	wheel2(Vector3(10 * size, 0.0f, -30 * size), size * 20, size * 20, wheelsOnTheLeft),
	wheel3(Vector3(70 * size, 0.0f, -30 * size), size * 20, size * 20, wheelsOnTheLeft)
{
	this->position = startPosition;
	this->size = size;
	this->leftSide = wheelsOnTheLeft;

	if (wheelsOnTheLeft) {
		wheel1.ChangeYPosition(-size * 17);
		wheel2.ChangeYPosition(-size * 17);
		wheel3.ChangeYPosition(-size * 17);
	}
	else {
		wheel1.ChangeYPosition(size * 17);
		wheel2.ChangeYPosition(size * 17);
		wheel3.ChangeYPosition(size * 17);
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

	glTranslatef(position.X(), position.Y(), position.Z());

	DrawConnector(0.0f, 0.0f, size * 15);
	DrawLink(0.0f, 0.0f, -65.0f * size, -30.0f * size, size);
	DrawConnector(-65.0f * size, -30.0f * size, size * 15, true, leftSide);
	wheel1.Draw();
	DrawLink(0.0f, 0.0f, 40.0f * size, -10.0f * size, size);
	DrawConnector(40.0f * size, -10.0f * size, size * 15);
	DrawLink(40.0f * size, -10.0f * size, 10.0f * size, -30.0f * size, size);
	DrawConnector(10.0f * size, -30.0f * size, size * 15, true, leftSide);
	wheel2.Draw();
	DrawLink(40.0f * size, -10.0f * size, 70.0f * size, -30.0f * size, size);
	DrawConnector(70.0f * size, -30.0f * size, size * 15, true, leftSide);
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
		glVertex3f(x, -width * 5, z);
		glVertex3f(x, width * 5, z);
	}
	glEnd();

	// Bottom wall
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_TRIANGLE_STRIP);
	for (step = 0; step < stepsCount; step++) {
		x = fromX + step * stepX;
		z = fromZ - 2.5 * width + step * stepZ;
		glVertex3f(x, width * 5, z);
		glVertex3f(x, -width * 5, z);
	}
	glEnd();

	// Right wall
	glColor3f(0.35f, 0.35f, 0.35f);
	glBegin(GL_TRIANGLE_STRIP);
	y = width * 5;
	for (step = 0; step < stepsCount; step++) {
		x = fromX + step * stepX;
		z = fromZ + 2.5 * width + step * stepZ;
		glVertex3f(x, y, z);
		glVertex3f(x, y, z - width * 5);
	}
	glEnd();

	// Left wall
	glBegin(GL_TRIANGLE_STRIP);
	y = -width * 5;
	for (step = 0; step < stepsCount; step++) {
		x = fromX + step * stepX;
		z = fromZ + 2.5 * width + step * stepZ;
		glVertex3f(x, y, z - width * 5);
		glVertex3f(x, y, z);
	}
	glEnd();
}

void WheelLinks::DrawConnector(GLfloat x, GLfloat z, GLfloat width, bool extraWidth, bool leftExtraWidth)
{
	GLint step;
	GLfloat leftY, rightY;

	if (extraWidth && leftExtraWidth) leftY = -width * 1.5;
	else leftY = -width / 2;
	if (extraWidth && !leftExtraWidth) rightY = width * 1.5;
	else rightY = width / 2;

	glColor3f(0.2f, 0.2f, 0.2f);

	// Left wall
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(x, leftY, z);
	glVertex3f(x + circleVertices[2 * circleVerticesCount - 2], leftY, z + circleVertices[2 * circleVerticesCount - 1]);
	for (step = 0; step < circleVerticesCount; step++) {
		glVertex3f(x + circleVertices[2 * step], leftY, z + circleVertices[2 * step + 1]);
	}
	glEnd();

	// Right wall
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(x, rightY, z);
	glVertex3f(x + circleVertices[0], rightY, z + circleVertices[1]);
	for (step = circleVerticesCount - 1; step >= 0; step--) {
		glVertex3f(x + circleVertices[2 * step], rightY, z + circleVertices[2 * step + 1]);
	}
	glEnd();

	glColor3f(0.22f, 0.22f, 0.22f);

	// Outer wall
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(x + circleVertices[circleVerticesCount * 2 - 2], leftY, z + circleVertices[circleVerticesCount * 2 - 1]);
	glVertex3f(x + circleVertices[circleVerticesCount * 2 - 2], rightY, z + circleVertices[circleVerticesCount * 2 - 1]);
	for (step = 0; step < circleVerticesCount; step++) {
		glVertex3f(x + circleVertices[step * 2], leftY, z + circleVertices[step * 2 + 1]);
		glVertex3f(x + circleVertices[step * 2], rightY, z + circleVertices[step * 2 + 1]);
	}
	glEnd();
}

void WheelLinks::TurnWheels(GLfloat turnAngle)
{
	wheel1.SetTurnAngle(turnAngle);
	wheel3.SetTurnAngle(-0.5 * turnAngle);
}
