#ifndef Playere_h
#define Playere_h

#include <Arduino.h>
#include <Vector.h>

class Player
{
public:
    Player();
    Vector pos;
    Vector vel;
    Vector acc;
};

#endif