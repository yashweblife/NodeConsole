#ifndef Pong_h
#define Pong_h

#include <Arduino.h>
#include <OledHelper.h>
#include <Box.h>
#include <Ball.h>
#include <Controller.h>
class Pong
{
public:
    bool game_mode;
    bool winner;
    Ball ball;
    Box player1;
    Box player2;
    Controller lhs;
    Controller rhs;
    void begin();
    void game( OledHelper &oled);
};

#endif