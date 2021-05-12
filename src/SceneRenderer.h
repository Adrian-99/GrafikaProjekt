#pragma once
#include <GLFW/glfw3.h>
#include "Drawable/Rover.h"
#include "Drawable/Object.h"

class SceneRenderer
{
public:
	GLfloat xRot;
	GLfloat zRot;

private:
	Rover rover;
	Object rock2;
	Object rock3;
	Object rock4;
	Object t_rock;
	Object t_rock4;

	Object terrain;

public:
	SceneRenderer();
	void ProcessInput(GLFWwindow* window);
	void RenderScene(GLFWwindow* window);

private:
	void RotateCamera(GLfloat xRotation = 0.0f, GLfloat zRotation = 0.0f);
};

