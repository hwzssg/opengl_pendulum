#include <iostream>
#include "draw.h"
#include <GL/glut.h>

using namespace std;

draw* panel;

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    panel->setColor("#33b5e5");
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