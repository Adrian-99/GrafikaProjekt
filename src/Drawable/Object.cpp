#include "Object.h"

std::string Object::loadingPath = "./obj/";

Object::Object(std::string name, Vector3 startPosition, GLfloat size)
{
    using namespace std;

    this->name = name;
    duplicateOffsets.clear();
    duplicateRotations.clear();

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
                        vertices.push_back(Vector3(startPosition.X() + stof(lineWords.at(1)) * size, startPosition.Y() + stof(lineWords.at(3)) * size, startPosition.Z() + stof(lineWords.at(2)) * size));
                    }
                }
                else if (lineWords.at(0) == "vt") {
                    if (lineWords.size() >= 3) {
                        textureCoords.push_back(Vector2(stof(lineWords.at(1)), stof(lineWords.at(2))));
                    }
                }
                else if (lineWords.at(0) == "vn") {
                    if (lineWords.size() >= 4) {
                        normals.push_back(Vector3(stof(lineWords.at(1)), stof(lineWords.at(3)), stof(lineWords.at(2))));
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

                        textureCoordsIndices.push_back(stoi(allWordsParts.at(0).at(1)) - 1);
                        textureCoordsIndices.push_back(stoi(allWordsParts.at(i - 1).at(1)) - 1);
                        textureCoordsIndices.push_back(stoi(allWordsParts.at(i).at(1)) - 1);

                        normalIndices.push_back(stoi(allWordsParts.at(0).at(2)) - 1);
                        normalIndices.push_back(stoi(allWordsParts.at(i - 1).at(2)) - 1);
                        normalIndices.push_back(stoi(allWordsParts.at(i).at(2)) - 1);
                    }
                }
                else if (lineWords.at(0) == "mtllib") {
                    if (lineWords.size() >= 2) {
                        Material::Add(loadingPath, lineWords.at(1), name);
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

int Object::AddDuplicate(Vector3 offset, GLfloat rotationAngle)
{
    duplicateOffsets.push_back(offset);
    duplicateRotations.push_back(rotationAngle);
    return duplicateOffsets.size() - 1;
}

void Object::Draw()
{
    DrawObject();
}

void Object::DrawDuplicate(int duplicateIndex)
{
    if (duplicateIndex == -1) {
        for (GLint i = 0; i < duplicateOffsets.size(); i++) {
            DrawObject(duplicateOffsets.at(i), duplicateRotations.at(i));
        }
    }
    else if (duplicateIndex >= 0 && duplicateIndex < duplicateOffsets.size()) {
        DrawObject(duplicateOffsets.at(duplicateIndex), duplicateRotations.at(duplicateIndex));
    }
}

void Object::DrawObject(Vector3 offset, GLfloat rotationAngle)
{
    glPushMatrix();

    glTranslatef(offset.X(), offset.Y(), offset.Z());
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    for (GLint i = 0; i < vertexIndices.size(); i += 3) {
        if (FindInVector(materialStartIndices, i) != -1) {
            Material::Find(materials.at(FindInVector(materialStartIndices, i)), name).Use();
        }
        glBegin(GL_TRIANGLES);
        for (GLint j = 0; j < 3; j++) {
            glTexCoord2fv(textureCoords.at(textureCoordsIndices.at(i + j)).ToArray());
            glNormal3fv(normals.at(normalIndices.at(i + j)).ToArray());
            glVertex3fv((vertices.at(vertexIndices.at(i + j))).ToArray());
        }
        glEnd();
    }
    Material::StopUsing();

    glPopMatrix();
}

