#include "Object.h"

std::string Object::loadingPath = "./obj/";

Object::Object(std::string name, GLfloat x, GLfloat y, GLfloat z, GLfloat size)
{
    using namespace std;

    this->name = name;

    string line;
    vector<string> lineWords;
    vector<vector<string>> allWordsParts;
    ifstream file(loadingPath + name + ".obj");

    if (file) {
        while (!file.eof()) {
            getline(file, line);
            lineWords = SplitString(line);
            if (lineWords.size() > 0) {
                if (lineWords.at(0)[0] == '#') continue;
                if (lineWords.at(0) == "v") {
                    if (lineWords.size() >= 4) {
                        vertices.push_back(Vertex(x + stof(lineWords.at(1)) * size, y + stof(lineWords.at(2)) * size, z + stof(lineWords.at(3)) * size));
                    }
                }
                else if (lineWords.at(0) == "vn") {
                    if (lineWords.size() >= 4) {
                        normals.push_back(Vertex(stof(lineWords.at(1)), stof(lineWords.at(2)), stof(lineWords.at(3))));
                    }
                }
                else if (lineWords.at(0) == "f") {
                    allWordsParts.clear();
                    for (GLint i = 1; i < lineWords.size(); i++) {
                        allWordsParts.push_back(SplitString(lineWords.at(i), '/', false));
                    }
                    for (GLint i = 2; i < allWordsParts.size(); i++) {
                        vertexIndices.push_back(stoi(allWordsParts.at(0).at(0)) - 1);
                        vertexIndices.push_back(stoi(allWordsParts.at(i - 1).at(0)) - 1);
                        vertexIndices.push_back(stoi(allWordsParts.at(i).at(0)) - 1);

                        normalIndices.push_back(stoi(allWordsParts.at(0).at(2)) - 1);
                        normalIndices.push_back(stoi(allWordsParts.at(i - 1).at(2)) - 1);
                        normalIndices.push_back(stoi(allWordsParts.at(i).at(2)) - 1);
                    }
                }
                else if (lineWords.at(0) == "mtllib") {
                    if (lineWords.size() >= 2) {
                        Material::Add(loadingPath + lineWords.at(1), name);
                    }
                }
                else if (lineWords.at(0) == "usemtl") {
                    if (lineWords.size() >= 2) {
                        materials.push_back(lineWords.at(1));
                        materialStartIndices.push_back(vertexIndices.size());
                    }
                }
            }
        }
        file.close();
    }
    else {
        cout << "Can't open file " << loadingPath + name + ".obj" << endl;
    }
}

void Object::Draw()
{
    for (GLint i = 0; i < vertexIndices.size(); i += 3) {
        if (FindInVector(materialStartIndices, i) != -1) {
            std::string tmp = materials.at(FindInVector(materialStartIndices, i));
            Material::Find(tmp, name).Use();
        }
        glBegin(GL_TRIANGLES);
        for (GLint j = 0; j < 3; j++) {
            glNormal3fv(normals.at(normalIndices.at(i + j)).ToArray());
            glVertex3fv(vertices.at(vertexIndices.at(i + j)).ToArray());
        }
        glEnd();
    }
    Material::StopUsing();
}

void Object::DrawDuplicate(Vertex offset)
{
    for (GLint i = 0; i < vertexIndices.size(); i += 3) {
        if (FindInVector(materialStartIndices, i) != -1) {
            std::string tmp = materials.at(FindInVector(materialStartIndices, i));
            Material::Find(tmp, name).Use();
        }
        glBegin(GL_TRIANGLES);
        for (GLint j = 0; j < 3; j++) {
            glNormal3fv(normals.at(normalIndices.at(i + j)).ToArray());
            glVertex3fv((vertices.at(vertexIndices.at(i + j)) + offset).ToArray());
        }
        glEnd();
    }
    Material::StopUsing();
}

