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
	static std::vector<Material> materials;			// lista wszystkich za³adowanych materia³ów
	static std::vector<std::string> textureNames;	// lista nazw za³adowanych tekstur
	static std::vector<GLuint> textureIds;			// lista idnetyfikatorów za³adownych tekstur

	std::string materialName;		// nazwa materia³u
	std::string objectName;			// nazwa obiektu, do którego nale¿y dany materia³
	Vector3 ambientColor;			// kolor ambientowy
	Vector3 diffuseColor;			// kolor dyfuzyjny
	Vector3 specularColor;			// kolor po³ysku
	Vector3 emissionColor;			// kolor emitowany
	GLfloat shininess;				// po³ysk
	GLuint textureId;				// identyfikator tekstury

public:
	Material(std::string materialName, std::string objectName);
	void Use();
	static void StopUsing();

	static void Add(std::string loadingPath, std::string materialFileName, std::string objectName);
	static Material& Find(std::string materialName, std::string objectName);
	static GLuint LoadTexture(std::string filePath);
};

