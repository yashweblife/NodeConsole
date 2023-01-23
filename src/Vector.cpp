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

/**
 * @brief get magnitude of vector
 */
float Vector::getMag()
{
    return (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

/**
 * @brief Add vectors together
 *
 * @param v vector
 */
void Vector::add(Vector v)
{
    x += v.x;
    y += v.y;
    z += v.z;
}
/**
 * @brief Subtract vectors
 *
 * @param v Vector
 */
void Vector::sub(Vector v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
}
/**
 * @brief Multiply a number to vector components
 *
 * @param num float
 */
void Vector::scalar(float num)
{
    x *= num;
    y *= num;
    z *= num;
}
/**
 * @brief Set the vector to its unit values
 *
 */
void Vector::normalize()
{
    const float mag = getMag();
    x /= mag;
    y /= mag;
    z /= mag;
}
/**
 * @brief Find distance between 2 vectors
 *
 * @param vec Vector
 * @return float
 */
float Vector::dist(Vector vec)
{
    return (sqrt(pow(x - vec.x, 2) + pow(y - vec.y, 2) + pow(z - vec.z, 2)));
}
/**
 * @brief Set the magnitude of the vector/ deirection stays the same
 *
 * @param val float
 */
void Vector::setMag(float val)
{
    normalize();
    scalar(val);
}
/**
 * @brief Rotate vector along x axis
 *
 * @param val float radians
 */
void Vector::rotateX(float val)
{
    float _y = y * cos(val) - z * sin(val);
    float _z = y * sin(val) + z * cos(val);
    this->y = _y;
    this->z = _z;
}
/**
 * @brief Rotate vector along y axis
 *
 * @param val float radians
 */
void Vector::rotateY(float val)
{
    float _x = x * cos(val) + z * sin(val);
    float _z = x * sin(val) - z * cos(val);
    this->x = _x;
    this->z = _z;
}
/**
 * @brief Rotate vector along x axis
 *
 * @param val float radians
 */
void Vector::rotateZ(float val)
{
    float _x = x * cos(val) - y * sin(val);
    float _y = x * sin(val) + y * cos(val);
    this->x = _x;
    this->y = _y;
}
