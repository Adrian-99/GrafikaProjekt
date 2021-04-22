#include "Cube.h"

Cube::Cube(GLfloat x, GLfloat y, GLfloat z, GLfloat size)
{
	sa[0] = x - size;
	sa[1] = y - size;
	sa[2] = z + size;

	sb[0] = x + size;
	sb[1] = y - size;
	sb[2] = z + size;

	sc[0] = x + size;
	sc[1] = y + size;
	sc[2] = z + size;

	sd[0] = x - size;
	sd[1] = y + size;
	sd[2] = z + size;

	se[0] = x - size;
	se[1] = y - size;
	se[2] = z - size;

	sf[0] = x + size;
	sf[1] = y - size;
	sf[2] = z - size;

	sg[0] = x + size;
	sg[1] = y + size;
	sg[2] = z - size;

	sh[0] = x - size;
	sh[1] = y + size;
	sh[2] = z - size;
}

void Cube::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		// Sciany skladowe
		// sciana czerwona - przod
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sc);
		glVertex3fv(sd);
		glEnd();

		//sciana zielona - prawy bok
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(sb);
		glVertex3fv(sf);
		glVertex3fv(sg);
		glVertex3fv(sc);
		glEnd();

		//sciana niebieska - tyl
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(sf);
		glVertex3fv(se);
		glVertex3fv(sh);
		glVertex3fv(sg);
		glEnd();

		//sciana zolta - lewy bok
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(se);
		glVertex3fv(sa);
		glVertex3fv(sd);
		glVertex3fv(sh);
		glEnd();

		//sciana jasno niebieska (cyan) - gora
		glColor3f(0.0f, 1.0f, 1.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(sd);
		glVertex3fv(sc);
		glVertex3fv(sg);
		glVertex3fv(sh);
		glEnd();

		//sciana rozowa (magenta) - spod
		glColor3f(1.0f, 0.5f, 0.6f);
		glBegin(GL_POLYGON);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sf);
		glVertex3fv(se);
		glEnd();
	}
}
