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

class Object
{
protected:
	static std::string loadingPath;			// �cie�ka do folderu, w kt�rym znajduj� si� pliki .obj

	std::string name;						// nazwa pliku .obj
	std::vector<Vector3> vertices;			// lista wsp�rzednych wierzcho�k�w obiektu
	std::vector<Vector2> textureCoords;		// lista koordynat�w tekstury obiektu
	std::vector<Vector3> normals;			// lista normalnych obiektu
	std::vector<std::string> materials;		// lista materia��w u�ywanych przez obiekt
	std::vector<int> vertexIndices;			// lista kolejno�ci u�ywania wierzcho�k�w
	std::vector<int> textureCoordsIndices;	// lista kolejno�ci u�ywania koordynat�w tekstury
	std::vector<int> normalIndices;			// lista kolejno�ci u�ywania normalnych
	std::vector<int> materialStartIndices;	// lista startowych wierzcho�k�w, u�ywaj�cych poszczeg�lne materia�y

	std::vector<Vector3> duplicateOffsets;
	std::vector<GLfloat> duplicateRotations;

public:
	Object(std::string name, Vector3 startPosition = Vector3(), GLfloat size = 1.0f);
	int AddDuplicate(Vector3 offset, GLfloat rotationAngle = 0.0f);
	void Draw();
	void DrawDuplicate(int duplicateIndex = -1);

private:
	void DrawObject(Vector3 offset = Vector3(), GLfloat rotationAngle = 0.0f);
};

