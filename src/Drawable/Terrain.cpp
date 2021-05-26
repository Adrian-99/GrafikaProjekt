#include "Terrain.h"

Terrain::Terrain(std::string name, Vector3 startPosition, GLfloat size) :
	Object(name, startPosition, size)
{
}

GLfloat Terrain::GetApproxHeightAt(Vector2 position)
{
	GLfloat toleranceRadius = 150.0f;

	std::vector<Vector3> verticesAround;

	for (GLint i = 1; i < vertices.size(); i++) {
		if ((vertices.at(i).ToVector2() - position).GetLength() < toleranceRadius) {
			verticesAround.push_back(vertices.at(i));
		}
	}

	GLfloat weights = 0.0f;
	GLfloat heights = 0.0f;

	for (GLint i = 0; i < verticesAround.size(); i++) {
		weights += toleranceRadius - (verticesAround.at(i).ToVector2() - position).GetLength();
		heights += verticesAround.at(i).Z() * (toleranceRadius - (verticesAround.at(i).ToVector2() - position).GetLength());
	}
	if (weights > 0.0f) return heights / weights;
	else return 0.0f;
}
