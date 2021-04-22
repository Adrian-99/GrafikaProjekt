#include "SceneRenderer.h"

SceneRenderer::SceneRenderer()
{
    xRot = 0.0f;
    zRot = 0.0f;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glPolygonMode(GL_BACK, GL_NONE);
}

void SceneRenderer::ProcessInput(GLFWwindow* window)
{	
	float rotationSpeed = 2.0f;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        RotateCamera(-rotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        RotateCamera(rotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        RotateCamera(0.0f, -rotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        RotateCamera(0.0f, rotationSpeed);
}

void SceneRenderer::RenderScene(GLFWwindow* window)
{
	// Parametry wierzcholkow
	GLfloat sa[3] = { 0.0f,0.0f,0.0f };
	GLfloat sb[3] = { 10.0f,0.0f,0.0f };
	GLfloat sc[3] = { 10.0f,10.0f,0.0f };
	GLfloat sd[3] = { 0.0f,10.0f,0.0f };
	GLfloat se[3] = { 0.0f,0.0f,-10.0f };
	GLfloat sf[3] = { 10.0f,0.0f,-10.0f };
	GLfloat sg[3] = { 10.0f,10.0f,-10.0f };
	GLfloat sh[3] = { 0.0f,10.0f,-10.0f };

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

void SceneRenderer::RotateCamera(GLfloat xRotation, GLfloat zRotation)
{
    xRot += xRotation;
    zRot += zRotation;

    while (xRot > 360) xRot -= 360;
    while (xRot < 0) xRot += 360;
    while (zRot > 360) zRot -= 360;
    while (zRot < 0) zRot += 360;
}