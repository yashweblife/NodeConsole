#ifndef Ball_h
#define Ball_h

#include <Arduino.h>
#include <Vector.h>
#include <OledHelper.h>
#include <Box.h>
class Ball
{
public:
    Vector pos;
    Vector vel;
    Vector acc;
    Vector size;
    float radius;
    Ball();
    Ball(int start_x, int start_y);
    void setSize(float val);
    void setPos(float x, float y);
    void setVel(float x, float y);
    void setAcc(float x, float y);
    void reverseVel(bool comp = false);
    int bound(int x = 0, int y = 0, int dx = 128, int dy = 64);
    bool checkCollisionWithBall(float x1, float y1, float rad);
    bool checkCollisionWithBox(float x1, float y1, float dx, float dy);
    void draw(OledHelper &oled, bool fill = false);
    void update();
};

#endif