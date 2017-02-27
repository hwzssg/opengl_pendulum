#include <iostream>
#include "draw.h"
#include <GL/glut.h>

using namespace std;

draw* panel;

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    panel->setColor("#EC407A");
    panel->drawCircle(0, 0, 0.8);

    panel->setColor("#7E57C2");
    panel->drawTriangle(
            {
                    -0.8, 0.76,
                    0.8, 0.76,
                    0, -0.8
            }
    );

    panel->setColor("#9575CD");
    panel->drawTriangle(
            {
                    -0.7, 0.7,
                    0.7, 0.7,
                    0, -0.7
            }
    );

    glFlush();
}

int main(int argc, char **argv) {
    panel = new draw(argc, argv);
    panel->setTitle("Pendulum Simulation");
    panel->setDrawFunction(drawFunc);

    panel->start();

    delete panel;
    return 0;
}