#include <Arduino.h>
#include <Ball.h>
#include <Vector.h>
#include <OledHelper.h>

Ball::Ball() {}
Ball::Ball(int start_x, int start_y) {}
void Ball::setSize(int x) {}
void Ball::setPos(int x, int y) {}
void Ball::setVel(int x, int y) {}
void Ball::setAcc(int x, int y) {}
void Ball::reverseVel(bool comp) {}
void Ball::bound(int  x, int y, int dx, int  dy) {}
bool Ball::checkCollisionWithBall(Ball b) {}
bool Ball::checkCollisionWithBox() {}
void Ball::draw(OledHelper *oled) {}
void Ball::update() {}
