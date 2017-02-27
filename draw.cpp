#include "draw.h"
#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <vector>

draw::draw(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
}

void draw::setTitle(string title) {
    glutCreateWindow(title.c_str());
}

void draw::setDrawFunction(callback_function drawFunc) {
    this->drawFunc = drawFunc;
}

void draw::setColor(string color) {
    stringstream r(color.substr(1, 2));
    stringstream g(color.substr(3, 2));
    stringstream b(color.substr(5, 2));

    unsigned int _r, _g, _b;
    r >> hex >> _r;
    g >> hex >> _g;
    b >> hex >> _b;

    glColor3f(_r/255.0, _g/255.0, _b/255.0);

}

void draw::drawTriangle(initializer_list<double> list) {
    vector<double > points = vector<double >(list.begin(), list.end());

    glBegin(GL_TRIANGLES);
    glVertex2d(points[0], points[1]);
    glVertex2d(points[2], points[3]);
    glVertex2d(points[4], points[5]);
    glEnd();
}

void glInit() {
    glClearColor(0.8, 0.8, 0.8, 1);
}

void draw::start() {
    glInit();
    glutDisplayFunc(drawFunc);
    glutMainLoop();
}