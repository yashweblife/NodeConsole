#include <Arduino.h>
#include <Text.h>
#include <Vector.h>
#include <OledHelper.h>

Text::Text(String data)
{
    value = data;
}
int Text::getWidth() {}
int Text::getHeight() {}
void Text::setScale(int s) {}
void Text::setPos(int x, int y) {}
void Text::setValue(String data) {}
void Text::calculatePadding() {}
void Text::calculatePosition() {}
void Text::centerCut() {}
void Text::underline() {}
void Text::setBorderLeft() {}
void Text::setBorderRight() {}
void Text::setBorderTop() {}
void Text::setBorderBottom() {}
void Text::setBorder() {}
void Text::draw(OledHelper &oled) {}