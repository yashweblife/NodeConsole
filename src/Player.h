#ifndef Playere_h
#define Playere_h

#include <Arduino.h>
#include <Vector.h>
#include <OledHelper.h>
#include <Ball.h>
#include <Box.h>
class Player
{
public:
    /**
     * @brief Construct a new Player object with initial position
     * 
     * @param x 
     * @param y 
     */
    Player(int x, int y);
    Vector pos;
    Vector vel;
    Vector acc;
    Vector size;
    Vector center;
    float radius;
    /**
     * @brief Set the position
     * 
     * @param x 
     * @param y 
     */
    void setPos(float x, float y);
    /**
     * @brief Set the velocity
     * 
     * @param x 
     * @param y 
     */
    void setVel(float x, float y);
    /**
     * @brief Set the acceleration
     * 
     * @param x 
     * @param y 
     */
    void setAcc(float x, float y);
    /**
     * @brief add a force to the object
     * 
     * @param x 
     * @param y 
     */
    void addForce(float x, float y);
    /**
     * @brief Give the player an image
     * 
     */
    void setImage();
    /**
     * @brief Bound the Player to a rectangle
     * 
     * @param x 
     * @param y 
     * @param dx 
     * @param dy 
     */
    void bound(int x, int y, int dx, int dy);
    /**
     * @brief Draw the player
     * 
     * @param oled 
     */
    void draw(OledHelper &oled);
    /**
     * @brief Update players physics
     * 
     */
    void update();
    /**
     * @brief Get distance between Player and some vector
     * 
     * @param v 
     * @return float 
     */
    float distance(Vector v);
    /**
     * @brief Use distance to check collision
     * 
     * @param b 
     * @return true 
     * @return false 
     */
    bool checkCollisionWithBall(Ball &b);
    /**
     * @brief Use bounds to check collision (AABB)
     * 
     * @param b 
     * @return true 
     * @return false 
     */
    bool checkCollisionWithBox(Box &b);
};

#endif