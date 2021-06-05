#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include "../Object/Vector2.h"
#include "Collider.h"

class CollisionSector
{
private:
	Vector2 startPoint;
	Vector2 endPoint;
	std::vector<Collider> colliders;

public:
	CollisionSector(Vector2 startPoint, GLfloat size);
	bool Contains(Vector2 point);
	void AddCollider(Vector3 position, GLfloat width, GLfloat height);
	std::vector<Vector2> DetectCollisions(Collider collider);

	void DrawAllColliders();
};

