#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <GLFW/glfw3.h>
#include "Vertex.h"

class Object
{
private:
	const char* filePath;
	std::vector<Vertex> vertices;
	std::vector<int> vertexIndices;

public:
	Object(const char* filePath, GLfloat x, GLfloat y, GLfloat z, GLfloat size = 1.0f);
	void Draw();

private:
	static std::vector<std::string> SplitString(std::string text, char delim = ' ', bool ignoreEmpty = true);
};

