#include <Arduino.h>
#include <Ball.h>
#include <Box.h>
#include <Vector.h>
#include <OledHelper.h>

Ball::Ball()
{
    pos = Vector(64, 32, 0);
    vel = Vector(0, 0, 0);
    acc = Vector(0, 0, 0);
}
Ball::Ball(int start_x, int start_y)
{
    pos = Vector(start_x, start_y, 0);
    vel = Vector(0, 0, 0);
    acc = Vector(0, 0, 0);
}
void Ball::setSize(float x)
{
    radius = x;
    size.x = x / 2;
    size.y = x / 2;
}

void Ball::setPos(float x, float y)
{
    pos.x = x;
    pos.y = y;
}
void Ball::setVel(float x, float y)
{
    vel.x = x;
    vel.y = y;
}
void Ball::setAcc(float x, float y)
{
    acc.x = x;
    acc.y = y;
}
void Ball::reverseVel(bool comp)
{
    if (comp == true)
    {
        vel.x = -vel.x;
    }
    else
    {

        vel.y = -vel.y;
    }
}
int Ball::bound(int x, int y, int dx, int dy)
{
    if (pos.x < x + radius)
    {
        pos.x = x + radius;
        reverseVel(true);
        return (1);
    }
    if (pos.y < y + radius)
    {
        pos.y = y + radius;
        reverseVel(false);
        return (2);
    }
    if (pos.x > dx - radius)
    {
        pos.x = dx - radius;
        reverseVel(true);
        return (3);
    }
    if (pos.y > dy - radius)
    {
        pos.y = dy - radius;
        reverseVel(false);
        return (4);
    }
    return (0);
}
bool Ball::checkCollisionWithBall(float x1, float y1, float rad)
{
    if (pos.distanceV1(x1, y1) < radius + rad)
    {
        return (true);
    }
    return (false);
}
bool Ball::checkCollisionWithBox(float x1, float y1, float dx, float dy)
{
    return (false);
}
void Ball::draw(OledHelper &oled, bool fill)
{
    oled.circle(pos.x, pos.y, radius, fill);
}
void Ball::update()
{
    vel.add(acc);
    pos.add(vel);
    acc.scalar(0);
}
