#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <GLFW/glfw3.h>
#include "Color.h"
#include "Helpers.h"

class Material
{
private:
	static std::vector<Material> materials;

	std::string materialName;
	std::string objectName;
	Color ambientColor;
	Color diffuseColor;
	Color specularColor;
	Color emissionColor;
	GLfloat shininess;

public:
	Material(std::string materialName, std::string objectName);
	void Use();
	static void StopUsing();

	static void Add(std::string filePath, std::string objectName);
	static Material Find(std::string materialName, std::string objectName);
};

