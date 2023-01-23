#ifndef Vector_h
#define Vector_h
#include <Arduino.h>

/**
 * @brief Vector class to store position data 
 */
class Vector
{
public:
    Vector();
    Vector(int x, int y, int z);
    Vector(float x, float y, float z);
    float x = 0;
    float y = 0;
    float z = 0;
    float getMag();
    void add(Vector vec);
    void sub(Vector vec);
    void normalize();
    void scalar(float num);
    float dist(Vector vec);
    void setMag(float num);
    void rotateX(float num);
    void rotateY(float num);
    void rotateZ(float num);
};
#endif