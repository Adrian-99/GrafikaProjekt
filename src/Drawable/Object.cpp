#include "Object.h"

std::string Object::loadingPath = "./obj/";

Object::Object(std::string name, Vector3 startPosition, GLfloat size, CollisionController* collisionController)
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

        if (collisionController != nullptr) AddCollider(collisionController);
    }
    else {
        cout << "Can't open file " << loadingPath + name + ".obj" << endl;
    }
}

int Object::AddDuplicate(Vector3 offset, GLfloat rotationAngle, CollisionController* collisionController)
{
    duplicateOffsets.push_back(offset);
    duplicateRotations.push_back(rotationAngle);

    if (collisionController != nullptr) AddCollider(collisionController, offset, rotationAngle);

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

Vector3 Object::GetMinPoint()
{
    Vector3 result = vertices.at(0);
    for (GLint i = 1; i < vertices.size(); i++) {
        if (vertices.at(i).X() < result.X()) result.X(vertices.at(i).X());
        if (vertices.at(i).Y() < result.Y()) result.Y(vertices.at(i).Y());
        if (vertices.at(i).Z() < result.Z()) result.Z(vertices.at(i).Z());
    }
    return result;
}

Vector3 Object::GetMaxPoint()
{
    Vector3 result = vertices.at(0);
    for (GLint i = 1; i < vertices.size(); i++) {
        if (vertices.at(i).X() > result.X()) result.X(vertices.at(i).X());
        if (vertices.at(i).Y() > result.Y()) result.Y(vertices.at(i).Y());
        if (vertices.at(i).Z() > result.Z()) result.Z(vertices.at(i).Z());
    }
    return result;
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

void Object::AddCollider(CollisionController* collisionController, Vector3 offset, GLfloat rotationAngle)
{
    Vector3 minPoint = GetMinPoint();
    Vector3 maxPoint = GetMaxPoint();

    Vector3 position;
    position.X((maxPoint.X() + minPoint.X()) / 2);
    position.Y((maxPoint.Y() + minPoint.Y()) / 2);
    position.Z(minPoint.Z());
    position.Rotate(0.0f, 0.0f, rotationAngle);

    GLfloat width = ((maxPoint.X() - minPoint.X()) + (maxPoint.Y() - minPoint.Y())) / 2;

    collisionController->AddCollider(position + offset, width, maxPoint.Z() - minPoint.Z());
}

