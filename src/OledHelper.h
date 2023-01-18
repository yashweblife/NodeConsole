#ifndef OledHelper_h
#define OledHelper_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

class OledHelper
{
    public:
        OledHelper();
        bool setup_oled();
        void pix(int x=0,int y=0);
        void line(int x=0,int y=0,int x1=10,int y1=10);
        void circle(int x=0,int y=0,int r=10, bool fill=false);
        void rect(int x=0,int y=0, int w=10, int h=10, bool fill=false);
        void text(String t="",int x=0, int y=0, float s=1, bool fill=false);
        void show(void);
        void clear(void);
        void dim(bool val=true);
        void rotate(int val=2);
    private:
        Adafruit_SSD1306 d;
};

#endif