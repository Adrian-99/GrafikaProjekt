#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include "Cuboid.h"
#include <cmath>


class Body {


public:
	GLfloat size;						//zmienna definiujaca rozmiar nadwozia
	GLfloat solarPanelAngle = -10.0f;	//kat pochylenia paneli s³onecznych

private:	
	
	//w³asiwoœci pok³adu
	GLfloat x, y, z;
	GLfloat l = 85.0f, w = 65.0f, h = 30.0f;

	GLfloat frontEdge;	// wspo³rzêdna (-x) okreœlajaca po³o¿enie przedniej krawedzi nadwodzia
	GLfloat backEdge;	// wspo³rzêdna (+x) okreœlajaca po³o¿enie tylnej krawedzi nadwodzia
	GLfloat rightEdge;	// wspo³rzêdna (-y) okreœlajaca po³o¿enie prawej krawedzi nadwodzia
	GLfloat leftEdge;	// wspo³rzêdna (+y) okreœlajaca po³o¿enie lewej krawedzi nadwodzia
	GLfloat deckH;		// wspo³rzêdna (z) okreœlajaca po³o¿enie górnej podstawy nadwodzia


	//w³aœciwoœci panelu s³onecznego
	GLfloat solarElem_L = 9;		//zmienna okreœlajaca d³ugoœæ(L) ogniwa fotowoltaicznego panelu s³onecznego
	GLfloat solarElem_W = 9;		//zmienna okreœlajaca szerokoœæ(W) ogniwa fotowoltaicznego panelu s³onecznego
	GLfloat solarElemSpace = 0.75;	//zmienna okreœlajaca odstêp pomiedzy ogniwami fotowoltaicznymi panelu s³onecznego
	int solarElemQuantity_L = 11;	//zmienna okreœlajaca iloœæ ogniw fotowoltaicznych sk³adaj¹cych sie na d³ugosc panelu s³onecznego
	int solarElemQuantity_W = 4;	//zmienna okreœlajaca iloœæ ogniw fotowoltaicznych sk³adaj¹cych sie na szerokosc panelu s³onecznego
	
	GLfloat solarPanel_L = solarElemQuantity_L * (solarElem_L + solarElemSpace) - solarElemSpace;		//d³ugoœæ panelu s³onecznego obliczna na podstawie powy¿szych parametrów																										//obliczna na podstawie powy¿szych parametrów
	GLfloat solarPanel_W = solarElemQuantity_W * (solarElem_W + solarElemSpace) - solarElemSpace;		//szerokoœæ panelu s³onecznego  obliczna na podstawie powy¿szych parametrów
	GLfloat solarPanel_H = 4.0f;																		//wysokoœæ panelu s³onecznego
	
	
public:
	Body(GLfloat x, GLfloat y, GLfloat z, GLfloat size);
	~Body();
	void Draw();

private:
	void roverDeck(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h);

	void solarPanel(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h);
	void solarPanelTop(GLfloat x, GLfloat y, GLfloat z);
	void solarPanelArm(GLfloat l, GLfloat h, GLint side, GLint order);

	void cameraNeck(GLfloat x, GLfloat y, GLfloat r, GLfloat h);
	void cameraHead(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h);
	void cameraEye(GLfloat eyeR, GLfloat eyeH, GLfloat neckOffsets[3], GLfloat headOffstets[3]);

};