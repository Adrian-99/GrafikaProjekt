#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include "Cuboid.h"
#include <cmath>


class Body {


public:
	GLfloat size;
	GLfloat solarPanelAngle = -10.0f;

private:	
	
	//deck properties
	GLfloat x, y, z;
	GLfloat l, w, h;

	GLfloat frontEdge;	//(-x1)
	GLfloat backEdge;	//(+x2)
	GLfloat rightEdge;	//(-y1)
	GLfloat leftEdge;	//(+y2)
	GLfloat deckH;

	//soalr panel properties
	GLfloat solarElem_L = 9;
	GLfloat solarElem_W = 9;
	GLfloat solarElemSpace = 0.75;
	int solarElemQuantity_L = 11;
	int solarElemQuantity_W = 4;
	GLfloat solarL = solarElemQuantity_L * (solarElem_L + solarElemSpace) - solarElemSpace;
	GLfloat solarW = solarElemQuantity_W * (solarElem_W + solarElemSpace) - solarElemSpace;
	GLfloat solarH = 4.0f;
	
	
public:
	Body(GLfloat x, GLfloat y, GLfloat z, GLfloat size);
	~Body();

	void roverBody(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h);

	void solarPanel(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h);
	void solarPanelTop(GLfloat x, GLfloat y, GLfloat z);
	void solarPanelArm(GLfloat l, GLfloat h, GLint side, GLint order);

	void cameraNeck(GLfloat x, GLfloat y, GLfloat r, GLfloat h);
	void cameraHead(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h);
	void cameraEye(GLfloat eyeR, GLfloat eyeH, GLfloat neckOffsets[3], GLfloat headOffstets[3]);

	void Draw();

};