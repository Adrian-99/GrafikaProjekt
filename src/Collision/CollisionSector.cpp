#include "CollisionSector.h"

CollisionSector::CollisionSector(Vector2 startPoint, GLfloat size)
{
	this->startPoint = startPoint;
	this->endPoint = startPoint + Vector2(size, size);

	colliders.clear();
}

bool CollisionSector::Contains(Vector2 point)
{
	return point >= startPoint && point < endPoint;
}

void CollisionSector::AddCollider(Vector3 position, GLfloat width, GLfloat height)
{
	colliders.push_back(Collider(position, width, height));
}

std::vector<Vector2> CollisionSector::DetectCollisions(Collider collider)
{
	std::vector<Vector2> result;
	for (GLint i = 0; i < colliders.size(); i++) {
		if (collider.CollidesWith(colliders.at(i))) {
			result.push_back((colliders.at(i).GetPosition() - collider.GetPosition()).ToVector2());
		}
	}
	return result;
}

void CollisionSector::DrawAllColliders()
{
	for (GLint i = 0; i < colliders.size(); i++) {
		colliders.at(i).Draw();
	}
}
