#include "Terrain.h"

Terrain::Terrain(std::string name, Vector3 startPosition, GLfloat size, GLint heightMapOptimization) :
	Object(name, startPosition, size)
{
	this->heightMapOptimization = heightMapOptimization;

	GLfloat minX = vertices.at(0).X() / heightMapOptimization;
	GLfloat maxX = vertices.at(0).X() / heightMapOptimization;
	GLfloat minY = vertices.at(0).Y() / heightMapOptimization;
	GLfloat maxY = vertices.at(0).Y() / heightMapOptimization;

	for (GLint i = 1; i < vertices.size(); i++) {
		if (vertices.at(i).X() / heightMapOptimization < minX) minX = vertices.at(i).X() / heightMapOptimization;
		else if (vertices.at(i).X() / heightMapOptimization > maxX) maxX = vertices.at(i).X() / heightMapOptimization;
		if (vertices.at(i).Y() / heightMapOptimization < minY) minY = vertices.at(i).Y() / heightMapOptimization;
		else if (vertices.at(i).Y() / heightMapOptimization > maxY) maxY = vertices.at(i).Y() / heightMapOptimization;
	}

	heightMapMinX = (GLint)round(minX);
	heightMapMaxX = (GLint)round(maxX);
	heightMapMinY = (GLint)round(minY);
	heightMapMaxY = (GLint)round(maxY);

	heightMapDimensionX = heightMapMaxX - heightMapMinX + 1;
	heightMapDimensionY = heightMapMaxY - heightMapMinY + 1;

	heightMap = new GLfloat * [heightMapDimensionX];
	GLint** occurances = new GLint * [heightMapDimensionX];
	for (GLint i = 0; i < heightMapDimensionX; i++) {
		heightMap[i] = new GLfloat[heightMapDimensionY]{};
		occurances[i] = new GLint[heightMapDimensionY]{};
	}


	GLint tmpX, tmpY;
	GLint* occurancesPtr;
	GLfloat* heightMapPtr;

	for (GLint i = 0; i < vertices.size(); i++) {
		tmpX = (GLint)round(vertices.at(i).X() / heightMapOptimization);
		tmpY = (GLint)round(vertices.at(i).Y() / heightMapOptimization);
		occurancesPtr = &occurances[tmpX - heightMapMinX][tmpY - heightMapMinY];
		heightMapPtr = &heightMap[tmpX - heightMapMinX][tmpY - heightMapMinY];

		if (*occurancesPtr == 0) *heightMapPtr = vertices.at(i).Z();
		else *heightMapPtr = (*heightMapPtr * *occurancesPtr + vertices.at(i).Z()) / (*occurancesPtr + 1);

		*occurancesPtr += 1;
	}

	GLint unknownHeights;
	GLint knownHeightsAround;
	GLfloat sumOfHeightsAround;
	do {
		unknownHeights = 0;
		for (GLint i = 0; i < heightMapDimensionX; i++) {
			for (GLint j = 0; j < heightMapDimensionY; j++) {
				if (occurances[i][j] > 0) continue;
				knownHeightsAround = 0;
				sumOfHeightsAround = 0.0f;
				if (i > 0 && occurances[i - 1][j] > 0) {
					knownHeightsAround++;
					sumOfHeightsAround += heightMap[i - 1][j];
				}
				if (i < heightMapDimensionX - 1 && occurances[i + 1][j] > 0) {
					knownHeightsAround++;
					sumOfHeightsAround += heightMap[i + 1][j];
				}
				if (j > 0 && occurances[i][j - 1] > 0) {
					knownHeightsAround++;
					sumOfHeightsAround += heightMap[i][j - 1];
				}
				if (j < heightMapDimensionY - 1 && occurances[i][j + 1] > 0) {
					knownHeightsAround++;
					sumOfHeightsAround += heightMap[i][j + 1];
				}
				heightMap[i][j] = sumOfHeightsAround / knownHeightsAround;
				occurances[i][j] = 1;
			}
		}

	} while (unknownHeights);

	for (GLint i = 0; i < heightMapDimensionX; i++) delete[] occurances[i];
	delete[] occurances;
}

Terrain::~Terrain()
{
	for (GLint i = 0; i < heightMapDimensionX; i++) delete[] heightMap[i];
	delete[] heightMap;
}

GLfloat Terrain::GetApproxHeightAt(Vector2 position)
{
	GLint convertedX = (GLint)round(position.X() / heightMapOptimization) - heightMapMinX;
	GLint convertedY = (GLint)round(position.Y() / heightMapOptimization) - heightMapMinY;
	if (convertedX >= 0 && convertedX < heightMapDimensionX && convertedY >= 0 && convertedY < heightMapDimensionY)
		return heightMap[convertedX][convertedY];
	return 0.0f;
}

void Terrain::DrawHeightMap()
{
	glPushMatrix();

	glColor3f(1.0f, 1.0f, 0.0f);

	for (GLint i = 0; i < heightMapDimensionX - 1; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (GLint j = 0; j < heightMapDimensionY; j++) {
			glVertex3f((i + heightMapMinX) * heightMapOptimization, (j + heightMapMinY) * heightMapOptimization, heightMap[i][j]);
			glVertex3f((i + heightMapMinX + 1) * heightMapOptimization, (j + heightMapMinY) * heightMapOptimization, heightMap[i + 1][j]);
		}
		glEnd();
	}

	glPopMatrix();
}
