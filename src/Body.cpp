#include "Body.h"

Body::Body(GLfloat x, GLfloat y, GLfloat z, GLfloat size):
	roverBody(x, y, z, 85.0f * size, 65.0f * size, 30.0f * size)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->l = 85.0f * size;
	this->w = 65.0f * size;
	this->h = 30.0f * size;
	this->size = size;

	frontEdge = x - (l / 2.0f);
	backEdge = x + (l / 2.0f);
	rightEdge = y - (w / 2.0f);
	leftEdge = y + (w / 2.0f);
	deckH = z + (h / 2.0f);

	//std::cout << frontEdge << "|" << backEdge;
	//std::cout << rightEdge << "|" << leftEdge;
	//std::cout << deckH;
}

Body::~Body() {}

void Body::solarPanel(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h)
{
	GLfloat halfL = l / GLfloat(2.0f);
	GLfloat halfW = w / GLfloat(2.0f);
	GLfloat halfH = h / GLfloat(2.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		
		// sciana czerwona - góra
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.0, 0.10, 0.40);	//kolor rozpoczynajacy gradient
		glVertex3f(x - halfL, y - halfW, z + halfH);
		glVertex3f(x - halfL, y + halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y - halfW, z + halfH);
		glVertex3f(x + halfL, y + halfW, z + halfH);
		glEnd();

		//sciana niebieska - spód
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.30, 0.30, 0.30);	//kolor rozpoczynajacy gradient
		glVertex3f(x - halfL, y - halfW, z - halfH);
		glVertex3f(x - halfL, y + halfW, z - halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y - halfW, z - halfH);
		glVertex3f(x + halfL, y + halfW, z - halfH);
		glEnd();


		//sciana zielona - przod
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.46, .46, 0.46);	//kolor rozpoczynajacy gradient
		glVertex3f(x - halfL, y - halfW, z - halfH);
		glVertex3f(x - halfL, y - halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x - halfL, y + halfW, z - halfH);
		glVertex3f(x - halfL, y + halfW, z + halfH);
		glEnd();

		//sciana ¿ó³ta - ty³
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.46, .46, 0.46);	//kolor rozpoczynajacy gradient
		glVertex3f(x + halfL, y - halfW, z - halfH);
		glVertex3f(x + halfL, y - halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y + halfW, z - halfH);
		glVertex3f(x + halfL, y + halfW, z + halfH);
		glEnd();


		//sciana jasno niebieska (cyan) - prawa
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.46, .46, 0.46);	//kolor rozpoczynajacy gradient
		glVertex3f(x - halfL, y - halfW, z - halfH);
		glVertex3f(x - halfL, y - halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y - halfW, z - halfH);
		glVertex3f(x + halfL, y - halfW, z + halfH);
		glEnd();


		//sciana jasno ro¿owa (magenta) - lewa
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.46, .46, 0.46);	//kolor rozpoczynajacy gradient
		glVertex3f(x - halfL, y + halfW, z - halfH);
		glVertex3f(x - halfL, y + halfW, z + halfH);
		//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
		glVertex3f(x + halfL, y + halfW, z - halfH);
		glVertex3f(x + halfL, y + halfW, z + halfH);
		glEnd();
	}

}

