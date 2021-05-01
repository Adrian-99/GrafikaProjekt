#include "Body.h"


Body::Body(GLfloat x, GLfloat y, GLfloat z, GLfloat size){
	
	this->x = x;
	this->y = y;
	this->z = z;
	this->l = l * size;
	this->w = w * size;
	this->h = h * size;
	this->size = size;

	frontEdge = x - (l / 2.0f);
	backEdge = x + (l / 2.0f);
	rightEdge = y - (w / 2.0f);
	leftEdge = y + (w / 2.0f);
	deckH = z + (h / 2.0f);
}

Body::~Body() {}

void Body::roverDeck(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h)
{

	GLfloat halfL = l / GLfloat(2.0);
	GLfloat halfW = w / GLfloat(2.0);
	GLfloat halfH = h / GLfloat(2.0);

	GLfloat topColor = 0.35;
	GLfloat bottomColor = 0.3;
	GLfloat outerColor = 0.325;

	
	// podstawa  góra
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(topColor, topColor, topColor);
	glVertex3f(x - halfL, y - halfW, z + halfH);
	glVertex3f(x - halfL, y + halfW, z + halfH);

	glVertex3f(x + halfL, y - halfW, z + halfH);
	glVertex3f(x + halfL, y + halfW, z + halfH);
	glEnd();

	//postawa  dolna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(bottomColor, bottomColor, bottomColor);
	glVertex3f(x - halfL, y - halfW, z - halfH);
	glVertex3f(x - halfL, y + halfW, z - halfH);
	//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
	glVertex3f(x + halfL, y - halfW, z - halfH);
	glVertex3f(x + halfL, y + halfW, z - halfH);
	glEnd();


	//sciana zielona - przod
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(outerColor, outerColor, outerColor);
	glVertex3f(x - halfL, y - halfW, z - halfH);
	glVertex3f(x - halfL, y - halfW, z + halfH);
	//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
	glVertex3f(x - halfL, y + halfW, z - halfH);
	glVertex3f(x - halfL, y + halfW, z + halfH);
	glEnd();

	//sciana ¿ó³ta - ty³
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(outerColor, outerColor, outerColor);
	glVertex3f(x + halfL, y - halfW, z - halfH);
	glVertex3f(x + halfL, y - halfW, z + halfH);
	//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
	glVertex3f(x + halfL, y + halfW, z - halfH);
	glVertex3f(x + halfL, y + halfW, z + halfH);
	glEnd();


	//sciana jasno niebieska (cyan) - prawa
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(outerColor, outerColor, outerColor);
	glVertex3f(x - halfL, y - halfW, z - halfH);
	glVertex3f(x - halfL, y - halfW, z + halfH);
	//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
	glVertex3f(x + halfL, y - halfW, z - halfH);
	glVertex3f(x + halfL, y - halfW, z + halfH);
	glEnd();


	//sciana jasno ro¿owa (magenta) - lewa
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(outerColor, outerColor, outerColor);
	glVertex3f(x - halfL, y + halfW, z - halfH);
	glVertex3f(x - halfL, y + halfW, z + halfH);
	//glColor3d(0.0, 1.0, 0.0);	//kolor konczacy gradient
	glVertex3f(x + halfL, y + halfW, z - halfH);
	glVertex3f(x + halfL, y + halfW, z + halfH);
	glEnd();

}


