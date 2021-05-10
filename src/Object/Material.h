#pragma once
#include <stb_image.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <GLFW/glfw3.h>
#include "Vector3.h"
#include "Helpers.h"

class Material
{
private:
	static std::vector<Material> materials;
	static std::vector<std::string> textureNames;
	static std::vector<GLuint> textureIds;

	std::string materialName;
	std::string objectName;
	Vector3 ambientColor;
	Vector3 diffuseColor;
	Vector3 specularColor;
	Vector3 emissionColor;
	GLfloat shininess;
	GLuint textureId;

public:
	Material(std::string materialName, std::string objectName);
	void Use();
	static void StopUsing();

	static void Add(std::string loadingPath, std::string materialFileName, std::string objectName);
	static Material Find(std::string materialName, std::string objectName);
	static GLuint LoadTexture(std::string filePath);
};

