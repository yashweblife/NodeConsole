#ifndef Text_h
#define Text_h
#include <Arduino.h>
#include <Vector.h>
#include <OledHelper.h>

class Text
{
    public:
    String value;
    Vector pos;
    Vector size;
    int scale;
    int padding;
    bool border_left;
    bool border_top;
    bool border_right;
    bool border_bottom;
    Text(String data);
    int getWidth();
    int getHeight();
    void setScale(int s);
    void setPos(int x, int y);
    void setValue(String data);
    void calculatePadding();
    void calculatePosition();
    void centerCut();
    void underline();
    void setBorderLeft();
    void setBorderRight();
    void setBorderTop();
    void setBorderBottom();
    void setBorder();
    void draw(OledHelper &oled);
};

#endif
