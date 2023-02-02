#ifndef Menu_h
#define Menu_h
#include <Arduino.h>
class Menu
{
public:
    Menu(String val, int index);
    int index = 0;
    bool selected = false;
    String text = "";
};

#endif