#ifndef Controller_h
#define Controller_h
#include <Arduino.h>
class Controller
{
public:
    Controller();
    Controller(int val);
    Controller(int val, int _min, int _max);
    int pin = 14;
    float minVal = 0;
    float maxVal = 1024;
    void setMin(float val);
    void setMax(float val);
    float getValue();
    void caliberateMin();
    void caliberateMax();
    float mapValue(float _min, float _max);
};
#endif