#include "draw.h"
#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>


void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if (width >= height)
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    else
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
}

draw::draw(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(720, 720);
    glutInitWindowPosition(600, 200);
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

    glColor3d(_r/255.0, _g/255.0, _b/255.0);

}

void draw::drawRect(initializer_list<float> list) {
    vector<float> points = vector<float>(list.begin(), list.end());

    glBegin(GL_QUADS);
    glVertex2f(points[0], points[1]);
    glVertex2f(points[2], points[3]);
    glVertex2f(points[4], points[5]);
    glVertex2f(points[6], points[7]);
    glEnd();
}

void draw::drawRect(float x, float y, float width, float height) {
    float x2 = x + width;
    float y3 = y + height;

    glTranslatef(-width/2, 0, 0);
    drawRect({ x, y, x2, y, x2, y3, x, y3 });
    glTranslatef(width/2, 0, 0);
}

void draw::drawCircle(float cx, float cy, float r) {
    int points = 100;

    glBegin(GL_POLYGON);
    for(int i = 0; i < points; i++) {
        float theta = 2.0f * 3.1415926f * float(i)/float(points);

        float x = r * cos(theta);
        float y = r * sin(theta);

        glVertex2f(x + cx, y + cy);

    }
    glEnd();
}

void glInit() {
    glClearColor(0.8, 0.8, 0.8, 1);
}

void draw::start() {
    glInit();
    glutDisplayFunc(drawFunc);
    glutIdleFunc(drawFunc);
    glutReshapeFunc(reshape);
    glutMainLoop();
}