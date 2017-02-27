#include <iostream>
#include "draw.h"
#include <GL/glut.h>

using namespace std;

draw* panel;

void drawBob(float x, float y) {
    float cx = x;
    float cy = -1.0f + y;

    glTranslatef(0.0f, 0.4f, 0.0f);
    panel->setColor("#BA68C8");
    panel->drawRect({-0.015f, 0, 0.015f, 0, 0.015f+cx, cy, -0.015f+cx, cy});

    glTranslatef(cx, cy, 0.0f);
    panel->setColor("#9C27B0");
    panel->drawCircle(0, 0, 0.15);

    panel->setColor("#AB47BC");
    panel->drawCircle(0, 0, 0.1);
}

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
    glLoadIdentity();                // Reset the model-view matrix

    drawBob(0.2, 0);

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