void Body::solarPanelArm(GLfloat L, GLfloat H, GLint side, GLint order)
{

	//side = 1 - leftSide
	//side = -1 - rightSide
	//order = 1 - first arm near the topEdge of deck
	//order = 2 - second arm near the backEdge of deck

	GLfloat frontOrBackEdge;
	GLfloat spaceFromEdges = 10.0f * size;		//space from top and back edge
	GLfloat armOnDeck = 10.0f * size;			//determines the length of the part of horizontal arm on board
	GLfloat sideEdge;

	if (side == 1) {
		sideEdge = leftEdge;
	}
	else {
		sideEdge = rightEdge;
	}

	GLfloat h = 4.0f * size;
	GLfloat w = 7.0f * size;

	GLfloat hArmL = 30.0f * size;	//horizontal arm length
	GLfloat vArmH = 20.0f * size;	//vertical arm height
	GLfloat hArmEnd = side * (sideEdge + side * (-armOnDeck + hArmL));	//ending coordinate of horizontal arm

	
	if (order == 1) {
		frontOrBackEdge = frontEdge;
	}
	else {
		frontOrBackEdge = backEdge;
		order = -1;
	}

	GLfloat armHandleX = frontOrBackEdge + order * (spaceFromEdges + (w/2.0));
	GLfloat armHandleY = side * (hArmEnd + (h / 2.0));
	GLfloat armHandleZ = deckH + vArmH;

	GLfloat armHandleL = 5.0f * size;
	GLfloat armHandleW = 4.0f * size;
	GLfloat armHandleH = 2.0f * size;


	//horizontal arm
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{

		// sciana dolna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * spaceFromEdges, sideEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck), deckH);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck + hArmL), deckH);
		glEnd();

		// sciana górna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * spaceFromEdges, sideEdge + side * (-armOnDeck), deckH + h);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck + hArmL), deckH + h);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck + hArmL), deckH + h);
		glEnd();


		// sciana boczna d³u¿sza nr1
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck + hArmL), deckH + h);
		glEnd();

		// sciana boczna d³u¿sza nr2
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck + hArmL), deckH + h);
		glEnd();

		// sciana boczna krotsza nr1
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck), deckH + h);
		glEnd();

		// sciana boczna krotsza nr2
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), sideEdge + side * (-armOnDeck + hArmL), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), sideEdge + side * (-armOnDeck + hArmL), deckH + h);
		glEnd();

	}


	//vertical arm
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{

		// sciana dolna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * spaceFromEdges, side * (hArmEnd), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd), deckH);

		glVertex3f(frontOrBackEdge + order * spaceFromEdges, side * (hArmEnd + h), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd + h), deckH);
		glEnd();

		// sciana górna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * spaceFromEdges, side * (hArmEnd), deckH + vArmH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd), deckH + vArmH);

		glVertex3f(frontOrBackEdge + order * spaceFromEdges, side * (hArmEnd + h), deckH + vArmH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd + h), deckH + vArmH);
		glEnd();

		// sciana boczna d³uga szersza nr1
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * spaceFromEdges, side * (hArmEnd), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), side * (hArmEnd), deckH + vArmH);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd), deckH + vArmH);
		glEnd();

		// sciana boczna d³uga szersza nr2
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * spaceFromEdges, side * (hArmEnd + h), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), side * (hArmEnd + h), deckH + vArmH);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd + h), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd + h), deckH + vArmH);
		glEnd();


		// sciana boczna d³uga w¹ska nr1
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * spaceFromEdges, side * (hArmEnd), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), side * (hArmEnd), deckH + vArmH);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), side * (hArmEnd + h), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), side * (hArmEnd + h), deckH + vArmH);
		glEnd();

		// sciana boczna d³uga w¹ska nr2
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd), deckH + vArmH);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd + h), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), side * (hArmEnd + h), deckH + vArmH);
		glEnd();

	}

	
	///arm handle
	glPushMatrix();
	glTranslatef(armHandleX, armHandleY, armHandleZ);
	glRotatef(side*solarPanelAngle, 1.0f, 0.0f, 0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		
		double r = armHandleW, zOffset = r / 2.0;
		double y, z, alpha, PI = 3.14;

		GLfloat armHandleCylinderPartEnd = r / 2.0f;
		GLfloat armHandleCuboidPartEnd = armHandleH + (r / 2.0f);
		
		
		// --- CILINDER PART --- //
		//outter wall
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.35, 0.35, 0.35);
		for (alpha = 0.5 * PI; alpha <= 1.5 * PI; alpha += PI / 8.0)
		{
			
			y = r * sin(alpha);
			z = r * cos(alpha);

			glVertex3d(-side*armHandleL, y, z + zOffset);
			glVertex3d(side*armHandleL, y, z + zOffset);
		}
		glEnd();

		

		
		//base front
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.35, 0.35, 0.35);
		for (alpha = 0.5 * PI; alpha <= 1.5 * PI; alpha += PI / 8.0)
		{

			y = r * sin(alpha);
			z = r * cos(alpha);

			glVertex3d(side*armHandleL, y, z+zOffset);
			glVertex3d(side*armHandleL, y, z+zOffset);
		}
		glEnd();

		
		//base back
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.35, 0.35, 0.35);
		for (alpha = 0.5 * PI; alpha <= 1.5 * PI; alpha += PI / 8.0)
		{

			y = r * sin(alpha);
			z = r * cos(alpha);

			glVertex3d(-side*armHandleL, y, z+zOffset);
			glVertex3d(-side*armHandleL, y, z+zOffset);
		}
		glEnd();
		
		
		// --- CUBOID PART -- //
		///////
		//krotsza sciana boczna przednia
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25, 0.25, 0.25);
	
		glVertex3d(-side*armHandleL, -r, armHandleCylinderPartEnd);
		glVertex3d(-side*armHandleL, -r, armHandleCuboidPartEnd);

		glVertex3d(-side*armHandleL, +r, armHandleCylinderPartEnd);
		glVertex3d(-side*armHandleL, +r, armHandleCuboidPartEnd);
		glEnd();

		//krotsza sciana boczna tylna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25, 0.25, 0.25);

		glVertex3d(side*armHandleL, -r, armHandleCylinderPartEnd);
		glVertex3d(side*armHandleL, -r, armHandleCuboidPartEnd);

		glVertex3d(side*armHandleL, +r, armHandleCylinderPartEnd);
		glVertex3d(side*armHandleL, +r, armHandleCuboidPartEnd);
		glEnd();
		

		//d³u¿sza sciana boczna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25, 0.25, 0.25);

		glVertex3d(-side*armHandleL, -r, armHandleCylinderPartEnd);
		glVertex3d(side*armHandleL, -r, armHandleCylinderPartEnd);

		glVertex3d(-side*armHandleL, -r, armHandleCuboidPartEnd);
		glVertex3d(side*armHandleL, -r, armHandleCuboidPartEnd);
		glEnd();

		//d³u¿sza sciana boczna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25, 0.25, 0.25);

		glVertex3d(-side*armHandleL, r, armHandleCylinderPartEnd);
		glVertex3d(side*armHandleL, r, armHandleCylinderPartEnd);

		glVertex3d(-side*armHandleL, r, armHandleCuboidPartEnd);
		glVertex3d(side*armHandleL, r, armHandleCuboidPartEnd);
		glEnd();


		
		//nie potrafie dobrze obrocic paneli poza ta funkcja
		if(order == 1)
			solarPanel(x-armHandleX, 0.0f, armHandleCuboidPartEnd + (solarH / 2.0f), solarL * size, solarW * size, solarH * size);

	}
	glPopMatrix();
	
}

void Body::Draw() {

	
	roverBody.Draw();

	//roverBody is centered by point [0,0,0]
	//solar panel coordinates are determined by body base size and coordinates
		
	//left solar ??
	glPushMatrix();
	//glTranslatef(15.0f, -47.5f, 27.5f);
	//glTranslatef(solarX, solarY, solarZ + 24.0f);
	//glRotatef(solarPanelAngle, 1.0f, 0.0f, 0.0f);
	//solarPanel(0.0f, 0.0f, 0.0f, solarL, solarW, solarH);
	glPopMatrix();

	//right top
	solarPanelArm(44 * size, 44 * size, -1, 1);
	//right back
	solarPanelArm(44 * size, 44 * size, -1, 2);
	//left top
	solarPanelArm(44 * size, 44 * size, 1, 1);
	//left back
	solarPanelArm(44 * size, 44 * size, 1, 2);

	roverBody.Draw();

	


}

