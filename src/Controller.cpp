#include <Arduino.h>
#include <Controller.h>

Controller::Controller() {}
Controller::Controller(int val)
{
    pin = val;
    pinMode(pin, OUTPUT);
}
Controller::Controller(int val, int _min, int _max)
{
    pin = val;
    pinMode(pin, OUTPUT);
    minVal = _min;
    maxVal = _max;
}
void Controller::setMin(float val)
{
    minVal = val;
}
void Controller::setMax(float val)
{
    maxVal = val;
}
float Controller::getValue()
{
    digitalWrite(pin, 1);
    float val = analogRead(A0);
    digitalWrite(pin, 0);
    return (val);
}
void Controller::caliberateMin()
{
    float val = 0;
    for (int i = 0; i < 100; i++)
    {
        val += getValue();
    }
    val /= 100;
    minVal = val;
}
void Controller::caliberateMax()
{
    float val = 0;
    for (int i = 0; i < 100; i++)
    {
        val += getValue();
    }
    val /= 100;
    maxVal = val;
}
float Controller::mapValue(float _min, float _max)
{
    return (map(getValue(), minVal, maxVal, _min, _max));
}