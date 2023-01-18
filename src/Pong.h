#ifndef Pong_h
#define Pong_h
#include <Arduino.h>
#include <Controller.h>
#include <Ball.h>
class Pong
{
public:
    Controller lhs;
    Controller rhs;
    Ball b;

    bool gameState = false;
    Pong();
    void draw();
    void update();
};

#endif