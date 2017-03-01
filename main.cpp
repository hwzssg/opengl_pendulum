#include <iostream>
#include "draw.h"
#include <GL/glut.h>
#include <cmath>
#include <ctime>

using namespace std;


// Pendulum related variables
double angle = M_PI / 6;
double angleAcceleration, angleVelocity = 0, dt = 0.1;
float length = 9.44;

// Clock related variables
int clocks, seconds;

draw* panel;

void drawClock() {
    float secondsAngle = (seconds%60)/60.0f*360;
    float minutesAngle = (seconds/60)/60.0f*360;
    float hoursAngle = (seconds/60/60)/12.0f*360;

    glLoadIdentity();

    glTranslatef(0, 0.4f, 0.0f);

    panel->setColor("#E91E63");
    panel->drawCircle(0, 0, 0.4);
    panel->setColor("#F48FB1");
    panel->drawCircle(0, 0, 0.35);

    panel->setColor("#F50057");

    glRotatef(-secondsAngle, 0, 0, 1);
    panel->drawRect(0, 0, 0.008, 0.3);
    glRotatef(secondsAngle, 0, 0, 1);

    glRotatef(-minutesAngle, 0, 0, 1);
    panel->drawRect(0, 0, 0.015, 0.26);
    glRotatef(minutesAngle, 0, 0, 1);

    glRotatef(-hoursAngle, 0, 0, 1);
    panel->drawRect(0, 0, 0.025, 0.15);
    glRotatef(hoursAngle, 0, 0, 1);
}

void drawBob(double passedAngle) {
    glLoadIdentity();

    double angleDegree = passedAngle/M_PI*180;

    glTranslatef(0, 0.4f, 0.0f);
    glRotated(angleDegree, 0, 0, 1);
    panel->setColor("#BA68C8");
    panel->drawRect(0, 0, 0.03, -1);

    glTranslatef(0, -1, 0.0f);
    panel->setColor("#9C27B0");
    panel->drawCircle(0, 0, 0.15);

    panel->setColor("#AB47BC");
    panel->drawCircle(0, 0, 0.1);

    glTranslatef(0, 1.0f, 0.0f);
}

void drawFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    angleAcceleration = -9.81 / length * sin(angle);
    angleVelocity += angleAcceleration * dt;
    angle += angleVelocity * dt;

    drawBob(angle);
    drawClock();

    clocks++;
    if(clocks%60 == 0)
        seconds++;

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    seconds = ltm->tm_sec + 60*ltm->tm_min + 60*60*ltm->tm_hour;


    panel = new draw(argc, argv);
    panel->setTitle("Pendulum Simulation");
    panel->setDrawFunction(drawFunc);

    panel->start();

    delete panel;
    return 0;
}