#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include "Cuboid.h"
#include <cmath>


class Body {

private:
	
	//base block coordinates
	GLfloat x = 15.0f, y = 0.0f, z = 15.0f;
	//base block dimensions
	GLfloat l= 85.0f, w= 65.0f, h= 30.0f;

	

	GLfloat solarPanelAngle = 37.0f;

	//deck
	GLfloat frontEdge;	//(-x1)
	GLfloat backEdge;	//(+x2)
	GLfloat rightEdge;	//(-y1)
	GLfloat leftEdge;	//(+y2)
	GLfloat deckH;



	GLfloat solarL = 110.0f;
	GLfloat solarW = 40.0f;
	GLfloat solarH = 4.0f;

	//cords to translate
	//GLfloat solarX = x;
	//GLfloat solarY = abs(rightEdge) + (solarW / 2.0f);
	//GLfloat solarZ = 5 + z + (h / 2.0f) - (solarH / 2.0f);


	Cuboid roverBody;
	//Cuboid solarPanel;


public:
	Body();
	~Body();

	void solarPanel(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h);
	void solarPanelArm(GLfloat l, GLfloat h, GLint side, GLint order);
	void Draw();

};