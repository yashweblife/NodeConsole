#ifndef Vector_h
#define Vector_h
#include<Arduino.h>
class Vector
{
public:
    Vector();
    Vector(float x = 0, float y = 0);
    Vector(float x = 0, float y = 0, float z = 0);
    float x = 0;
    float y = 0;
    float z = 0;
    float getMag();
    void add(Vector vec);
    void sub(Vector vec);
    void scalar(float num);
    void normalize();
    void setMag(float num);
    void rotateX(float num);
    void rotateY(float num);
    void rotateZ(float num);
};
#endif