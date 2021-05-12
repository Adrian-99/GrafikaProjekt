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
private:
	static std::string loadingPath;			// œcie¿ka do folderu, w którym znajduj¹ siê pliki .obj

	std::string name;						// nazwa pliku .obj
	std::vector<Vector3> vertices;			// lista wspó³rzednych wierzcho³ków obiektu
	std::vector<Vector2> textureCoords;		// lista koordynatów tekstury obiektu
	std::vector<Vector3> normals;			// lista normalnych obiektu
	std::vector<std::string> materials;		// lista materia³ów u¿ywanych przez obiekt
	std::vector<int> vertexIndices;			// lista kolejnoœci u¿ywania wierzcho³ków
	std::vector<int> textureCoordsIndices;	// lista kolejnoœci u¿ywania koordynatów tekstury
	std::vector<int> normalIndices;			// lista kolejnoœci u¿ywania normalnych
	std::vector<int> materialStartIndices;	// lista startowych wierzcho³ków, u¿ywaj¹cych poszczególne materia³y

public:
	Object(std::string name, GLfloat x, GLfloat y, GLfloat z, GLfloat size = 1.0f);
	void Draw();
	void DrawDuplicate(Vector3 offset, GLfloat rotationAngle = 0.0f);
};

