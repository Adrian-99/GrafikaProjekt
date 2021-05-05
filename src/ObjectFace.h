#pragma once
class ObjectFace
{
private:
	unsigned int verticesCount;
	unsigned int* vertexIndices;

public:
	ObjectFace(unsigned int verticesCount);
	ObjectFace(ObjectFace&& objectFace);
	~ObjectFace();
	void SetIndex(int orderNumber, unsigned int indexValue);
	unsigned int GetVerticesCount();
	unsigned int GetVertexIndex(int orderNumber);
};

