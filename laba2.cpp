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

struct Point {

    float x;
    float y;
    float z;
};

struct Edge {
    Edge(const std::vector<GLfloat>& coord, const std::vector<GLfloat>& color,
        const std::vector<GLubyte>& idx) : coord(coord), color(color), idx(idx) {}

    std::vector<GLfloat> coord;
    std::vector<GLfloat> color;
    std::vector<GLubyte> idx;

};


void drawSky(bool state, int w, int h) {
    std::vector<GLfloat> coordSky{ 0, 0, float(w), 0, float(w), 350, 0, 350 };
    std::vector<GLfloat> colorSkyDay{ 0.58, 0.85, 0.918, 0.58, 0.85, 0.918, 0.58, 0.85, 0.918, 0.58, 0.85, 0.918 };
    std::vector<GLfloat> colorSkyHigth{ 0.25, 0.28, 0.8, 0.25, 0.28, 0.8, 0.25, 0.28, 0.8, 0.25, 0.28, 0.8 };
    std::vector<GLubyte> idxSky{ 0, 1, 2, 3 };
    glVertexPointer(2, GL_FLOAT, 0, coordSky.data());
    glColorPointer(3, GL_FLOAT, 0, colorSkyDay.data());
    if (!state) {
        glColorPointer(3, GL_FLOAT, 0, colorSkyHigth.data());
    }
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, idxSky.data());
}

void drawGrass(bool state, int w, int h) {
    std::vector<GLfloat> coordGrass{ 0, 350, float(w), 350, float(w), float(h), 0, float(h) };
    std::vector<GLfloat> colorGrassDay{ 0.7, 0.9, 0.11, 0.7, 0.9, 0.11, 0.7, 0.9, 0.11, 0.7, 0.9, 0.11 };
    std::vector<GLfloat> colorGrassHigth{ 0.05, 0.26, 0.11, 0.05, 0.26, 0.11, 0.05, 0.26, 0.11, 0.05, 0.26, 0.11 };
    std::vector<GLubyte> idxGrass{ 0, 1, 2, 3 };
    glVertexPointer(2, GL_FLOAT, 0, coordGrass.data());
    glColorPointer(3, GL_FLOAT, 0, colorGrassDay.data());
    if (!state) {
        glColorPointer(3, GL_FLOAT, 0, colorGrassHigth.data());
    }
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, idxGrass.data());
}

void drawHouse(bool state) {
    std::vector<GLfloat> coord{ 600, 325, 800, 325, 800, 525, 600, 525 };
    std::vector<GLfloat> colorDay{ 0.73, 0.48, 0.34, 0.73, 0.48, 0.34, 0.73, 0.48, 0.34, 0.73, 0.48, 0.34 };
    std::vector<GLfloat> colorHigth{ 0.26, 0.f, 0.04, 0.26, 0.f, 0.04, 0.26, 0.f, 0.04, 0.26, 0.f, 0.04 };
    std::vector<GLubyte> idx{ 0, 1, 2, 3 };
    glVertexPointer(2, GL_FLOAT, 0, coord.data());
    glColorPointer(3, GL_FLOAT, 0, colorDay.data());
    if (!state) {
        glColorPointer(3, GL_FLOAT, 0, colorHigth.data());
    }
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, idx.data());
}

void drawRoof(bool state) {
    std::vector<GLfloat> coord{ 550, 325, 700, 200, 850, 325};
    std::vector<GLfloat> colorDay{ 0.81, 0.06, 0.1, 0.81, 0.06, 0.1, 0.81, 0.06, 0.1 };
    std::vector<GLfloat> colorHigth{ 0.55, 0.04, 0.07, 0.55, 0.04, 0.07, 0.55, 0.04, 0.07 };
    std::vector<GLubyte> idx{ 0, 1, 2 };
    glVertexPointer(2, GL_FLOAT, 0, coord.data());
    glColorPointer(3, GL_FLOAT, 0, colorDay.data());
    if (!state) {
        glColorPointer(3, GL_FLOAT, 0, colorHigth.data());
    }
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, idx.data());
}

void drawWindow(bool state) {
    std::vector<GLfloat> coord{ 650, 375, 750, 375, 750, 475, 650, 475 };
    std::vector<GLfloat> colorDay{ 0.8, 0.84, 0.84, 0.8, 0.84, 0.84, 0.8, 0.84, 0.84, 0.8, 0.84, 0.84 };
    std::vector<GLfloat> colorHigth{ 0.57, 0.64, 0.65, 0.57, 0.64, 0.65, 0.57, 0.64, 0.65, 0.57, 0.64, 0.65 };
    std::vector<GLubyte> idx{ 0, 1, 2, 3 };
    glVertexPointer(2, GL_FLOAT, 0, coord.data());
    glColorPointer(3, GL_FLOAT, 0, colorDay.data());
    if (!state) {
        glColorPointer(3, GL_FLOAT, 0, colorHigth.data());
    }
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, idx.data());
}

void drawWindowRamc() {
    glLineWidth(5.f);
    std::vector<GLfloat> coord{ 650, 375, 750, 375, 750, 475, 650, 475 };
    std::vector<GLfloat> color{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    std::vector<GLubyte> idx{ 0, 1, 2, 3 };
    glVertexPointer(2, GL_FLOAT, 0, coord.data());
    glColorPointer(3, GL_FLOAT, 0, color.data());
    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, idx.data());
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(900, 600, "My little house ^-^", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    
    float xPos = -50.f;
    float yPos = 100.f;
    float radius = 50.f;
    float xPosMoon = -70.f;
    float yPosMoon = 100.f;
    float radiusMoon = 40.f;
    float speed = 0;
    bool state = true;

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
        glLoadIdentity();

       
        drawSky(state, width, height);
        drawGrass(state, width, height);
        drawHouse(state);
        drawRoof(state);
        drawWindow(state);
        drawWindowRamc();

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
                glColor3f(0.25, 0.28, 0.8);
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