void Body::solarPanel(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h)
{
	GLfloat halfL = l / GLfloat(2.0f);
	GLfloat halfW = w / GLfloat(2.0f);
	GLfloat halfH = h / GLfloat(2.0f);

	solarPanelTop(x - halfL, y - halfW, z + halfH);

	//podstawa góra
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.40, 0.40, 0.40);
	glVertex3f(x - halfL, y - halfW, z + halfH);
	glVertex3f(x - halfL, y + halfW, z + halfH);

	glVertex3f(x + halfL, y - halfW, z + halfH);
	glVertex3f(x + halfL, y + halfW, z + halfH);
	glEnd();

	//podstawa dolna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.30, 0.30, 0.30);
	glVertex3f(x - halfL, y - halfW, z - halfH);
	glVertex3f(x - halfL, y + halfW, z - halfH);

	glVertex3f(x + halfL, y - halfW, z - halfH);
	glVertex3f(x + halfL, y + halfW, z - halfH);
	glEnd();


	//sciana boczna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.46, .46, 0.46);
	glVertex3f(x - halfL, y - halfW, z - halfH);
	glVertex3f(x - halfL, y - halfW, z + halfH);
	
	glVertex3f(x - halfL, y + halfW, z - halfH);
	glVertex3f(x - halfL, y + halfW, z + halfH);
	glEnd();

	//sciana boczna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.46, .46, 0.46);
	glVertex3f(x + halfL, y - halfW, z - halfH);
	glVertex3f(x + halfL, y - halfW, z + halfH);
	
	glVertex3f(x + halfL, y + halfW, z - halfH);
	glVertex3f(x + halfL, y + halfW, z + halfH);
	glEnd();


	//sciana boczna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.46, .46, 0.46);
	glVertex3f(x - halfL, y - halfW, z - halfH);
	glVertex3f(x - halfL, y - halfW, z + halfH);
	
	glVertex3f(x + halfL, y - halfW, z - halfH);
	glVertex3f(x + halfL, y - halfW, z + halfH);
	glEnd();


	//sciana boczna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.46, .46, 0.46);
	glVertex3f(x - halfL, y + halfW, z - halfH);
	glVertex3f(x - halfL, y + halfW, z + halfH);
	
	glVertex3f(x + halfL, y + halfW, z - halfH);
	glVertex3f(x + halfL, y + halfW, z + halfH);
	glEnd();

}

void Body::solarPanelTop(GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat nextElem_X = x;	//wspolrzedna X aktualnego elementu
	GLfloat nextElem_Y = y;	//wspolrzedna Y aktualnego elementu
	z += 0.01;				//tekstura musi byc nad gorna podstawa panelu

	for (int w = 1; w <= solarElemQuantity_W; w++) {

		for (int l = 1; l <= solarElemQuantity_L; l++) {

			glBegin(GL_TRIANGLE_STRIP);
			glColor3f(0.0, 0.10, 0.40);
			
			glVertex3f(nextElem_X, nextElem_Y, z);
			glVertex3f(nextElem_X + (solarElem_L* size), nextElem_Y, z);

			glVertex3f(nextElem_X, nextElem_Y + (solarElem_W*size), z);
			glVertex3f(nextElem_X + (solarElem_L*size), nextElem_Y + (solarElem_W*size), z);

			glEnd();

			nextElem_X += size*(solarElemSpace + solarElem_L);
		}

		nextElem_X = x;
		nextElem_Y += size*(solarElemSpace + solarElem_W);
	}		
}

