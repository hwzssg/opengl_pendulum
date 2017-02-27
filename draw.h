#ifndef PENDULUM_DRAW_H
#define PENDULUM_DRAW_H

#include <string>

typedef void (*callback_function)(void);

using namespace std;

class draw {
private:
    callback_function drawFunc;

public:
    draw(int argc, char **argv);

    void setTitle(string title);
    void setDrawFunction(callback_function drawFunc);
    void setColor(string color);

    void drawTriangle(initializer_list<float> list);

    void start();

};


#endif //PENDULUM_DRAW_H
