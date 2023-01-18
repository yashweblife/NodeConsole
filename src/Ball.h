#ifndef Ball_h
#define Ball_h

#include <Arduino.h>
#include <Vector.h>
#include <OledHelper.h>

class Ball
{
public:
    Vector pos;
    Vector vel;
    Vector acc;
    int size;

    Ball();
    Ball(int start_x = 64, int start_y = 32);
    void setSize(int val);
    void setPos(int x, int y);
    void setVel(int x, int y);
    void setAcc(int x, int y);
    void reverseVel(bool comp=false);
    void bound(int x = 0, int y = 0, int dx = 128, int dy = 64);
    bool checkCollisionWithBall(Ball b);
    bool checkCollisionWithBox();
    void draw(OledHelper *oled);
    void update();
};

#endif