#ifndef Playere_h
#define Playere_h

#include <Arduino.h>
#include <Vector.h>
#include <OledHelper.h>
#include <Ball.h>
#include <Box.h>
class Player
{
public:
    Player(int x, int y);
    Vector pos;
    Vector vel;
    Vector acc;
    Vector size;
    Vector center;
    float radius;
    void setPos(float x, float y);
    void setVel(float x, float y);
    void setAcc(float x, float y);
    void addForce(float x, float y);
    void setImage();
    void bound(int x, int y, int dx, int dy);
    void draw(OledHelper &oled);
    void update();
    float distance(Vector v);
    bool checkCollisionWithBall(Ball &b);
    bool checkCollisionWithBox(Box &b);
};

#endif