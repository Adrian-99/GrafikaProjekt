#pragma once
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include "Drawable/Rover.h"
#include "Drawable/Object.h"

class SceneRenderer
{
public:
	static GLfloat cameraDistance;
	static GLfloat clickMouseX;
	static GLfloat clickMouseY;
	static GLfloat currMouseX;
	static GLfloat currMouseY;

private:
	GLFWwindow* window;

	GLfloat CameraXRotation;
	GLfloat CameraZRotation;
	
	Rover rover;
	Object rock2;
	Object rock3;
	Object rock4;
	Object t_rock;
	Object t_rock4;

	Object terrain;

public:
	SceneRenderer(GLFWwindow* window);
	void ProcessInput();
	void RenderScene();

private:
	void RotateCamera(GLfloat xRotation = 0.0f, GLfloat zRotation = 0.0f);
	void UpdateCameraPosition();
};

