#include<Arduino.h>
#include<Box.h>
#include<Ball.h>
#include<OledHelper.h>

Box::Box(){}
Box::Box(int size_x, int size_y){}
void Box::setSize(int x, int y){}
void Box::setPos(int x, int y){}
void Box::setVel(int x, int y){}
void Box::setAcc(int x, int y){}
void Box::reverseVel(bool comp){}
int Box::bound(int x, int y, int dx, int dy){}
bool Box::checkCollisionWithBall(Ball b){}
bool Box::checkCollisionWithBox(Box b){}
void Box::draw(OledHelper *oled){}
void Box::update(){}
