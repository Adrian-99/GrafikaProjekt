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
	static std::vector<Material> materials;			// lista wszystkich załadowanych materiałów
	static std::vector<std::string> textureNames;	// lista nazw załadowanych tekstur
	static std::vector<GLuint> textureIds;			// lista idnetyfikatorów załadownych tekstur

	std::string materialName;		// nazwa materiału
	std::string objectName;			// nazwa obiektu, do którego należy dany materiał
	Vector3 ambientColor;			// kolor ambientowy
	Vector3 diffuseColor;			// kolor dyfuzyjny
	Vector3 specularColor;			// kolor połysku
	Vector3 emissionColor;			// kolor emitowany
	GLfloat shininess;				// połysk
	GLuint textureId;				// identyfikator tekstury

public:
	Material(std::string materialName, std::string objectName);
	void Use();
	static void StopUsing();

	static void Add(std::string loadingPath, std::string materialFileName, std::string objectName);
	static Material& Find(std::string materialName, std::string objectName);
	static GLuint LoadTexture(std::string filePath);
};

