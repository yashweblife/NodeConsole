#include <Arduino.h>
#include <Pong.h>
#include <Ball.h>
#include <OledHelper.h>

Pong::Pong()
{
    b = Ball();
    b.setVel(1, 1);
}
void Pong::draw(OledHelper &oled)
{
    lhs.draw(oled);
    rhs.draw(oled);
    b.draw(oled);
}
void Pong::update(int p1_pos, int p2_pos)
{
    if (gameState == true)
    {
        b.update();
        lhs.setPos(0, p1_pos);
        rhs.setPos(128 - rhs.size.x, p2_pos);
        b.bound(0, 0, 128, 64);
        if (lhs.checkCollisionWithBall(b) || rhs.checkCollisionWithBall(b))
        {
            b.reverseVel(true);
        }
    }
}