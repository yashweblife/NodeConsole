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
    int padding_left;
    int padding_right;
    int padding_top;
    int padding_bottom;
    bool fill;
    bool underline;
    bool center_cut;
    Text(String data);
    int getWidth();
    int getHeight();
    void setScale(int s);
    void setPos(int x, int y);
    void setPadding(int val);
    void setValue(String data);
    void calculatePadding();
    void calculatePosition();
    void centerCut();
    void underline();
    void setBorderLeft(bool val);
    void setBorderRight(bool val);
    void setBorderTop(bool val);
    void setBorderBottom(bool val);
    void setBorder(bool val);
    void draw(OledHelper &oled);
};

#endif
