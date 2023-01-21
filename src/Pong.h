#ifndef Pong_h
#define Pong_h

#include <Arduino.h>
#include <OledHelper.h>
#include <Box.h>
#include <Ball.h>
class Pong
{
public:
    Box lhs;
    Box rhs;
    Ball b;
    bool gameState = false;
    Pong();
    void draw(OledHelper &oled);
    void update(int p1_pos, int p2_pos);
};

#endif