#include "SceneRenderer.h"


SceneRenderer::SceneRenderer() :
    rover(100.0f, 0.0f, 0.0f, 1.0f),
    rock1("rock", -100.0f, -150.0f, 0.0f, 70.0f),
    rock2("rock2", -100.0f, -50.0f, 0.0f, 5.0f),
    rock3("rock3", -100.0f, 50.0f, 0.0f, 10.0f),
    rock4("rock4", -100.0f, 150.0f, 0.0f, 10.0f)
{
    xRot = 0.0f;
    zRot = 0.0f;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_NONE);
}

void SceneRenderer::ProcessInput(GLFWwindow* window)
{	
	float rotationSpeed = 1.5f;

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
    rover.Draw();
    //rock1.Draw();
    rock2.Draw();
    rock3.Draw();
    //rock3.DrawDuplicate(Vector3(-30.0f, 0.0f, 0.0f));
    //rock3.DrawDuplicate(Vector3(0.0f, 30.0f, 0.0f));
    //rock3.DrawDuplicate(Vector3(0.0f, 0.0f, 30.0f));
    rock4.Draw();
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