void Body::solarPanelArm(GLfloat L, GLfloat H, GLint side, GLint order)
{
	//okreœlenie oznaczenia poszczególnych wartoœci argumentów
	//L - d³ugoœæ ramienia poziomego (obecnie nieuzywane, zdefiniowane w funkcji)
	//H - wysokoœæ ramienia pionowego (obecnie nieuzywane, zdefiniowane w funkcji)
	//side = 1 - lewa strona pok³adu (leftSide)
	//side = -1 - prawa strona pok³adu (rightSide)
	//order = 1 - ramie nr1, bli¿ej przedniej krawêdzi pok³adu
	//order = 2 - ramie nr2, bli¿ej tylnej krawêdzi pok³adu


	GLfloat frontOrBackEdge;
	GLfloat spaceFromEdges = 10.0f * size;		//space from top and back edge
	GLfloat armOnDeck = 10.0f * size;			//determines the length of the part of horizontal arm on board
	GLfloat leftOrRightEdge;

	if (side == 1) {
		leftOrRightEdge = leftEdge;
	}
	else {
		leftOrRightEdge = rightEdge;
	}

	GLfloat h = 4.0f * size;	//wysokoœæ ramienia
	GLfloat w = 7.0f * size;	//szerokoœæ ramienia

	GLfloat hArmL = 30.0f * size;	//horizontal arm length
	GLfloat vArmH = 20.0f * size;	//vertical arm height
	GLfloat hArmEnd = side * (leftOrRightEdge + side * (-armOnDeck + hArmL));	//ending coordinate of horizontal arm

	
	if (order == 1) {
		frontOrBackEdge = frontEdge;
	}
	else {
		frontOrBackEdge = backEdge;
		order = -1;
	}

	GLfloat armBase_X = frontOrBackEdge + order * (spaceFromEdges + (w / 2.0f));
	GLfloat armBase_Y = leftOrRightEdge - side*armOnDeck;
	GLfloat armBase_Z = deckH;

	GLfloat armBase_L = 8.0f * size;	//X axis lenght
	GLfloat armBase_W = 6.0f * size;	//Y axis width
	GLfloat armBase_H = 7.0f * size;	//Z axis height

	GLfloat armHandleX = frontOrBackEdge + order * (spaceFromEdges + (w/2.0));
	GLfloat armHandleY = side * (hArmEnd + (h / 2.0));
	GLfloat armHandleZ = deckH + vArmH;

	GLfloat armHandleL = 5.0f * size;
	GLfloat armHandleW = 4.0f * size;
	GLfloat armHandleH = 2.0f * size;


	// ---- ARM BASE ---- /
	//zaczyna sie od srodka krawedzi ramienia na pokladzie
	//dolna œciana
	GLfloat armBaseTopColor = 0.05;
	GLfloat armBaseOuterColor = 0.0;

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(armBaseTopColor, armBaseTopColor, armBaseTopColor);	//kolor rozpoczynajacy gradient
	glVertex3f(armBase_X - armBase_L, armBase_Y - armBase_W, armBase_Z);
	glVertex3f(armBase_X - armBase_L, armBase_Y + armBase_W, armBase_Z);
	glVertex3f(armBase_X + armBase_L, armBase_Y - armBase_W, armBase_Z);
	glVertex3f(armBase_X + armBase_L, armBase_Y + armBase_W, armBase_Z);
	glEnd();

	//górna œciana
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(armBaseTopColor, armBaseTopColor, armBaseTopColor);	//kolor rozpoczynajacy gradient
	glVertex3f(armBase_X - armBase_L, armBase_Y - armBase_W, armBase_Z + armBase_H);
	glVertex3f(armBase_X - armBase_L, armBase_Y + armBase_W, armBase_Z + armBase_H);
	glVertex3f(armBase_X + armBase_L, armBase_Y - armBase_W, armBase_Z + armBase_H);
	glVertex3f(armBase_X + armBase_L, armBase_Y + armBase_W, armBase_Z + armBase_H);
	glEnd();

	//œciana boczna przednia
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(armBaseOuterColor, armBaseOuterColor, armBaseOuterColor);
	glVertex3f(armBase_X - armBase_L, armBase_Y - armBase_W, armBase_Z);
	glVertex3f(armBase_X - armBase_L, armBase_Y - armBase_W, armBase_Z + armBase_H);
	glVertex3f(armBase_X - armBase_L, armBase_Y + armBase_W, armBase_Z);
	glVertex3f(armBase_X - armBase_L, armBase_Y + armBase_W, armBase_Z + armBase_H);
	glEnd();

	//œciana boczna tylna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(armBaseOuterColor, armBaseOuterColor, armBaseOuterColor);
	glVertex3f(armBase_X + armBase_L, armBase_Y - armBase_W, armBase_Z);
	glVertex3f(armBase_X + armBase_L, armBase_Y - armBase_W, armBase_Z + armBase_H);
	glVertex3f(armBase_X + armBase_L, armBase_Y + armBase_W, armBase_Z);
	glVertex3f(armBase_X + armBase_L, armBase_Y + armBase_W, armBase_Z + armBase_H);
	glEnd();

	//œciana boczna prawa
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(armBaseOuterColor, armBaseOuterColor, armBaseOuterColor);
	glVertex3f(armBase_X - armBase_L, armBase_Y - armBase_W, armBase_Z);
	glVertex3f(armBase_X - armBase_L, armBase_Y - armBase_W, armBase_Z + armBase_H);
	glVertex3f(armBase_X + armBase_L, armBase_Y - armBase_W, armBase_Z);
	glVertex3f(armBase_X + armBase_L, armBase_Y - armBase_W, armBase_Z + armBase_H);
	glEnd();

	//œciana boczna lewa
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(armBaseOuterColor, armBaseOuterColor, armBaseOuterColor);
	glVertex3f(armBase_X - armBase_L, armBase_Y + armBase_W, armBase_Z);
	glVertex3f(armBase_X - armBase_L, armBase_Y + armBase_W, armBase_Z + armBase_H);
	glVertex3f(armBase_X + armBase_L, armBase_Y + armBase_W, armBase_Z);
	glVertex3f(armBase_X + armBase_L, armBase_Y + armBase_W, armBase_Z + armBase_H);
	glEnd();

	

	// ---- HORIZONTAL ARM ---- //
	
		// sciana dolna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * spaceFromEdges, leftOrRightEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck), deckH);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH);
		glEnd();

		// sciana górna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * spaceFromEdges, leftOrRightEdge + side * (-armOnDeck), deckH + h);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH + h);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH + h);
		glEnd();


		// sciana boczna d³u¿sza nr1
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH + h);
		glEnd();

		// sciana boczna d³u¿sza nr2
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH + h);
		glEnd();

		// sciana boczna krotsza nr1
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck), deckH + h);
		glEnd();

		// sciana boczna krotsza nr2
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.50, 0.50, 0.50);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH + h);

		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH);
		glVertex3f(frontOrBackEdge + order * (spaceFromEdges + w), leftOrRightEdge + side * (-armOnDeck + hArmL), deckH + h);
		glEnd();



	// ---- VERTICAL ARM ---- //
		
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


	// ---- ARM HANDLE ---- //
	glPushMatrix();
	glTranslatef(armHandleX, armHandleY, armHandleZ);
	glRotatef(side*solarPanelAngle, 1.0f, 0.0f, 0.0f);
	
		double r = armHandleW, zOffset = r / 2.0;
		double y, z, alpha, PI = 3.14;

		GLfloat armHandleCylinderPartEnd = r / 2.0f;
		GLfloat armHandleCuboidPartEnd = armHandleH + (r / 2.0f);


		// --- CILINDER PART --- //
		
		//outter wall
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.35, 0.35, 0.35);
		for (alpha = 0.5 * PI; alpha <= 1.5 * PI; alpha += PI / 8.0) {

			y = r * sin(alpha);
			z = r * cos(alpha);

			glVertex3d(-side * armHandleL, y, z + zOffset);
			glVertex3d(side * armHandleL, y, z + zOffset);
		}
		glEnd();


		//base front
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.35, 0.35, 0.35);
		for (alpha = 0.5 * PI; alpha <= 1.5 * PI; alpha += PI / 8.0) {

			y = r * sin(alpha);
			z = r * cos(alpha);

			glVertex3d(side * armHandleL, y, z + zOffset);
			glVertex3d(side * armHandleL, y, z + zOffset);
		}
		glEnd();


		//base back
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.35, 0.35, 0.35);
		for (alpha = 0.5 * PI; alpha <= 1.5 * PI; alpha += PI / 8.0) {

			y = r * sin(alpha);
			z = r * cos(alpha);

			glVertex3d(-side * armHandleL, y, z + zOffset);
			glVertex3d(-side * armHandleL, y, z + zOffset);
		}
		glEnd();


		// --- CUBOID PART -- //
		//krotsza sciana boczna przednia
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25, 0.25, 0.25);
		glVertex3d(-side * armHandleL, -r, armHandleCylinderPartEnd);
		glVertex3d(-side * armHandleL, -r, armHandleCuboidPartEnd);

		glVertex3d(-side * armHandleL, +r, armHandleCylinderPartEnd);
		glVertex3d(-side * armHandleL, +r, armHandleCuboidPartEnd);
		glEnd();

		//krotsza sciana boczna tylna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25, 0.25, 0.25);
		glVertex3d(side * armHandleL, -r, armHandleCylinderPartEnd);
		glVertex3d(side * armHandleL, -r, armHandleCuboidPartEnd);

		glVertex3d(side * armHandleL, +r, armHandleCylinderPartEnd);
		glVertex3d(side * armHandleL, +r, armHandleCuboidPartEnd);
		glEnd();


		//d³u¿sza sciana boczna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25, 0.25, 0.25);
		glVertex3d(-side * armHandleL, -r, armHandleCylinderPartEnd);
		glVertex3d(side * armHandleL, -r, armHandleCylinderPartEnd);

		glVertex3d(-side * armHandleL, -r, armHandleCuboidPartEnd);
		glVertex3d(side * armHandleL, -r, armHandleCuboidPartEnd);
		glEnd();

		//d³u¿sza sciana boczna
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25, 0.25, 0.25);
		glVertex3d(-side * armHandleL, r, armHandleCylinderPartEnd);
		glVertex3d(side * armHandleL, r, armHandleCylinderPartEnd);

		glVertex3d(-side * armHandleL, r, armHandleCuboidPartEnd);
		glVertex3d(side * armHandleL, r, armHandleCuboidPartEnd);
		glEnd();


		//SOLAR PANEL
		if (order == 1)
			solarPanel(x - armHandleX, 0.0f, armHandleCuboidPartEnd + (solarPanel_H / 2.0f), solarPanel_L * size, solarPanel_W * size, solarPanel_H * size);
	
	glPopMatrix();
	
	
}



