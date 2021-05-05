#include "Object.h"

Object::Object(const char* filePath, GLfloat x, GLfloat y, GLfloat z, GLfloat size)
{
    using namespace std;

    string line;
    vector<string> lineWords;
    vector<string> wordParts;
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
                    faces.push_back(ObjectFace(lineWords.size() - 1));
                    for (GLint i = 1; i < lineWords.size(); i++) {
                        wordParts = SplitString(lineWords.at(i), '/', false);
                        faces.back().SetIndex(i - 1, stoi(wordParts.at(0)) - 1);
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
    GLenum drawingMode;

    for (GLint i = 0; i < faces.size(); i++) {
        if (faces.at(i).GetVerticesCount() == 4) drawingMode = GL_QUADS;
        else drawingMode = GL_TRIANGLE_STRIP;
        glBegin(drawingMode);
        for (GLint j = 0; j < faces.at(i).GetVerticesCount(); j++) {
            glVertex3fv(vertices.at(faces.at(i).GetVertexIndex(j)).ToArray());
        }
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
