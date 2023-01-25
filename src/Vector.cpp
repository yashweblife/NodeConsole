#include <Arduino.h>
#include <Vector.h>

Vector::Vector()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector::getMag()
{
    return (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

void Vector::add(Vector v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}

void Vector::sub(Vector v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vector::scalar(float num)
{
    x *= num;
    y *= num;
    z *= num;
}

void Vector::normalize()
{
    const float mag = getMag();
    x /= mag;
    y /= mag;
    z /= mag;
}

float Vector::distance(Vector vec)
{
    return (sqrt(pow(x - vec.x, 2) + pow(y - vec.y, 2) + pow(z - vec.z, 2)));
}

void Vector::setMag(float val)
{
    normalize();
    scalar(val);
}

void Vector::rotateX(float val)
{
    float _y = y * cos(val) - z * sin(val);
    float _z = y * sin(val) + z * cos(val);
    this->y = _y;
    this->z = _z;
}

void Vector::rotateY(float val)
{
    float _x = x * cos(val) + z * sin(val);
    float _z = x * sin(val) - z * cos(val);
    this->x = _x;
    this->z = _z;
}

void Vector::rotateZ(float val)
{
    float _x = x * cos(val) - y * sin(val);
    float _y = x * sin(val) + y * cos(val);
    this->x = _x;
    this->y = _y;
}

float Vector::distanceV1(float x1, float y1)
{
    return (sqrt(pow(x - x1, 2) + pow(y - y1, 2)));
}