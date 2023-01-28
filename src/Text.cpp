#include <Arduino.h>
#include <Text.h>
#include <Vector.h>
#include <OledHelper.h>

Text::Text(String data)
{
    value = data;
    size = Vector(data.length() * 5 + 5, 8, 0);
    pos = Vector(0, 0, 0);
    scale = 1;
    padding = 0;
}
int Text::getWidth() {
    return(value.length() * 5 + 5);
}
int Text::getHeight() {
    return(8);
}
void Text::setScale(int s)
{
    scale = s;
}
void Text::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}
void Text::setValue(String data)
{
    value = data;
}
void Text::calculatePadding()
{
    size.x += padding;
    size.y += padding;
}
void Text::calculatePosition()
{
    pos.x += padding;
    pos.y += padding;
}
void Text::centerCut() {}
void Text::underline() {}
void Text::setBorderLeft() {}
void Text::setBorderRight() {}
void Text::setBorderTop() {}
void Text::setBorderBottom() {}
void Text::setBorder() {}
void Text::draw(OledHelper &oled)
{
    oled.text(value, pos.x+padding, pos.y+padding, scale, false);

    if(border_left==true){
        oled.line(pos.x,pos.y,pos.x,pos.y+size.y+(padding*2));
    }
    if(border_right==true){
        oled.line(pos.x+size.x+(padding*2),pos.y,pos.x+size.x+(padding*2),pos.y+size.y+(padding*2));
    }
    if(border_top==true){
        oled.line(pos.x, pos.y, pos.x+size.x+(padding*2), pos.y);
    }
    if(border_bottom==true){
        oled.line(pos.x, pos.y+size.y+(padding*2), pos.x+size.x+(padding*2), pos.y+size.y+(padding*2));
    }
}