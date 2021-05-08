#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <GLFW/glfw3.h>
#include "../Object/Vertex.h"

class Object
{
private:
	std::vector<Vertex> vertices;
	std::vector<Vertex> normals;
	std::vector<int> vertexIndices;
	std::vector<int> normalIndices;

public:
	Object(const char* filePath, GLfloat x, GLfloat y, GLfloat z, GLfloat size = 1.0f);
	void Draw();
	void DrawDuplicate(Vertex offset);

private:
	static std::vector<std::string> SplitString(std::string text, char delim = ' ', bool ignoreEmpty = true);
};

