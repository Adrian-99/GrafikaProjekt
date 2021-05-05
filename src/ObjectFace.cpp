#include "ObjectFace.h"

ObjectFace::ObjectFace(unsigned int verticesCount)
{
	this->verticesCount = verticesCount;
	vertexIndices = new unsigned int[verticesCount];
}

ObjectFace::ObjectFace(ObjectFace&& objectFace)
{
	this->verticesCount = objectFace.verticesCount;
	this->vertexIndices = new unsigned int[verticesCount];
	for (int i = 0; i < objectFace.verticesCount; i++) {
		this->vertexIndices[i] = objectFace.vertexIndices[i];
	}
}

ObjectFace::~ObjectFace()
{
	delete[] vertexIndices;
}

void ObjectFace::SetIndex(int orderNumber, unsigned int indexValue)
{
	if (orderNumber < verticesCount) {
		vertexIndices[orderNumber] = indexValue;
	}
}

unsigned int ObjectFace::GetVerticesCount()
{
	return verticesCount;
}

unsigned int ObjectFace::GetVertexIndex(int orderNumber)
{
	if (orderNumber < verticesCount) return vertexIndices[orderNumber];
	else return 0;
}
