#include "Object.h"

Object::Object(const char* filePath, GLfloat x, GLfloat y, GLfloat z, GLfloat size)
{
    using namespace std;

    string line;
    vector<string> lineWords;
    vector<vector<string>> allWordsParts;
    ifstream file(filePath);

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
                else if (lineWords.at(0) == "f") {
                    allWordsParts.clear();
                    for (GLint i = 1; i < lineWords.size(); i++) {
                        allWordsParts.push_back(SplitString(lineWords.at(i), '/', false));
                    }
                    for (GLint i = 2; i < allWordsParts.size(); i++) {
                        vertexIndices.push_back(stoi(allWordsParts.at(0).at(0)) - 1);
                        vertexIndices.push_back(stoi(allWordsParts.at(i - 1).at(0)) - 1);
                        vertexIndices.push_back(stoi(allWordsParts.at(i).at(0)) - 1);
                    }
                }
            }
        }
    }
    else {
        cout << "Can't open file " << filePath << endl;
    }

    file.close();
}

void Object::Draw()
{
    for (GLint i = 0; i < vertexIndices.size() / 3; i++) {
        glBegin(GL_TRIANGLES);
        glVertex3fv(vertices.at(vertexIndices.at(i * 3)).ToArray());
        glVertex3fv(vertices.at(vertexIndices.at(i * 3 + 1)).ToArray());
        glVertex3fv(vertices.at(vertexIndices.at(i * 3 + 2)).ToArray());
        glEnd();
    }
}

void Object::DrawDuplicate(Vertex offset)
{
    for (GLint i = 0; i < vertexIndices.size() / 3; i++) {
        glBegin(GL_TRIANGLES);
        glVertex3fv((vertices.at(vertexIndices.at(i * 3)) + offset).ToArray());
        glVertex3fv((vertices.at(vertexIndices.at(i * 3 + 1)) + offset).ToArray());
        glVertex3fv((vertices.at(vertexIndices.at(i * 3 + 2)) + offset).ToArray());
        glEnd();
    }
}

std::vector<std::string> Object::SplitString(std::string text, char delim, bool ignoreEmpty)
{
    using namespace std;

    int lastDelim = 0;
    int foundDelim;
    vector<string> result;

    while (1) {
        foundDelim = text.find(delim, lastDelim);
        if (foundDelim == string::npos) {
            if (text.length() != lastDelim || !ignoreEmpty) {
                result.push_back(text.substr(lastDelim, text.length() - lastDelim));
            }
            break;
        }
        if (foundDelim != lastDelim || !ignoreEmpty) {
            result.push_back(text.substr(lastDelim, foundDelim - lastDelim));
        }
        lastDelim = foundDelim + 1;
    }

    return result;
}
