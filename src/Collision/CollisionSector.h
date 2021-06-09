#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include "../Object/Vector2.h"
#include "Collider.h"

class CollisionSector
{
private:
	Vector2 startPoint;					// pocz¹tkowe wspó³rzêdne XY sektora
	Vector2 endPoint;					// koñcowe wspó³rzêdne XY sektora
	std::vector<Collider> colliders;	// lista obiektów, znajduj¹ych siê w sektorze

public:
	CollisionSector(Vector2 startPoint, GLfloat size);
	bool Contains(Vector2 point);
	void AddCollider(Vector3 position, GLfloat width, GLfloat height);
	std::vector<Vector2> DetectCollisions(Collider collider);

	void DrawAllColliders();
};

