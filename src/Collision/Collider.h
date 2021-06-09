#pragma once
#include <GLFW/glfw3.h>
#include "../Object/Vector3.h"

class Collider
{
private:
	Vector3 position;	// pozycja obiektu
	GLfloat width;		// œrednica
	GLfloat height;		// wysokoœæ

public:
	Collider(Vector3 position, GLfloat width, GLfloat height);
	Vector3 GetPosition();
	void SetPosition(Vector3 position);
	bool CollidesWith(Collider collider);

	void Draw();
};

