#include <iostream>
#include "draw.h"
#include <GL/glut.h>
#include <cmath>

using namespace std;

float angle = 3.14f / 6;
double angleAccel, angleVelocity = 0, dt = 0.1;
int length = 20;

draw* panel;

void drawBob(float passedAngle) {

    float angleRadian = passedAngle/3.14f*180;

    glTranslatef(0, 0.4f, 0.0f);
    glRotatef(angleRadian, 0, 0, 1);
    panel->setColor("#BA68C8");
    panel->drawRect({-0.015f, 0, 0.015f, 0, 0.015f, -1, -0.015f, -1});

    glTranslatef(0, -1, 0.0f);
    panel->setColor("#9C27B0");
    panel->drawCircle(0, 0, 0.15);

    panel->setColor("#AB47BC");
    panel->drawCircle(0, 0, 0.1);
}

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
    glLoadIdentity();                // Reset the model-view matrix


    angleAccel = -9.81 / length * sin(angle);
    angleVelocity += angleAccel * dt;
    angle += angleVelocity * dt;

    drawBob(angle);

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    panel = new draw(argc, argv);
    panel->setTitle("Pendulum Simulation");
    panel->setDrawFunction(drawFunc);

    panel->start();

    delete panel;
    return 0;
}