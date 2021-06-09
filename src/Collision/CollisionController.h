#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include "CollisionSector.h"
#include "Collider.h"
#include "../Object/Vector2.h"

class CollisionController
{
private:
	std::vector<CollisionSector> collisionSectors;	// lista sektorów obs³ugiwanych przez kontroler
	GLint sectorsCountX;							// liczba sektorów w osi X
	GLint sectorsCountY;							// liczba sektorów w osi Y

public:
	void Initialize(Vector2 startPoint, Vector2 endPoint, GLfloat sectorSize);
	void AddCollider(Vector3 position, GLfloat width, GLfloat height);
	std::vector<Vector2> DetectCollisions(Collider collider);

	void DrawAllColliders();
};

