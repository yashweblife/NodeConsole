#ifndef Ball_h
#define Ball_h

#include <Arduino.h>
#include <Vector.h>
#include <OledHelper.h>
#include <Box.h>
class Ball
{
public:
    Vector pos;
    Vector vel;
    Vector acc;
    Vector size;
    float radius;
    /**
     * @brief Construct a new Ball object
     *
     */
    Ball();
    /**
     * @brief Construct a new Ball object
     *
     * @param start_x
     * @param start_y
     */
    Ball(int start_x, int start_y);
    /**
     * @brief Set the Size of the object
     *
     * @param val
     */
    void setSize(float val);
    /**
     * @brief Set the position of the object
     *
     * @param x
     * @param y
     */
    void setPos(float x, float y);
    /**
     * @brief Set the Vel of the object
     *
     * @param x
     * @param y
     */
    void setVel(float x, float y);
    /**
     * @brief Set the Acc of the object
     *
     * @param x
     * @param y
     */
    void setAcc(float x, float y);
    /**
     * @brief Reverse velocity of the object in  direction
     *
     * @param comp
     */
    void reverseVel(bool comp = false);
    /**
     * @brief bound the object within a box
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
     * @brief Check Box collision
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
     * @brief Draw the ball (Will not print)
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