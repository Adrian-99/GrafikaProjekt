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
    GLfloat nRange = 100.0f;
    GLfloat fAspect;

    fAspect = (GLfloat)width / (GLfloat)height;
    // Set Viewport to window dimensions
    glViewport(0, 0, width, height);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    /*if (width <= height)
        glOrtho(-nRange, nRange, -nRange * height / width, nRange * height / width, -nRange, nRange);
    else
        glOrtho(-nRange * width / height, nRange * width / height, -nRange, nRange, -nRange, nRange);*/

    // Establish perspective: 
    gluPerspective(60.0f,fAspect,1.0,4000);
    gluLookAt(0.0f, 0.0f, 300.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

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
    #pragma endregion

    #pragma region Variables declarations
    SceneRenderer sceneRenderer{};

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

        sceneRenderer.ProcessInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glEnable(GL_DEPTH_TEST);    //bardzo wazne okresla kolejnosc rysowania scian
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();

        glRotatef(sceneRenderer.xRot, 1.0f, 0.0f, 0.0f);
        glRotatef(sceneRenderer.zRot, 0.0f, 0.0f, 1.0f);

        // Draw thigs here
        sceneRenderer.RenderScene(window);

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