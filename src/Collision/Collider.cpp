#include "Collider.h"

Collider::Collider(Vector3 position, GLfloat width, GLfloat height)
{
	this->position = position;
	this->width = width;
	this->height = height;
}

Vector3 Collider::GetPosition()
{
	return position;
}

void Collider::SetPosition(Vector3 position)
{
	this->position = position;
}

bool Collider::CollidesWith(Collider collider)
{
	if ((position.Z() >= collider.position.Z() && position.Z() <= collider.position.Z() + collider.height) ||
		(collider.position.Z() >= position.Z() && collider.position.Z() <= position.Z() + height)) {
		return (position - collider.position).ToVector2().GetLength() <= (width + collider.width) / 2;
	}
	return false;
}

void Collider::Draw()
{
	GLfloat angle = 0.0f;
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(position.X(), position.Y(), position.Z());
	for (GLint i = 0; i < 20; i++) {
		angle = i * 3.14 / 10;
		glVertex3f(position.X() + cos(angle) * width / 2, position.Y() + sin(angle) * width / 2, position.Z());
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(position.X(), position.Y(), position.Z() + height);
	for (GLint i = 0; i < 20; i++) {
		angle = i * 3.14 / 10;
		glVertex3f(position.X() + cos(angle) * width / 2, position.Y() + sin(angle) * width / 2, position.Z() + height);
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(position.X() + width / 2, position.Y(), position.Z());
	glVertex3f(position.X() + width / 2, position.Y(), position.Z() + height);
	for (GLint i = 19; i >= 0; i--) {
		angle = i * 3.14 / 10;
		glVertex3f(position.X() + cos(angle) * width / 2, position.Y() + sin(angle) * width / 2, position.Z());
		glVertex3f(position.X() + cos(angle) * width / 2, position.Y() + sin(angle) * width / 2, position.Z() + height);
	}
	glEnd();
	glPopMatrix();
}
