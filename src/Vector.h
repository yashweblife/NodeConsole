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
    /**
     * @brief Construct a new Vector object
     *
     * @param x
     * @param y
     * @param z
     */
    Vector(int x, int y, int z);
    /**
     * @brief Construct a new Vector object with floats
     *
     * @param x
     * @param y
     * @param z
     */
    Vector(float x, float y, float z);
    float x = 0;
    float y = 0;
    float z = 0;
    /**
     * @brief Get the magnitude of the vector
     *
     * @return float
     */
    float getMag();
    /**
     * @brief Add 2 vectors
     *
     * @param vec
     */
    void add(Vector vec);
    /**
     * @brief Subtract 2 vectors
     *
     * @param vec
     */
    void sub(Vector vec);
    /**
     * @brief Set vector to its unit vector
     *
     */
    void normalize();
    /**
     * @brief Scalar multiplication `Multiply number to vector components`
     *
     * @param num
     */
    void scalar(float num);
    /**
     * @brief Get distance between 2 vectors
     *
     * @param vec
     * @return float
     */
    float distance(Vector vec);
    /**
     * @brief Set the magnitude of vector
     *
     * @param num
     */
    void setMag(float num);
    /**
     * @brief Rotate vector along x axis
     *
     * @param num
     */
    void rotateX(float num);
    /**
     * @brief Rotate vector along y axis
     *
     * @param num
     */
    void rotateY(float num);
    /**
     * @brief Rotate vector along z axis
     *
     * @param num
     */
    void rotateZ(float num);
    /**
     * @brief Get distance with components as inputs
     *
     * @param x
     * @param y
     * @return float
     */
    float distanceV1(float x, float y);
};
#endif