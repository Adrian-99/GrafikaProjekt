#include "SceneRenderer.h"


SceneRenderer::SceneRenderer(GLFWwindow* window) :
    rover(Vector3(0.0f, 0.0f, 0.0f), 1.0f),

    rock2("rock2", Vector3(), 5.0f),
    rock3("rock3", Vector3(0.0f, 0.0f, 50.0f), 50.0f),
    rock4("rock4", Vector3(0.0f, 0.0f, 60.0f), 70.0f),
    t_rock("t_rock", Vector3(0.0f, 0.0f, 55.0f), 3.0f),
    t_rock4("t_rock4", Vector3(0.0f, 0.0f, -5.0f), 1.0f),
    terrain("terrain", Vector3(), 1.0f)
{
    CameraXRotation = 30.0f;
    CameraZRotation = 180.0f;

    this->window = window;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_NONE);
}

void SceneRenderer::ProcessInput()
{	
	GLfloat cameraRotationSpeed = 1.5f;
    GLfloat mouseCameraRotationSpeed = 4.0f;
    GLfloat additionalTurnAngle = 0.0f;
    GLfloat moveDirection = 0.0f;           //1=moveForward  -1=moveBackward, 0=staying

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        RotateCamera(cameraRotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        RotateCamera(-cameraRotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        RotateCamera(0.0f, cameraRotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        RotateCamera(0.0f, -cameraRotationSpeed);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        moveDirection = 1.0f;

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        moveDirection = -1.0f;

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        additionalTurnAngle += 2.0f;

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        additionalTurnAngle -= 2.0f;


    //MOUSE EVENTS

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        //std::cout << xpos << "-" << ypos << std::endl;

        GLfloat tolerance = 25.0f;

        /*if (abs(clickMouseX - currMouseX) > 100) mouseCameraRotationSpeed = 2.0f;
        if (abs(clickMouseX - currMouseX) > 200) mouseCameraRotationSpeed = 4.0f;
        if (abs(clickMouseX - currMouseX) > 300) mouseCameraRotationSpeed = 6.0f;
        if (abs(clickMouseX - currMouseX) > 400) mouseCameraRotationSpeed = 8.0f;
        if (abs(clickMouseX - currMouseX) > 500) mouseCameraRotationSpeed = 10.0f;
        if (abs(clickMouseX - currMouseX) > 600) mouseCameraRotationSpeed = 12.0f;*/

        //horizontal swipe
        //if (ypos <= clickMouseY + tolerance and ypos >= clickMouseY - tolerance) {

            std::cout <<  "-" << std::endl;
            if (currMouseX - xpos > 0) {
                //move camera to the left
                std::cout << "move camera to the left" << std::endl;
                CameraZRotation += mouseCameraRotationSpeed;
            }
            else if (currMouseX - xpos < 0) {
                //move camera to the right
                std::cout << "move camera to the right" << std::endl;
                CameraZRotation -= mouseCameraRotationSpeed;
            }

            currMouseX = xpos;
            currMouseY = ypos;

        //}

    }

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout << xpos << ypos << std::endl;

        GLfloat tolerance = 25.0f;

        //vertical swipe
        /*if (xpos <= clickMouseX + tolerance and xpos >= clickMouseX - tolerance) {*/

            if (currMouseY - ypos > 0) {
                //move camera to the left
                std::cout << "move camera to the left" << std::endl;
                CameraXRotation += mouseCameraRotationSpeed / 2.0f;
            }
            else if (currMouseY - ypos < 0) {
                //move camera to the right
                std::cout << "move camera to the right" << std::endl;
                CameraXRotation -= mouseCameraRotationSpeed / 2.0f;
            }

            currMouseX = xpos;
            currMouseY = ypos;

        //}

    }

    rover.ProcessInput(moveDirection, additionalTurnAngle);
}

void SceneRenderer::RenderScene()
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

    UpdateCameraPosition();
}

void SceneRenderer::RotateCamera(GLfloat xRotation, GLfloat zRotation)
{
    CameraXRotation += xRotation;
    CameraZRotation += zRotation;

    //while (CameraXRotation > 360) CameraXRotation -= 360;
    //while (CameraXRotation < 0) CameraXRotation += 360;
    if (CameraXRotation < 0.0f) CameraXRotation = 0.0f;
    else if (CameraXRotation > 89.0f) CameraXRotation = 89.0f;
    while (CameraZRotation > 360) CameraZRotation -= 360;
    while (CameraZRotation < 0) CameraZRotation += 360;
}

void SceneRenderer::UpdateCameraPosition()
{
    GLint width, height;
    glfwGetFramebufferSize(window, &width, &height);
    Vector3 roverPosition = rover.GetPosition();
    GLfloat roverRotation = rover.GetRotation();
    Vector3 cameraPosition;

    cameraPosition = roverPosition + Vector3(
        cos((-CameraZRotation + roverRotation) * 0.01745329252f) * cos(CameraXRotation * 0.01745329252f) * cameraDistance,
        sin((-CameraZRotation + roverRotation) * 0.01745329252f) * cos(CameraXRotation * 0.01745329252f) * cameraDistance,
        sin(CameraXRotation * 0.01745329252f) * cameraDistance + 50.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 1.0, 4000);
    gluLookAt(cameraPosition.X(), cameraPosition.Y(), cameraPosition.Z(), roverPosition.X(), roverPosition.Y(), roverPosition.Z(), 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}
