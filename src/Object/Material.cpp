#include "Material.h"

std::vector<Material> Material::materials;

Material::Material(std::string materialName, std::string objectName)
{
	this->materialName = materialName;
	this->objectName = objectName;
	shininess = 0.0f;
}

void Material::Use()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientColor.ToArray());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor.ToArray());
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor.ToArray());
	glMaterialfv(GL_FRONT, GL_EMISSION, emissionColor.ToArray());
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void Material::StopUsing()
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
}

void Material::Add(std::string filePath, std::string objectName)
{
	using namespace std;

	string line;
	vector<string> lineWords;
	bool wasNewMaterialDeclared = false;
	ifstream file(filePath);

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
						 	materials.back().ambientColor = Color(stof(lineWords.at(1)), stof(lineWords.at(2)), stof(lineWords.at(3)));
						}
					}
					else if (lineWords.at(0) == "Kd") {
						if (lineWords.size() >= 4) {
							materials.back().diffuseColor = Color(stof(lineWords.at(1)), stof(lineWords.at(2)), stof(lineWords.at(3)));
						}
					}
					else if (lineWords.at(0) == "Ks") {
						if (lineWords.size() >= 4) {
							materials.back().specularColor = Color(stof(lineWords.at(1)), stof(lineWords.at(2)), stof(lineWords.at(3)));
						}
					}
					else if (lineWords.at(0) == "Ke") {
						if (lineWords.size() >= 4) {
							materials.back().emissionColor = Color(stof(lineWords.at(1)), stof(lineWords.at(2)), stof(lineWords.at(3)));
						}
					}
					else if (lineWords.at(0) == "Ns") {
						if (lineWords.size() >= 2) {
							materials.back().shininess = stof(lineWords.at(1));
						}
					}
				}
			}
		}
		file.close();
	}
	else {
		cout << "Can't open file " << filePath << endl;
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
