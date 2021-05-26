#pragma once
#include <vector>
#include "Object.h"

class Terrain : public Object
{
public:
	Terrain(std::string name, Vector3 startPosition = Vector3(), GLfloat size = 1.0f);
	GLfloat GetApproxHeightAt(Vector2 position);
};

