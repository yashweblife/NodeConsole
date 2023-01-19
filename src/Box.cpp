#include <Arduino.h>
#include <Box.h>
#include <Ball.h>
#include <OledHelper.h>
#include <Vector.h>

Box::Box()
{
    pos = Vector(64, 16, 0);
    vel = Vector(0, 0, 0);
    acc = Vector(0, 0, 0);
    size = Vector(10, 10, 0);
}
Box::Box(int size_x, int size_y)
{
    pos = Vector(64, 16, 0);
    vel = Vector(0, 0, 0);
    acc = Vector(0, 0, 0);
    size = Vector(size_x, size_y, 0);
}
void Box::setSize(int x, int y)
{
    size.x = x;
    size.y = y;
}
void Box::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}
void Box::setVel(int x, int y)
{
    vel.x = x;
    vel.y = y;
}
void Box::setAcc(int x, int y)
{
    acc.x = x;
    acc.y = y;
}
void Box::reverseVel(bool comp)
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
int Box::bound(int x, int y, int dx, int dy)
{
    if (pos.x < x)
    {
        pos.x = x;
        reverseVel(true);
        return (1);
    }
    if (pos.x > dx - size.x)
    {
        pos.x = dx - size.x;
        reverseVel(true);
        return (2);
    }
    if (pos.y < y)
    {
        pos.y = y;
        reverseVel();
        return (3);
    }
    if (pos.y > dy - size.y)
    {
        pos.y = dy - size.y;
        reverseVel();
        return (4);
    }
    return (0);
}
bool Box::checkCollisionWithBall(Ball b)
{
    if (b.pos.x - b.size < pos.x + size.x && b.pos.x + b.size > pos.x && b.pos.y - b.size < pos.y + size.y && b.pos.y + b.size > pos.y)
    {
        return (true);
    }
    return (false);
}
bool Box::checkCollisionWithBox(Box b) {}
void Box::draw(OledHelper &oled, bool fill)
{
    oled.rect(pos.x, pos.y, size.x, size.y, fill);
}
void Box::update() {}
