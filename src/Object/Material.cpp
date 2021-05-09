#include "Material.h"

std::vector<Material> Material::materials;

Material::Material(std::string materialName, std::string objectName)
{
	this->materialName = materialName;
	this->objectName = objectName;
	shininess = 0.0f;
}

void Material::LoadTexture(std::string filePath)
{
	GLint textureWidth, textureHeight, textureChannels;
	unsigned char* textureData = stbi_load(filePath.c_str(), &textureWidth, &textureHeight, &textureChannels, 0);
	if (textureData) {
		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
	}
	else {
		std::cout << "Can't load texture " << filePath << std::endl;
	}
	stbi_image_free(textureData);
}

void Material::Use()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glColor3fv(ambientColor.ToArray());
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glColor3fv(diffuseColor.ToArray());
	glColorMaterial(GL_FRONT, GL_SPECULAR);
	glColor3fv(specularColor.ToArray());
	glColorMaterial(GL_FRONT, GL_EMISSION);
	glColor3fv(emissionColor.ToArray());
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Material::StopUsing()
{
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
}

void Material::Add(std::string loadingPath, std::string materialFileName, std::string objectName)
{
	using namespace std;

	string line;
	vector<string> lineWords;
	bool wasNewMaterialDeclared = false;
	ifstream file(loadingPath + materialFileName);

	if (file) {
		while (!file.eof()) {
			getline(file, line);
			lineWords = SplitString(line);
			if (lineWords.size() > 0) {
				if (lineWords.at(0)[0] == '#') continue;
				if (lineWords.at(0) == "newmtl") {
					if (lineWords.size() >= 2) {
						materials.push_back(Material(lineWords.at(1), objectName));
						wasNewMaterialDeclared = true;
					}
				}
				else if (wasNewMaterialDeclared) {
					if (lineWords.at(0) == "Ka") {
						if (lineWords.size() >= 4) {
						 	materials.back().ambientColor = Vector3(stof(lineWords.at(1)), stof(lineWords.at(2)), stof(lineWords.at(3)));
						}
					}
					else if (lineWords.at(0) == "Kd") {
						if (lineWords.size() >= 4) {
							materials.back().diffuseColor = Vector3(stof(lineWords.at(1)), stof(lineWords.at(2)), stof(lineWords.at(3)));
						}
					}
					else if (lineWords.at(0) == "Ks") {
						if (lineWords.size() >= 4) {
							materials.back().specularColor = Vector3(stof(lineWords.at(1)), stof(lineWords.at(2)), stof(lineWords.at(3)));
						}
					}
					else if (lineWords.at(0) == "Ke") {
						if (lineWords.size() >= 4) {
							materials.back().emissionColor = Vector3(stof(lineWords.at(1)), stof(lineWords.at(2)), stof(lineWords.at(3)));
						}
					}
					else if (lineWords.at(0) == "Ns") {
						if (lineWords.size() >= 2) {
							materials.back().shininess = stof(lineWords.at(1));
						}
					}
					else if (lineWords.at(0) == "map_Kd") {
						if (lineWords.size() >= 2) {
							materials.back().LoadTexture(loadingPath + lineWords.at(1));
						}
					}
				}
			}
		}
		file.close();
	}
	else {
		cout << "Can't open file " << loadingPath + materialFileName << endl;
	}
}

Material Material::Find(std::string materialName, std::string objectName)
{
	for (int i = 0; i < materials.size(); i++) {
		if (materials.at(i).materialName == materialName && materials.at(i).objectName == objectName) {
			return materials.at(i);
		}
	}
}
