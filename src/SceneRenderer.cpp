#include "SceneRenderer.h"


SceneRenderer::SceneRenderer() :
    rover(Vector3(0.0f, 0.0f, 30.0f), 1.0f),

    rock2("rock2", Vector3(), 5.0f),
    rock3("rock3", Vector3(0.0f, 0.0f, 50.0f), 50.0f),
    rock4("rock4", Vector3(0.0f, 0.0f, 60.0f), 70.0f),
    t_rock("t_rock", Vector3(0.0f, 0.0f, 55.0f), 3.0f),
    t_rock4("t_rock4", Vector3(0.0f, 0.0f, -5.0f), 1.0f),
    terrain("terrain", Vector3(), 1.0f)
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

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        rover.AddWheelsTurnAngle(4.0f);

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        rover.AddWheelsTurnAngle(-4.0f);
}

void SceneRenderer::RenderScene(GLFWwindow* window)
{
    rover.Draw();

    terrain.Draw();

    t_rock.DrawDuplicate(Vector3(-450.0f, 30.0f, 0.0f), 5.0f);
    t_rock.DrawDuplicate(Vector3(842.0f, 965.0f, 0.0f), 65.0f);
    t_rock.DrawDuplicate(Vector3(937.0f, -386.0f, 0.0f), 53.0f);
    t_rock.DrawDuplicate(Vector3(-214.0f, -937.0f, 0.0f), 21.0f);
    rock2.DrawDuplicate(Vector3(-700.0f, -450.0f, 0.0f), 30.0f);
    rock2.DrawDuplicate(Vector3(725.0f, 1053.0f, 0.0f), 38.0f);
    rock2.DrawDuplicate(Vector3(30.0f, -1320.0f, 0.0f), 73.0f);
    rock2.DrawDuplicate(Vector3(1274.0f, -57.0f, 0.0f), 64.0f);
    rock3.DrawDuplicate(Vector3(845.0f, -602.0f, 0.0f), 95.0f);
    rock3.DrawDuplicate(Vector3(-1322.0f, -321.0f, -30.0f), 32.0f);
    rock3.DrawDuplicate(Vector3(456.0f, -1434.0f, 0.0f), 52.0f);
    rock3.DrawDuplicate(Vector3(-634.0f, 678.0f, 0.0f), 103.0f);
    t_rock4.DrawDuplicate(Vector3(523.0f, 645.0f, 0.0f), 32.0f);
    t_rock4.DrawDuplicate(Vector3(-132.0f, 885.0f, -10.0f), 142.0f);
    t_rock4.DrawDuplicate(Vector3(842.0f, -1075.0f, -10.0f), 74.0f);
    t_rock4.DrawDuplicate(Vector3(-1042.0f, -892.0f, 0.0f), 98.0f);
    rock4.DrawDuplicate(Vector3(463.0f, 1193.0f, 0.0f), 45.0f);

    rover.WheelsCentering();
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