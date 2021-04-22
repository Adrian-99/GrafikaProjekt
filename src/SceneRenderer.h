#pragma once
#include <GLFW/glfw3.h>
#include "Cube.h"
#include "Wheel.h"

class SceneRenderer
{
public:
	GLfloat xRot;
	GLfloat zRot;

private:
	Cube exampleCube;
	Wheel exampleWheel;

public:
	SceneRenderer();
	void ProcessInput(GLFWwindow* window);
	void RenderScene(GLFWwindow* window);

private:
	void RotateCamera(GLfloat xRotation = 0.0f, GLfloat zRotation = 0.0f);
};

