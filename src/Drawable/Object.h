#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <GLFW/glfw3.h>
#include "../Object/Helpers.h"
#include "../Object/Vertex.h"
#include "../Object/Material.h"

class Object
{
private:
	static std::string loadingPath;

	std::string name;
	std::vector<Vertex> vertices;
	std::vector<Vertex> normals;
	std::vector<std::string> materials;
	std::vector<int> vertexIndices;
	std::vector<int> normalIndices;
	std::vector<int> materialStartIndices;

public:
	Object(std::string name, GLfloat x, GLfloat y, GLfloat z, GLfloat size = 1.0f);
	void Draw();
	void DrawDuplicate(Vertex offset);
};

