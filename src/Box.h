#ifndef Box_h
#define Box_h

#include <Arduino.h>
#include <Vector.h>
#include <OledHelper.h>
#include <Ball.h>
class Box
{
public:
    Vector pos;
    Vector vel;
    Vector acc;
    Vector size;
    float radius;

    Box();
    Box(int start_x, int start_y);
    void setSize(int x, int y);
    void setPos(int x, int y);
    void setVel(int x, int y);
    void setAcc(int x, int y);
    void reverseVel(bool comp = false);
    int bound(int x = 0, int y = 0, int dx = 128, int dy = 64);
    bool checkCollisionWithBall(float x1, float y1, float rad);
    bool checkCollisionWithBox(float x1, float y1, float dx, float dy);
    void draw(OledHelper &oled, bool fill = false);
    void update();
};

#endif