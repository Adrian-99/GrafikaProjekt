#include "SceneRenderer.h"

SceneRenderer::SceneRenderer() :
    leftWheelsWithLinks(0.0f, -30.0f, 20.0f, 1.0f, true),
    rightWheelsWithLinks(0.0f, 30.0f, 20.0f, 1.0f, false)
{
    xRot = 0.0f;
    zRot = 0.0f;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glPolygonMode(GL_BACK, GL_NONE);
}

void SceneRenderer::ProcessInput(GLFWwindow* window)
{	
	float rotationSpeed = 0.5f;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        RotateCamera(rotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        RotateCamera(-rotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        RotateCamera(0.0f, rotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        RotateCamera(0.0f, -rotationSpeed);
}

void SceneRenderer::RenderScene(GLFWwindow* window)
{
    leftWheelsWithLinks.Draw();
    rightWheelsWithLinks.Draw();
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