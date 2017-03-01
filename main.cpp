#include <iostream>
#include "draw.h"
#include <GL/glut.h>
#include <cmath>

using namespace std;

float angle = 3.14f / 6;
double angleAccel, angleVelocity = 0, dt = 0.1;
int length = 20;

draw* panel;

void drawClock() {
    glLoadIdentity();

    glTranslatef(0, 0.4f, 0.0f);

    panel->setColor("#E91E63");
    panel->drawCircle(0, 0, 0.4);
    panel->setColor("#F48FB1");
    panel->drawCircle(0, 0, 0.35);



}

void drawBob(float passedAngle) {
    glLoadIdentity();

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

    glTranslatef(0, 1.0f, 0.0f);
}

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix

    angleAccel = -9.81 / length * sin(angle);
    angleVelocity += angleAccel * dt;
    angle += angleVelocity * dt;

    drawBob(angle);
    drawClock();

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