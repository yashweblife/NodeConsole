#include <Arduino.h>
#include <OledHelper.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

OledHelper::OledHelper() {}

bool OledHelper::setup_oled()
{
    d = Adafruit_SSD1306(128, 64, &Wire, -1);
    if (!d.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        return (false);
    }
    return (true);
}

void OledHelper::pix(int x, int y)
{
    d.drawPixel(x, y, SSD1306_WHITE);
}

void OledHelper::line(int x, int y, int x1, int y1)
{
    d.drawLine(x, y, x1, y1, SSD1306_WHITE);
}

void OledHelper::circle(int x, int y, int r, bool fill)
{
    if (fill)
    {
        d.fillCircle(x, y, r, SSD1306_WHITE);
    }
    else
    {
        d.drawCircle(x, y, r, SSD1306_WHITE);
    }
}

void OledHelper::rect(int x, int y, int w, int h, bool fill)
{
    if (fill)
    {
        d.fillRect(x, y, w, h, SSD1306_WHITE);
    }
    else
    {
        d.drawRect(x, y, w, h, SSD1306_WHITE);
    }
}

void OledHelper::text(String t, int x, int y, float s, bool fill)
{
    d.setTextSize(s); // Draw 2X-scale text
    if (fill == true)
    {
        d.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    }
    else
    {
        d.setTextColor(SSD1306_WHITE);
    }
    d.setCursor(x, y);
    d.println(t);
}

void OledHelper::show()
{
    d.display();
}

void OledHelper::clear()
{
    d.clearDisplay();
}
void OledHelper::dim(bool val)
{
    d.dim(val);
}
void OledHelper::rotate(int val){
    d.setRotation(val);
}