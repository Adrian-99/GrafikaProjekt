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

bool Collider::CollidesWith(Collider collider)
{
	if ((position.Z() >= collider.position.Z() && position.Z() <= collider.position.Z() + collider.height) ||
		(collider.position.Z() >= position.Z() && collider.position.Z() <= position.Z() + height)) {
		return (position - collider.position).ToVector2().GetLength() <= (width + collider.width) / 2;
	}
	return false;
}
