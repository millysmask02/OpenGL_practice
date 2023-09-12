#include <glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory>
#include <vector>
#include <iostream>

const int steps = 30;
const float angle = 3.1415926 * 2.f / steps;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}



int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(900, 600, "Simple example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    float xPos = -50.f;
    float yPos = 100.f;
    float radius = 50.f;
    float xPosMoon = -70.f;
    float yPosMoon = 100.f;
    float radiusMoon = 40.f;
    float speed = 0;
    bool state = true; // 1 - day, 0 - hight
    std::vector<float> x(100);
    for (float &i : x) {
        i = float(rand() % 900);
    }
    std::vector<float> y(100);
    for (float& i : y) {
        i = float(rand() % 350);
    }
    while (!glfwWindowShouldClose(window)) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0f, width, height, 0.0f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
       
        
        // цвета дня и ночи
        GLfloat colorSkyDay[3] = { 0.58, 0.85, 0.918 };
        GLfloat colorSkyHight[3] = { 0.25, 0.28, 0.8 };
        GLfloat colorGrassDay[3] = { 0.7, 0.9, 0.11 };
        GLfloat colorGrassHight[3] = { 0.05, 0.26, 0.11 };
        GLfloat colorHouseDay[3] = { 0.73, 0.48, 0.34 };
        GLfloat colorHouseHight[3] = { 0.26, 0.f, 0.04 };
        GLfloat colorRoofDay[3] = { 0.81, 0.06, 0.1 };
        GLfloat colorRoofHight[3] = { 0.55, 0.04, 0.07 };
        GLfloat colorWindowDay[3] = { 0.8, 0.84, 0.84 };
        GLfloat colorWindowHight[3] = { 0.57, 0.64, 0.65 };
       
        // небо
        glBegin(GL_POLYGON);
            glColor3fv(colorSkyDay);
            if (!state) {
                glColor3fv(colorSkyHight);
            }
            glVertex2f(0.f, 0.f);
            glVertex2f(width, 0.f);
            glVertex2f(width, 350.f);
            glVertex2f(0.f, 350.f);
        glEnd();

        // трава
        glBegin(GL_POLYGON);
            glColor3fv(colorGrassDay);
            if (!state) {
                glColor3fv(colorGrassHight);
            }
            glVertex2f(0.f, 350.f);
            glVertex2f(width, 350.f);
            glVertex2f(width, height);
            glVertex2f(0.f, height);
        glEnd();

        glPointSize(3);
        if (!state) {
            glBegin(GL_POINTS);
            for(int i = 0; i < 100; i++) {
                glColor3f(1, 1, 1);
                glVertex2f(x[i], y[i]);
            }
            glEnd();
        }

        glBegin(GL_POLYGON);
            glColor3fv(colorHouseDay);
            if (!state) {
                glColor3fv(colorHouseHight);
            }
            glVertex2f(600.f, 325.f);
            glVertex2f(800.f, 325.f);
            glVertex2f(800.f, 525.f);
            glVertex2f(600.f, 525.f);
        glEnd();

        
        glBegin(GL_TRIANGLES);
            glColor3fv(colorRoofDay);
            if (!state) {
                glColor3fv(colorRoofHight);
            }
            glVertex2f(550.f, 325.f);
            glVertex2f(700.f, 200.f);
            glVertex2f(850.f, 325.f);
        glEnd();

        
        glBegin(GL_POLYGON);
            glColor3fv(colorWindowDay);
            if (!state) {
                glColor3fv(colorWindowHight);
            }
            glVertex2f(650.f, 375.f);
            glVertex2f(750.f, 375.f);
            glVertex2f(750.f, 475.f);
            glVertex2f(650.f, 475.f);
        glEnd();

        glLineWidth(5.f);
        glBegin(GL_LINE_LOOP);
            glColor3f(0.f, 0.f, 0.f);
            glVertex2f(650.f, 375.f);
            glVertex2f(750.f, 375.f);
            glVertex2f(750.f, 475.f);
            glVertex2f(650.f, 475.f);
        glEnd();

        glBegin(GL_LINES);
            glColor3f(0.f, 0.f, 0.f);
            glVertex2f(700.f, 375.f);
            glVertex2f(700.f, 475.f);
        glEnd();

        glBegin(GL_LINES);
            glColor3f(0.f, 0.f, 0.f);
            glVertex2f(650.f, 425.f);
            glVertex2f(750.f, 425.f);
        glEnd();
   
        
        float prevX = xPos;
        float prevY = yPos - radius;
        for (int i = 0; i <= steps; i++) {
            float newX = xPos + radius * sin(angle * i);
            float newY = yPos + radius * cos(angle * i);

            glBegin(GL_TRIANGLES);
                glColor3f(1.f, 0.9, 0.f);
                if (!state) {
                    glColor3f(0.83, 0.83, 83.f);

                }
                glVertex2f(speed + xPos, 50.f);
                glVertex2f(speed + prevX, prevY);
                glVertex2f(speed + newX, newY);
            glEnd();

            prevX = newX;
            prevY = newY;
        }
        if (!state) {
            float moonX = xPosMoon;
            float moonY = yPosMoon - radiusMoon;
            for (int i = 0; i <= steps; i++) {
                float newXMoon = xPosMoon + radiusMoon * sin(angle * i);
                float newYMoon = yPosMoon + radiusMoon * cos(angle * i);

                glBegin(GL_TRIANGLES);
                glColor3fv(colorSkyHight);
                glVertex2f(speed + xPosMoon, 60.f);
                glVertex2f(speed + moonX, moonY);
                glVertex2f(speed + newXMoon, newYMoon);
                glEnd();

                moonX = newXMoon;
                moonY = newYMoon;
            }
        }
        speed += 0.1;

        if (speed > width + 100) {
            state = (state + 1) % 2;
            speed = -50;
        }

        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}