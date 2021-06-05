#include "CollisionController.h"
#include <iostream>

void CollisionController::Initialize(Vector2 startPoint, Vector2 endPoint, GLfloat sectorSize)
{

	sectorsCountX = ceil((endPoint.X() - startPoint.X()) / sectorSize);
	sectorsCountY = ceil((endPoint.Y() - startPoint.Y()) / sectorSize);

	collisionSectors.clear();

	for (GLfloat x = startPoint.X(); x < endPoint.X(); x += sectorSize) {
		for (GLfloat y = startPoint.Y(); y < endPoint.Y(); y += sectorSize) {
			collisionSectors.push_back(CollisionSector(Vector2(x, y), sectorSize));
		}
	}
}

void CollisionController::AddCollider(Vector3 position, GLfloat width, GLfloat height)
{
	for (GLint i = 0; i < collisionSectors.size(); i++) {
		if (collisionSectors.at(i).Contains(position.ToVector2())) {
			collisionSectors.at(i).AddCollider(position, width, height);
			break;
		}
	}
}

std::vector<Vector2> CollisionController::DetectCollisions(Collider collider)
{
	std::vector<Vector2> result;
	std::vector<Vector2> sectorCollisions;

	std::vector<GLint> sectorsToCheck;
	for (GLint i = 0; i < collisionSectors.size(); i++) {
		if (collisionSectors.at(i).Contains(collider.GetPosition().ToVector2())) {
			sectorsToCheck.push_back(i);
			break;
		}
	}
	if (sectorsToCheck.size() > 0) {
		GLint mainSectorY = sectorsToCheck.at(0) % sectorsCountY;
		GLint mainSectorX = sectorsToCheck.at(0) / sectorsCountY;

		if (mainSectorX > 0) sectorsToCheck.push_back((mainSectorX - 1) * sectorsCountY + mainSectorY);
		if (mainSectorX < sectorsCountX - 1) sectorsToCheck.push_back((mainSectorX + 1) * sectorsCountY + mainSectorY);
		if (mainSectorY > 0) sectorsToCheck.push_back(mainSectorX * sectorsCountY + mainSectorY - 1);
		if (mainSectorY < sectorsCountY - 1) sectorsToCheck.push_back(mainSectorX * sectorsCountY + mainSectorY + 1);
		if (mainSectorX > 0 && mainSectorY > 0) sectorsToCheck.push_back((mainSectorX - 1) * sectorsCountY + mainSectorY - 1);
		if (mainSectorX > 0 && mainSectorY < sectorsCountY - 1) sectorsToCheck.push_back((mainSectorX - 1) * sectorsCountY + mainSectorY + 1);
		if (mainSectorX < sectorsCountX - 1 && mainSectorY > 0) sectorsToCheck.push_back((mainSectorX + 1) * sectorsCountY + mainSectorY - 1);
		if (mainSectorX < sectorsCountX - 1 && mainSectorY < sectorsCountY - 1) sectorsToCheck.push_back((mainSectorX + 1) * sectorsCountY + mainSectorY + 1);

		for (GLint i = 0; i < sectorsToCheck.size(); i++) {
			sectorCollisions = collisionSectors.at(sectorsToCheck.at(i)).DetectCollisions(collider);
			result.insert(result.end(), sectorCollisions.begin(), sectorCollisions.end());
		}
		std::cout << collider.GetPosition().X() << ", " << collider.GetPosition().Y() << " - " << mainSectorX << ", " << mainSectorY << std::endl;
	}


	return result;
}

void CollisionController::DrawAllColliders()
{
	for (GLint i = 0; i < collisionSectors.size(); i++) {
		collisionSectors.at(i).DrawAllColliders();
	}
}
