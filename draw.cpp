#include "draw.h"
#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>


void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset the projection matrix
    if (width >= height) {
        // aspect >= 1, set the height from -1 to 1, with larger width
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    } else {
        // aspect < 1, set the width to -1 to 1, with larger height
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
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

void draw::drawTriangle(initializer_list<float> list) {
    vector<float> points = vector<float>(list.begin(), list.end());

    glBegin(GL_TRIANGLES);
    glVertex2f(points[0], points[1]);
    glVertex2f(points[2], points[3]);
    glVertex2f(points[4], points[5]);
    glEnd();
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