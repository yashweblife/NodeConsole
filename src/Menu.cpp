#include <Arduino.h>
#include <Menu.h>

Menu::Menu(String val, int index)
{
    text = val;
    this->index = index;
}
