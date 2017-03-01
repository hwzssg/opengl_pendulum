#include <iostream>
#include "draw.h"
#include <GL/glut.h>

using namespace std;

bool direction = true;
float angle = 0;
draw* panel;

void drawBob(float angle) {

    glTranslatef(-0.015f, 0.4f, 0.0f);
    glRotatef(angle, 0, 0, 1);
    panel->setColor("#BA68C8");
    panel->drawRect({-0.015f, 0, 0.015f, 0, 0.015f, -1, -0.015f, -1});

    glTranslatef(0.015f, -1, 0.0f);
    panel->setColor("#9C27B0");
    panel->drawCircle(0, 0, 0.15);

    panel->setColor("#AB47BC");
    panel->drawCircle(0, 0, 0.1);
}

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
    glLoadIdentity();                // Reset the model-view matrix

    drawBob(angle);

    if(direction) angle++;
    else angle--;

    if(angle > 45) direction = false;
    else if(angle < -45) direction = true;

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