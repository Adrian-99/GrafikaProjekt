#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include "Cuboid.h"
#include <cmath>


class Body {


public:
	GLfloat size;						//zmienna definiujaca rozmiar nadwozia
	GLfloat solarPanelAngle = -10.0f;	//kat pochylenia paneli s�onecznych

private:	
	
	//w�asiwo�ci pok�adu
	GLfloat x, y, z;
	GLfloat l = 85.0f, w = 65.0f, h = 30.0f;

	GLfloat frontEdge;	// wspo�rz�dna (-x) okre�lajaca po�o�enie przedniej krawedzi nadwodzia
	GLfloat backEdge;	// wspo�rz�dna (+x) okre�lajaca po�o�enie tylnej krawedzi nadwodzia
	GLfloat rightEdge;	// wspo�rz�dna (-y) okre�lajaca po�o�enie prawej krawedzi nadwodzia
	GLfloat leftEdge;	// wspo�rz�dna (+y) okre�lajaca po�o�enie lewej krawedzi nadwodzia
	GLfloat deckH;		// wspo�rz�dna (z) okre�lajaca po�o�enie g�rnej podstawy nadwodzia


	//w�a�ciwo�ci panelu s�onecznego
	GLfloat solarElem_L = 9;		//zmienna okre�lajaca d�ugo��(L) ogniwa fotowoltaicznego panelu s�onecznego
	GLfloat solarElem_W = 9;		//zmienna okre�lajaca szeroko��(W) ogniwa fotowoltaicznego panelu s�onecznego
	GLfloat solarElemSpace = 0.75;	//zmienna okre�lajaca odst�p pomiedzy ogniwami fotowoltaicznymi panelu s�onecznego
	int solarElemQuantity_L = 11;	//zmienna okre�lajaca ilo�� ogniw fotowoltaicznych sk�adaj�cych sie na d�ugosc panelu s�onecznego
	int solarElemQuantity_W = 4;	//zmienna okre�lajaca ilo�� ogniw fotowoltaicznych sk�adaj�cych sie na szerokosc panelu s�onecznego
	
	GLfloat solarPanel_L = solarElemQuantity_L * (solarElem_L + solarElemSpace) - solarElemSpace;		//d�ugo�� panelu s�onecznego obliczna na podstawie powy�szych parametr�w																										//obliczna na podstawie powy�szych parametr�w
	GLfloat solarPanel_W = solarElemQuantity_W * (solarElem_W + solarElemSpace) - solarElemSpace;		//szeroko�� panelu s�onecznego  obliczna na podstawie powy�szych parametr�w
	GLfloat solarPanel_H = 4.0f;																		//wysoko�� panelu s�onecznego
	
	
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