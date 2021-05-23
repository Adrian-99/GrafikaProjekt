#pragma once
#include "Object.h"

class Terrain : public Object
{
private:
	GLfloat** heightMap;
	GLint heightMapMinX;
	GLint heightMapMaxX;
	GLint heightMapMinY;
	GLint heightMapMaxY;
	GLint heightMapDimensionX;
	GLint heightMapDimensionY;
	GLint heightMapOptimization;

public:
	Terrain(std::string name, Vector3 startPosition = Vector3(), GLfloat size = 1.0f, GLint heightMapOptimization = 10);
	~Terrain();
	GLfloat GetApproxHeightAt(Vector2 position);

	void DrawHeightMap();
};