void Body::cameraNeck(GLfloat xOffset, GLfloat yOffset, GLfloat r, GLfloat h)
{
	/*
	---------
	|		|
	|		|	pozycja szyi jest defniowanaj z lewgo przedniego rogu
	|		|	pok³adu ³azika, patrzac na niego z góy
	|*		|
	---------
	*/

	GLfloat alpha, PI = 3.14;	
	GLfloat x,y,z = deckH;
	GLfloat totalOffsetX = frontEdge + size*xOffset;	//cameraNeck possition
	GLfloat totalOffsetY = leftEdge + size*yOffset;		//cameraNeck possition
	GLfloat cameraNeckEnd = deckH + size*h;

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.45, 0.45, 0.45);
	for (alpha = 0; alpha <= 2 * PI; alpha += PI / 50.0) {

		x = r * sin(alpha) * size;
		y = r * cos(alpha) * size;

		glVertex3d(x + totalOffsetX, y + totalOffsetY, z);
		glVertex3d(x + totalOffsetX, y + totalOffsetY, cameraNeckEnd);

	}
	glEnd();

	cameraHead(totalOffsetX, totalOffsetY, cameraNeckEnd, 9, 14, 10);
}

void Body::cameraHead(GLfloat x, GLfloat y, GLfloat z, GLfloat l, GLfloat w, GLfloat h)
{
	//x, y, z coordinates determine position of cameraNeck
	//multiplying by size is not required because argument has been multiplied in cameraNeck()
	//real cameraHead sizes are 2 times bigger than values pass in arguments

	l = size * l;	//x
	w = size * w;	//y
	h = size * h;	//z

	// ---- HEAD ---- //
	//podstawa dolna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.50, 0.50);
	glVertex3f(x - l, y - w, z);
	glVertex3f(x - l, y + w, z);

	glVertex3f(x + l, y - w, z);
	glVertex3f(x + l, y + w, z);
	glEnd();

	//podstawa górna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.50, 0.50);
	glVertex3f(x - l, y - w, z + h);
	glVertex3f(x - l, y + w, z + h);
	glVertex3f(x + l, y - w, z + h);
	glVertex3f(x + l, y + w, z + h);
	glEnd();

	//œciana boczna przednia
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.40, 0.40);
	glVertex3f(x - l, y - w, z);
	glVertex3f(x - l, y - w, z + h);

	glVertex3f(x - l, y + w, z);
	glVertex3f(x - l, y + w, z + h);
	glEnd();

	////œciana boczna tylna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.40, 0.40);
	glVertex3f(x + l, y - w, z);
	glVertex3f(x + l, y - w, z + h);
	glVertex3f(x + l, y + w, z);
	glVertex3f(x + l, y + w, z + h);
	glEnd();

	//œciana boczna lewa
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.40, 0.40);
	glVertex3f(x - l, y + w, z);
	glVertex3f(x - l, y + w, z + h);
	glVertex3f(x + l, y + w, z);
	glVertex3f(x + l, y + w, z + h);
	glEnd();

	//œciana boczna prawa
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.40, 0.40);
	glVertex3f(x - l, y - w, z);
	glVertex3f(x - l, y - w, z + h);
	glVertex3f(x + l, y - w, z);
	glVertex3f(x + l, y - w, z + h);
	glEnd();


	GLfloat neckOffset_X = x - l;			//first center towards neck(x), then center towards top left corner of head(-l), then set right possition on head(array[x])
	GLfloat neckOffset_Y = y + w;			//first center towards neck(y), then center towards top left corner of head(+w), then set right possition on head(array[y])
	GLfloat neckOffset_Z = z + h;			//first center towards neck(z), then center towards top left corner of head(+h), then set right possition on head(array[z])
	GLfloat neckOffsets[3] = { neckOffset_X, neckOffset_Y, neckOffset_Z };

	GLfloat bigEye[3] = { 0.0, 6.0, 5.0 };
	cameraEye(3.5, 1.5, neckOffsets, bigEye);

	GLfloat smallEye1[3] = { 0.0, 20.0, 3.0 };
	cameraEye(1.5, 2.0, neckOffsets, smallEye1);

	GLfloat smallEye2[3] = { 0.0, 25.0, 3.0 };
	cameraEye(1.5, 2.0, neckOffsets, smallEye2);

}

