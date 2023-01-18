#include <Arduino.h>
#include <Ball.h>
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
void Ball::setSize(int x)
{
    size = x;
}
void Ball::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}
void Ball::setVel(int x, int y)
{
    vel.x = x;
    vel.y = y;
}
void Ball::setAcc(int x, int y)
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
    if (pos.x < x + size)
    {
        pos.x = x + size;
        reverseVel(true);
        return (1);
    }
    if (pos.y < y + size)
    {
        pos.y = y + size;
        reverseVel(false);
        return (2);
    }
    if (pos.x > dx - size)
    {
        pos.x = dx - size;
        reverseVel(true);
        return (3);
    }
    if (pos.y > dy - size)
    {
        pos.y = dy - size;
        reverseVel(false);
        return (4);
    }
    return (0);
}
bool Ball::checkCollisionWithBall(Ball b) {
    if(pos.dist(b.pos)<size+b.size){
        return(true);
    }
    return(false);
}
bool Ball::checkCollisionWithBox() {}
void Ball::draw(OledHelper *oled) {
    oled->circle(pos.x,pos.y,size);
}
void Ball::update() {
    vel.add(acc);
    pos.add(vel);
    acc.scalar(0);
}
