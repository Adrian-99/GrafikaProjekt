#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include "SceneRenderer.h"

/// <summary>
/// Function called when window gets resized
/// </summary>
/// <param name="window">Resized window</param>
/// <param name="width">New window width</param>
/// <param name="height">New window height</param>
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    SceneRenderer::cameraDistance -= yoffset * 20;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    
    if (action == 1) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        SceneRenderer::clickMouseX = xpos;
        SceneRenderer::clickMouseY = ypos;
        SceneRenderer::currMouseX = xpos;
        SceneRenderer::currMouseY = ypos;
        std::cout << "mouse_button_callback: pressed -> " << xpos << " " << ypos << std::endl;
    }
    else {
        std::cout << "mouse_button_callback: released"<< std::endl;
    }
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
}



GLfloat SceneRenderer::cameraDistance = 300.f;
GLfloat SceneRenderer::clickMouseX = 0.f;;
GLfloat SceneRenderer::clickMouseY = 0.f;
GLfloat SceneRenderer::currMouseX = 0.f;
GLfloat SceneRenderer::currMouseY = 0.f;


int main() {
    #pragma region Creating window
    glfwInit();

    const int windowWidth = 800;
    const int windowHeight = 600;

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Grafika komputerowa - projekt", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    #pragma endregion

    framebuffer_size_callback(window, windowWidth, windowHeight);

    #pragma region Registering callbacks
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);     //unused
    #pragma endregion

    #pragma region Variables declarations
    SceneRenderer sceneRenderer(window);

    double frameStartTime, frameDuration;
    const unsigned short fpsLimit = 30;

    /*double lastTime = glfwGetTime();    //Simple FPS counter - to remove
    int nbFrames = 0;                   //Simple FPS counter - to remove*/
    #pragma endregion

    #pragma region Render loop
    while (!glfwWindowShouldClose(window))
    {
        frameStartTime = glfwGetTime();

        //Simple FPS counter
        // Measure speed
        /*double currentTime = glfwGetTime();
        nbFrames++;
        if (currentTime - lastTime >= 1.0) { // If last prinf() was more than 1 sec ago
            // printf and reset timer
            printf("%f ms/frame\n", 1000.0 / double(nbFrames));
            nbFrames = 0;
            lastTime += 1.0;
        }*/

        sceneRenderer.ProcessInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glEnable(GL_DEPTH_TEST);    //bardzo wazne okresla kolejnosc rysowania scian
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();

        // Draw thigs here
        sceneRenderer.RenderScene();

        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glFlush();

        glfwSwapBuffers(window);
        glfwPollEvents();

        frameDuration = (glfwGetTime() - frameStartTime) * 1000;
        if (frameDuration < 1000.0 / fpsLimit) Sleep(0.85 * (1000 / fpsLimit - (int)frameDuration));
    }
    #pragma endregion

    glfwTerminate();

	return 0;
}