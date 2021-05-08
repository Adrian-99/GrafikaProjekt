#include "Cuboid.h"

Cuboid::Cuboid(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h)
{
	//	l - length - along X axis
	//	w - width - along Y axis
	//	h - height - along Z axis
	// Y+ za ekran

	this->x = x;
	this->y = y;
	this->z = z;
	this->l = l;
	this->w = w;
	this->h = h;
}

void Cuboid::Draw()
{	

	GLfloat halfL = l / GLfloat(2.0);
	GLfloat halfW = w / GLfloat(2.0);
	GLfloat halfH = h / GLfloat(2.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		GLfloat color = 0.8f;
		// sciana czerwona - góra
		glBegin(GL_TRIANGLE_STRIP);
		//glColor3f(1.0, 0.0, 0.0);	//kolor rozpoczynajacy gradient
		glColor3f(color, color, color);
		glVertex3f(x - halfL, y - halfW, z + halfH);
		glVertex3f(x - halfL, y + halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y - halfW, z + halfH);
		glVertex3f(x + halfL, y + halfW, z + halfH);
		glEnd();

		//sciana niebieska - spód
		glBegin(GL_TRIANGLE_STRIP);
		//glColor3f(0.0, 0.0, 1.0);	//kolor rozpoczynajacy gradient
		glColor3f(color, color, color);
		glVertex3f(x - halfL, y - halfW, z - halfH);
		glVertex3f(x - halfL, y + halfW, z - halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y - halfW, z - halfH);
		glVertex3f(x + halfL, y + halfW, z - halfH);
		glEnd();


		//sciana zielona - przod
		glBegin(GL_TRIANGLE_STRIP);
		//glColor3f(0.0, 1.0, 0.0);	//kolor rozpoczynajacy gradient
		glColor3f(color, color, color);
		glVertex3f(x - halfL, y - halfW, z - halfH);
		glVertex3f(x - halfL, y - halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x - halfL, y + halfW, z - halfH);
		glVertex3f(x - halfL, y + halfW, z + halfH);
		glEnd();

		//sciana ¿ó³ta - ty³
		glBegin(GL_TRIANGLE_STRIP);
		//glColor3f(1.0, 1.0, 0.0);	//kolor rozpoczynajacy gradient
		glColor3f(color, color, color);
		glVertex3f(x + halfL, y - halfW, z - halfH);
		glVertex3f(x + halfL, y - halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y + halfW, z - halfH);
		glVertex3f(x + halfL, y + halfW, z + halfH);
		glEnd();


		//sciana jasno niebieska (cyan) - prawa
		glBegin(GL_TRIANGLE_STRIP);
		//glColor3f(0.0, 1.0, 1.0);	//kolor rozpoczynajacy gradient
		glColor3f(color, color, color);
		glVertex3f(x - halfL, y - halfW, z - halfH);
		glVertex3f(x - halfL, y - halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y - halfW, z - halfH);
		glVertex3f(x + halfL, y - halfW, z + halfH);
		glEnd();
		

		//sciana jasno ro¿owa (magenta) - lewa
		glBegin(GL_TRIANGLE_STRIP);
		//glColor3f(1.0, 0.0, 1.0);	//kolor rozpoczynajacy gradient
		glColor3f(color, color, color);
		glVertex3f(x - halfL, y + halfW, z - halfH);
		glVertex3f(x - halfL, y + halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y + halfW, z - halfH);
		glVertex3f(x + halfL, y + halfW, z + halfH);
		glEnd();
		
		
	}
}

void Cuboid::setAngle(GLfloat angle)
{
	this->angle = angle;
}
