#pragma once
#include <GLFW/glfw3.h>
#include "../Object/Vector3.h"

class Collider
{
private:
	Vector3 position;
	GLfloat width;
	GLfloat height;

public:
	Collider(Vector3 position, GLfloat width, GLfloat height);
	Vector3 GetPosition();
	bool CollidesWith(Collider collider);
};

