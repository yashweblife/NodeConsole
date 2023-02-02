#include <Arduino.h>
#include <Vector.h>
#include <Player.h>
#include <OledHelper.h>
#include <Ball.h>
#include <Box.h>

Player::Player(int x, int y)
{
    pos = Vector(x, y, 0);
}
void Player::setPos(float x, float y)
{
    pos.x = x;
    pos.y = y;
}
void Player::setVel(float x, float y)
{
    vel.x = x;
    vel.y = y;
}
void Player::setAcc(float x, float y)
{
    acc.x = x;
    acc.y = y;
}
void Player::addForce(float x, float y)
{
    acc.x += x;
    acc.y += y;
}
void Player::setImage() {}
void Player::bound(int x, int y, int dx, int dy)
{
    if (pos.x < x)
    {
        pos.x = x;
        vel.x = -vel.x;
    }
    if (pos.y < y)
    {
        pos.y = y;
        vel.y = -vel.y;
    }
    if (pos.x + size.x > dx)
    {
        pos.x = pos.x + size.x > dx;
        vel.x = -vel.x;
    }
    if (pos.y + size.y > dy)
    {
        pos.y = pos.y + size.y > dy;
        vel.y = -vel.y;
    }
}
void Player::draw(OledHelper &oled) {}
void Player::update()
{
    vel.add(acc);
    pos.add(vel);
}
float Player::distance(Vector v)
{
}
bool Player::checkCollisionWithBall(Ball &b)
{
    if (pos.distance(b.pos) < radius + b.radius)
    {
        return (true);
    }
    return (false);
}
bool Player::checkCollisionWithBox(Box &b)
{
    if (pos.x < b.pos.x + b.size.x && pos.x + size.x > b.pos.x && pos.y < b.pos.y + b.pos.y && pos.y + size.y > b.pos.y)
    {
        return (true);
    }
    return (false);
}