#pragma once
#include <GLFW/glfw3.h>

class Cuboid
{
private:

	//block coordinates
	GLfloat x, y, z;

	//block dimensions
	GLfloat l, w, h;

	GLfloat angle = 1;	
	

public:
	Cuboid(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h);
	void Draw();

	void setAngle(GLfloat angle);
};

