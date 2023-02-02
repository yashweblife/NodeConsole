#ifndef Box_h
#define Box_h

#include <Arduino.h>
#include <Vector.h>
#include <OledHelper.h>
#include <Ball.h>
class Box
{
public:
    Vector pos;
    Vector vel;
    Vector acc;
    Vector size;
    float radius;
    /**
     * @brief Construct a new Box object
     *
     */
    Box();
    /**
     * @brief Construct a new Box object
     *
     * @param start_x
     * @param start_y
     */
    Box(int start_x, int start_y);
    /**
     * @brief Set the Size of the object
     *
     * @param x
     * @param y
     */
    void setSize(int x, int y);
    /**
     * @brief Set the Pos of the object
     *
     * @param x
     * @param y
     */
    void setPos(int x, int y);
    /**
     * @brief Set the Vel of the object
     *
     * @param x
     * @param y
     */
    void setVel(int x, int y);
    /**
     * @brief Set the Acc of the object
     *
     * @param x
     * @param y
     */
    void setAcc(int x, int y);
    /**
     * @brief Reverse velocity of the object in a direction
     *
     * @param comp
     */
    void reverseVel(bool comp = false);
    /**
     * @brief Bound object inside a box
     *
     * @param x
     * @param y
     * @param dx
     * @param dy
     * @return int
     */
    int bound(int x = 0, int y = 0, int dx = 128, int dy = 64);
    /**
     * @brief Check collision based on distance
     *
     * @param x1
     * @param y1
     * @param rad
     * @return true
     * @return false
     */
    bool checkCollisionWithBall(float x1, float y1, float rad);
    /**
     * @brief Check box collision
     *
     * @param x1
     * @param y1
     * @param dx
     * @param dy
     * @return true
     * @return false
     */
    bool checkCollisionWithBox(float x1, float y1, float dx, float dy);
    /**
     * @brief Draw the object
     *
     * @param oled
     * @param fill
     */
    void draw(OledHelper &oled, bool fill = false);
    /**
     * @brief Update the physics of the object
     *
     */
    void update();
};

#endif