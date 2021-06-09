#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <GLFW/glfw3.h>
#include "../Object/Helpers.h"
#include "../Object/Vector2.h"
#include "../Object/Vector3.h"
#include "../Object/Material.h"
#include "../Collision/CollisionController.h"

class Object
{
protected:
	static std::string loadingPath;				// œcie¿ka do folderu, w którym znajduj¹ siê pliki .obj

	std::string name;							// nazwa pliku .obj
	std::vector<Vector3> vertices;				// lista wspó³rzednych wierzcho³ków obiektu
	std::vector<Vector2> textureCoords;			// lista koordynatów tekstury obiektu
	std::vector<Vector3> normals;				// lista normalnych obiektu
	std::vector<std::string> materials;			// lista materia³ów u¿ywanych przez obiekt
	std::vector<int> vertexIndices;				// lista kolejnoœci u¿ywania wierzcho³ków
	std::vector<int> textureCoordsIndices;		// lista kolejnoœci u¿ywania koordynatów tekstury
	std::vector<int> normalIndices;				// lista kolejnoœci u¿ywania normalnych
	std::vector<int> materialStartIndices;		// lista startowych wierzcho³ków, u¿ywaj¹cych poszczególne materia³y

	std::vector<Vector3> duplicateOffsets;		// lista przesuniêæ duplikatów obiektów
	std::vector<GLfloat> duplicateRotations;	// lista k¹tów obrotów duplikatów obiektów

public:
	Object(std::string name, Vector3 startPosition = Vector3(), GLfloat size = 1.0f, CollisionController* collisionController = nullptr);
	int AddDuplicate(Vector3 offset, GLfloat rotationAngle = 0.0f, CollisionController* collisionController = nullptr);
	void Draw();
	void DrawDuplicate(int duplicateIndex = -1);
	Vector3 GetMinPoint();
	Vector3 GetMaxPoint();

private:
	void DrawObject(Vector3 offset = Vector3(), GLfloat rotationAngle = 0.0f);
	void AddCollider(CollisionController* collisionController, Vector3 offset = Vector3(), GLfloat rotationAngle = 0.0f);
};