void Body::cameraEye(GLfloat eyeR, GLfloat eyeH, GLfloat neckOffsets[3], GLfloat headOffstets[3])
{

	//p³aszczyzna okreœlona jest przez oœ X i Z
	//wysokosc obiektywu okreslona jest przez os Y
	//neckOffsets[3] ustawia pozycje obiektywu na lewy gorny rog przedniej sciany kamery
	//headOffstets[3] ustawia pozycje obiektywu na przedniej sicanie kamery

	/*
	-------------
	|*			|
	|			|
	-------------
	*/

	eyeR = size * eyeR;
	eyeH = size * eyeH;

	GLfloat eyeStartX = 0;		//initial eye X possition
	GLfloat eyeStartY = 0;		//initial eye Y possition
	GLfloat	eyeStartZ = 0;		//initial eye Z possition

	GLfloat eyeOffsetX = neckOffsets[0];
	GLfloat eyeOffsetY = neckOffsets[1] - (headOffstets[1] * size);
	GLfloat eyeOffsetZ = neckOffsets[2] - (headOffstets[2] * size);


	GLfloat alpha, PI = 3.14;

	//tylna podstawa
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.35, 0.35, 0.35);
	for (alpha = 0; alpha <= 2 * PI; alpha += PI / 50.0) {

		eyeStartY = eyeR * sin(alpha);
		eyeStartZ = eyeR * cos(alpha);

		glVertex3d(eyeStartX + eyeOffsetX, eyeStartY + eyeOffsetY, eyeStartZ + eyeOffsetZ);
		glVertex3d(eyeStartX + eyeOffsetX, eyeStartY + eyeOffsetY, eyeStartZ + eyeOffsetZ);

	}
	glEnd();

	////gorna podstawa
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.35, 0.35, 0.35);
	for (alpha = 0; alpha <= 2 * PI; alpha += PI / 50.0) {

		eyeStartY = eyeR * sin(alpha);
		eyeStartZ = eyeR * cos(alpha);

		glVertex3d(eyeStartX + eyeOffsetX - eyeH, eyeStartY + eyeOffsetY, eyeStartZ + eyeOffsetZ);
		glVertex3d(eyeStartX + eyeOffsetX - eyeH, eyeStartY + eyeOffsetY, eyeStartZ + eyeOffsetZ);

	}
	glEnd();

	//sciana boczna
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.35, 0.35, 0.35);
	for (alpha = 0; alpha <= 2 * PI; alpha += PI / 50.0) {

		eyeStartY = eyeR * sin(alpha);
		eyeStartZ = eyeR * cos(alpha);

		glVertex3d(eyeStartX + eyeOffsetX, eyeStartY + eyeOffsetY, eyeStartZ + eyeOffsetZ);
		glVertex3d(eyeStartX + eyeOffsetX - eyeH, eyeStartY + eyeOffsetY, eyeStartZ + eyeOffsetZ);

	}
	glEnd();
	
}

void Body::Draw() {

	glPushMatrix();
	
	roverDeck(x, y, z, l, w, h); //[x,y,z] = offset to point [0,0,0]
		
	solarPanelArm(0 * size, 0 * size, -1, 1);	//right top
	solarPanelArm(0 * size, 0 * size, -1, 2);	//right back
	solarPanelArm(0 * size, 0 * size, 1, 1);	//left top	
	solarPanelArm(0 * size, 0 * size, 1, 2);	//left back

	cameraNeck(15.0, -22.0, 2.75, 50.0);
	
	glPopMatrix();
}

